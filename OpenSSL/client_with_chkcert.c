#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h> // openssl

#define SUPPORT_CHK_SVR_CERT 1 // Check the certificate of server
#define SUPPORT_CLIENT_CERT  1 // Support client certificate

#if SUPPORT_CLIENT_CERT
#define SSL_CERT "client.crt"
#define SSL_KEY  "client.key"   
#endif

#if SUPPORT_CHK_SVR_CERT
#define CA_CERT  "ca.crt"
#endif

#define RECV_SIZE 256
#define SSL_IP   "127.0.0.1"
#define SSL_PORT 8080

int main(int argc, char *argv[])
{
    int ret = -1;
    int fd = -1;
    SSL_CTX *ctx;
    SSL *ssl = NULL;

    // SSL init
    printf("SSL init\n");
    SSL_library_init();

    // Create SSL_CTX
    printf("Create SSL_CTX\n");
    if ((ctx = SSL_CTX_new(TLS_client_method())) == NULL) {
        printf("SSL_CTX_new error\n");
        goto exit;
    }
    // Support only TLSv1.2
    // Other options: SSL3_VERSION, TLS1_VERSION, TLS1_1_VERSION, TLS1_2_VERSION
    if (SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION) == 0) {
        printf("Setting TLS version error\n");
        goto exit;
    }

#if SUPPORT_CHK_SVR_CERT
    printf("Load CA certificate\n");
    if (!SSL_CTX_load_verify_locations(ctx, CA_CERT, NULL)) {
        printf("SSL_CTX_load_verify_locations error\n");
        goto exit;
    }
#endif /*SUPPORT_CHK_SVR_CERT*/

#if SUPPORT_CLIENT_CERT
    // Configure cert and key
    printf("Configure cert and key\n");
    SSL_CTX_set_ecdh_auto(ctx, 1); // Able to use ECDH
    // Load certificate file
    if (SSL_CTX_use_certificate_file(ctx, SSL_CERT, SSL_FILETYPE_PEM) <= 0) {
        printf("Load certificate file error\n");
        goto exit;
    }
    // Load private key file
    if (SSL_CTX_use_PrivateKey_file(ctx, SSL_KEY, SSL_FILETYPE_PEM) <= 0 ) {
        printf("Load private key file error\n");
        goto exit;
    }
#endif /*SUPPORT_CLIENT_CERT*/

    // Create socket
    printf("Create socket\n");
    // New socket
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
        goto exit;
    // TCP connect to server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SSL_PORT);
    addr.sin_addr.s_addr = inet_addr(SSL_IP);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("TCP connect error\n");
        goto exit;
    }

    // Start to build ssl connection
    printf("Start to build ssl connection\n");
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, fd);
    if (SSL_connect(ssl) <= 0) {
        printf("SSL_connect error\n");
        goto exit;
    }

#if SUPPORT_CHK_SVR_CERT
    // Check the certificate of server
    printf("Check the certificate of server\n");
    if (SSL_get_verify_result(ssl) != X509_V_OK) {
        printf("SSL_get_verify_result error\n");
        goto exit;
    }
    printf("Get the certificate info\n");
    X509 *cert = SSL_get_peer_certificate(ssl); // Try to get certificates
    if (cert) {
        char *str;
        X509_NAME *name = X509_get_subject_name(cert);
        char CN[256] = {0};
        printf("Certificate info:\n");
        str = X509_NAME_oneline(name, 0, 0);
        printf("Subject: %s\n", str);
        free(str);
        X509_NAME_get_text_by_NID(name, NID_commonName, CN, sizeof(CN));
        printf("Common Name: %s\n", CN);
        str = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", str);
        free(str);
        X509_free(cert);
        // Check common name
        if (strcmp(CN, SSL_IP) != 0) {
            printf("Common Name fail.\n");
            goto exit;
        }
    } else {
        printf("Unable to get server certificate\n");
    }
#endif /*SUPPORT_CHK_SVR_CERT*/

    // SSL write/read
    printf("SSL read/write\n");
    char buf[RECV_SIZE] = {0};
    char *msg = "client's msg";
    if (SSL_write(ssl, msg, strlen(msg)) < 0) {
        printf("SSL_write error\n");
        goto exit;
    }
    int len = SSL_read(ssl, buf, sizeof(buf));
    if (len < 0) {
        printf("SSL_read error\n");
        goto exit;
    }
    printf("read len=%d, buf=%s\n", len, buf);

    ret = 0;
exit:
    // SSL close
    if (ssl)
        SSL_shutdown(ssl);
    // Free resource
    if (ssl)
        SSL_free(ssl);
    if (fd > 0)
        close(fd);
    if (ctx)
        SSL_CTX_free(ctx);
    EVP_cleanup();
    return ret;
}