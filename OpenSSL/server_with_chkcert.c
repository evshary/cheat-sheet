#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h> // openssl

#define SUPPORT_CLIENT_CERT       1  // Support client certificate
#define SUPPORT_NO_CHK_VALID_CERT 1  // Don't check the validity of the certificate

#if SUPPORT_CLIENT_CERT
#define CA_CERT  "ca.crt"
#define MAX_VERIFY_LEN 10
#endif

#define SSL_CERT "server.crt"
#define SSL_KEY  "server.key"   

#define BUF_LEN  256
#define SSL_PORT 8080

#if SUPPORT_NO_CHK_VALID_CERT
/* The validity of certificate will be in preverify_ok. However we can do our check in the callback. 
 * Return value 1 means pass, and 0 means fail.
 */
static int verify_callback(int preverify_ok, X509_STORE_CTX *ctx) {
    printf("The validity of origin certificate? %d\n", preverify_ok);
    return 1;
}
#endif /*SUPPORT_NO_CHK_VALID_CERT*/

int main(int argc, char *argv[])
{
    int ret = -1;
    SSL_CTX *ctx = NULL;
    int server_fd = -1;
    int client_fd = -1;
    SSL *ssl = NULL;

    // SSL init
    printf("SSL init\n");
    SSL_library_init();

    // Create SSL_CTX
    printf("Create SSL_CTX\n");
    if ((ctx = SSL_CTX_new(TLS_server_method())) == NULL) {
        printf("SSL_CTX_new error\n");
        goto exit;
    }
    // Support only TLSv1.2
    // Other options: SSL3_VERSION, TLS1_VERSION, TLS1_1_VERSION, TLS1_2_VERSION
    if (SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION) == 0) {
        printf("Setting TLS version error\n");
        goto exit;
    }

#if SUPPORT_CLIENT_CERT
    printf("Load CA certificate\n");
    if (!SSL_CTX_load_verify_locations(ctx, CA_CERT, NULL)) {
        printf("SSL_CTX_load_verify_locations error\n");
        goto exit;
    }
    
    printf("SSL_CTX_set_verify: Verify client certificate\n");
#if SUPPORT_NO_CHK_VALID_CERT
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER|SSL_VERIFY_FAIL_IF_NO_PEER_CERT, verify_callback);
#else
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER|SSL_VERIFY_FAIL_IF_NO_PEER_CERT, NULL);
#endif /*SUPPORT_NO_CHK_VALID_CERT*/
    SSL_CTX_set_verify_depth(ctx, MAX_VERIFY_LEN + 1);
    { /* We need to call SSL_CTX_set_session_id_context since client certificate is reused. */
      /* According to https://www.openssl.org/docs/man1.1.0/man3/SSL_CTX_set_session_id_context.html
         If the session id context is not set on an SSL/TLS server and client certificates are used, 
         stored sessions will not be reused but a fatal error will be flagged and the handshake will
         fail.
       */
        static int server_session_id_context = 1;
        SSL_CTX_set_session_id_context(ctx, (void *)&server_session_id_context, sizeof(server_session_id_context));
    }
#endif /*SUPPORT_CLIENT_CERT*/

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
    // Check private key
    if (SSL_CTX_check_private_key(ctx) <= 0) {
        printf("Error private key\n");
        goto exit;
    }

    // Create socket
    printf("Create socket\n");
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
        goto exit;
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SSL_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        goto exit;
    if (listen(server_fd, 1) < 0)
        goto exit;

    // Accept connection
    printf("Accept connection\n");
    struct sockaddr_in client_addr;
    unsigned int len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len)) < 0)
        goto exit;

    // Build SSL connection
    printf("Build SSL connection\n");
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client_fd);
    if (SSL_accept(ssl) <= 0) {
        printf("SSL_accept error\n");
        goto exit;
    }

#if SUPPORT_CLIENT_CERT
    // Get the certificate info
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
        printf("Check client certificate\n");
        if (SSL_get_verify_result(ssl) != X509_V_OK) {
            printf("SSL_get_verify_result error\n");
            goto exit;
        }
    } else {
        printf("Unable to get client certificate\n");
    }
#endif /*SUPPORT_CLIENT_CERT*/

    // SSL read/write
    printf("SSL read/write\n");
    char buf[BUF_LEN] = {0};
    char *msg = "server's msg";
    len = SSL_read(ssl, buf, sizeof(buf));
    if (len < 0) {
        printf("SSL_read error\n");
        goto exit;
    }
    printf("read len=%d, buf=%s\n", len, buf);
    if (SSL_write(ssl, msg, strlen(msg)) < 0) {
        printf("SSL_write error\n");
        goto exit;
    }

    ret = 0;
exit:
    // Close client
    if (ssl)
        SSL_free(ssl);
    if (client_fd > 0)
        close(client_fd);
    // Close server and relase resource
    if (server_fd > 0)
        close(server_fd);
    if (ctx)
        SSL_CTX_free(ctx);
    EVP_cleanup();
    return ret;
}