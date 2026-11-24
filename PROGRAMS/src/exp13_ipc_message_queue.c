/*
 * Experiment 13: Inter-Process Communication using Message Queue
 * Aim: Implement message queue communication using msgget(), msgsnd(), msgrcv().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;

    message.msg_type = 1;
    strcpy(message.msg_text, "Hello, message queue!");

    // Send message
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Data sent to message queue: %s\n", message.msg_text);

    // Receive message
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    printf("Message received: %s\n", message.msg_text);

    // Destroy message queue
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
