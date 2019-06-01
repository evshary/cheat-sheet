#include <stdio.h>
#include <string.h>
#include <sys/errno.h> // errno
#include <sys/msg.h>   // message queue

#define FTOK_ID  999
#define BUF_LEN  1024
#define RECV_MSG_TYPE  0
#define SEND_MSG_TYPE1 110
#define SEND_MSG_TYPE2 100

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

    // Send and receive
    struct msg_data msg;
    // Send message queue data1 (This won't be received by server, since type is different)
    printf("Send message queue data1\n");
    msg.type = SEND_MSG_TYPE1;
    strcpy(msg.buf, "Client Data1.");
    if (msgsnd(msqid, &msg, sizeof(msg), 0) < 0) {
        printf("msgsnd error\n");
        goto exit;
    }

    // Send message queue data2 (This will be received by server)
    printf("Send message queue data2\n");
    msg.type = SEND_MSG_TYPE2;
    strcpy(msg.buf, "Client Data2.");
    if (msgsnd(msqid, &msg, sizeof(msg), 0) < 0) {
        printf("msgsnd error\n");
        goto exit;
    }

    // Recv message queue data
    printf("Recv message queue data\n");
    if (msgrcv(msqid, &msg, sizeof(msg), RECV_MSG_TYPE, 0) <= 0) {
        printf("msgrcv error\n");
        goto exit;
    }
    
    ret = 0;
exit:
    return ret;
}