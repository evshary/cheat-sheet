#include <stdio.h>
#include <string.h>
#include <sys/errno.h> // errno
#include <sys/msg.h>   // message queue

#define FTOK_ID  999
#define BUF_LEN  1024
#define RECV_MSG_TYPE 100
#define SEND_MSG_TYPE 120

struct msg_data {
    long type;
    char buf[128];
};

int main() {
    int ret = -1;

    // Get IPC ID
    printf("Get IPC ID\n");
    key_t key;
    key = ftok(".", FTOK_ID);
    if (key == -1) {
        printf("Get IPC ID fail\n");
        goto exit;
    }

    // Create message queue
    printf("Create message queue\n");
    int msqid = msgget(key, IPC_CREAT);
    if (msqid == -1) {
        printf("msqid error errno=%d\n", errno);
        goto exit;
    }

    // Recv and send data
    struct msg_data msg;
    while (1) {
        // Recv message queue data
        printf("Recv message queue data\n");
        if (msgrcv(msqid, &msg, sizeof(msg), RECV_MSG_TYPE, 0) <= 0) { // block and wait
            printf("msgrcv error\n");
            goto exit;
        }
        printf("Recv: type=%ld buf=%s\n", msg.type, msg.buf);
        // Send message queue data back
        msg.type = SEND_MSG_TYPE;
        strcpy(msg.buf, "Server Recieved.");
        printf("Send message queue data back\n");
        if (msgsnd(msqid, &msg, sizeof(msg), 0) < 0) {
            printf("msgsnd error\n");
            goto exit;
        }
    }
    
    ret = 0;
exit:
    return ret;
}