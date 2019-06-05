#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h> // openssl

#define SSL_CERT "server.crt"
#define SSL_KEY  "server.key"   

#define BUF_LEN  256
#define SSL_PORT "8080"

int main(int argc, char *argv[])
{
    int ret = -1;
    BIO *bio = NULL;
    BIO *abio = NULL;
    BIO *cbio = NULL;
    SSL_CTX *ctx = NULL;

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
    
    // Create BIO SSL for server
    printf("Create BIO SSL for server\n");
    if ((bio = BIO_new_ssl(ctx,0)) == NULL) {
        printf("BIO_new_ssl error\n");
        goto exit;
    }
    // We can get fd,SSL if needed.
    // int fd = BIO_get_fd(bio, NULL);
    // SSL *ssl;
    // BIO_get_ssl(bio, & ssl);
    
    // Accept connection
    printf("Accept connection\n");
    abio = BIO_new_accept(SSL_PORT);
    BIO_set_accept_bios(abio, bio);
    // First call BIO_do_accept to setup accept BIO
    if (BIO_do_accept(abio) <= 0) {
        printf("BIO_do_accept error (setup accept BIO)\n");
        goto exit;
    }
    // Second call BIO_do_accept to await an incoming connection
    if (BIO_do_accept(abio) <= 0) {
        printf("BIO_do_accept error (wait incoming connection)\n");
        goto exit;
    }
    cbio = BIO_pop(abio);
    
    // Do SSL handshake
    printf("Do SSL handshake\n");
    if(BIO_do_handshake(cbio) <= 0) {
        printf("BIO_do_handshake error\n");
        goto exit;
    }
    
    // BIO write/read
    printf("BIO read/write\n");
    char buf[BUF_LEN] = {0};
    char *msg = "server's msg";
    int len = BIO_read(cbio, buf, sizeof(buf));
    if (len < 0) {
        printf("BIO_read error\n");
        goto exit;
    }
    printf("read len=%d, buf=%s\n", len, buf);
    if (BIO_write(cbio, msg, strlen(msg)) <= 0) {
        printf("BIO_write error\n");
        goto exit;
    }

    ret = 0;
exit:
    // Close client
    if (cbio)
        BIO_free_all(cbio);
    // Close server and relase resource
	// The bio will be also freed while freeing abio
    if (abio)
        BIO_free_all(abio);
    if (ctx)
        SSL_CTX_free(ctx);
    EVP_cleanup();
    return ret;
}