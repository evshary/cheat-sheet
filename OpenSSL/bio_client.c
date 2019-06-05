#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h> // openssl

#define RECV_SIZE 256
#define SSL_IP   "127.0.0.1"
#define SSL_PORT 8080

int main(int argc, char *argv[])
{
    int ret = -1;

    // SSL init
    printf("SSL init\n");
    SSL_library_init();

    // Create SSL_CTX
    printf("Create SSL_CTX\n");
    SSL_CTX *ctx;
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

    // Connect CTX with BIO
    printf("Connect CTX with BIO\n");
    BIO *bio;
    if ((bio = BIO_new_ssl_connect(ctx)) == NULL) {
        printf("BIO_new_ssl_connect error\n");
        goto exit;
    }
    // We can get fd,SSL if needed.
    // int fd = BIO_get_fd(bio, NULL);
    // SSL *ssl;
    // BIO_get_ssl(bio, & ssl);
    
    // Build TCP connection
    printf("Build TCP connection to server\n");
    char server[50];
    snprintf(server, sizeof(server), "%s:%d", SSL_IP, SSL_PORT);
    BIO_set_conn_hostname(bio, server);
    if (BIO_do_connect(bio) <= 0) {
        printf("BIO_do_connect error\n");
        goto exit;
    }
    
    // Establish SSL connection
    printf("Establish SSL connection\n");
    if (BIO_do_handshake(bio) <= 0) {
        printf("BIO_do_handshake error\n");
        goto exit;
    }

    // BIO write/read
    printf("BIO read/write\n");
    char buf[RECV_SIZE] = {0};
    char *msg = "client's msg";
    if (BIO_write(bio, msg, strlen(msg)) <= 0) {
        printf("BIO_write error\n");
        goto exit;
    }
    int len = BIO_read(bio, buf, sizeof(buf));
    if (len < 0) {
        printf("BIO_read error\n");
        goto exit;
    }
    printf("read len=%d, buf=%s\n", len, buf);

    ret = 0;
exit:
    // Free resource
    if (bio)
        BIO_free_all(bio);
    if (ctx)
        SSL_CTX_free(ctx);
    EVP_cleanup();
    return ret;
}