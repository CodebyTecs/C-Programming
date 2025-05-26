#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_MSG_LEN 128
#define MAX_QUEUE_SIZE 10

typedef struct {
    char messages[MAX_QUEUE_SIZE][MAX_MSG_LEN + 1];
    int front, rear;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} MessageQueue;

typedef struct {
    char name[32];
    MessageQueue *queue;
} ThreadData;

void queueInit(MessageQueue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->not_full, NULL);
    pthread_cond_init(&q->not_empty, NULL);
}

void queueDestroy(MessageQueue *q) {
    pthread_mutex_destroy(&q->mutex);
    pthread_cond_destroy(&q->not_full);
    pthread_cond_destroy(&q->not_empty);
}

int msgSend(MessageQueue *q, const char *msg) {
    pthread_mutex_lock(&q->mutex);
    
    while (q->count >= MAX_QUEUE_SIZE) {
        pthread_cond_wait(&q->not_full, &q->mutex);
    }
    
    int len = strlen(msg);
    if (len > MAX_MSG_LEN) {
        len = MAX_MSG_LEN;
    }
    
    strncpy(q->messages[q->rear], msg, len);
    q->messages[q->rear][len] = '\0';
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->count++;
    
    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->mutex);
    
    return len;
}

int msgRecv(MessageQueue *q, char *buf, size_t bufsize) {
    pthread_mutex_lock(&q->mutex);
    
    while (q->count <= 0) {
        pthread_cond_wait(&q->not_empty, &q->mutex);
    }
    
    int len = strlen(q->messages[q->front]);
    if (len > bufsize - 1) {
        len = bufsize - 1;
    }
    
    strncpy(buf, q->messages[q->front], len);
    buf[len] = '\0';
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    
    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->mutex);
    
    return len;
}

void *clientThread(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    MessageQueue *queue = data->queue;
    const char *name = data->name;
    
    srand(time(NULL) + (unsigned long)pthread_self());
    
    while (1) {
        char msg[MAX_MSG_LEN + 1];
        int msg_len = snprintf(msg, sizeof(msg), "Hello from %s", name);
        
        int sent = msgSend(queue, msg);
        printf("Client %s sent %d bytes\n", name, sent);
        
        usleep(rand() % 1000000 + 1000000); 
    }
    
    return NULL;
}

void *serverThread(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    MessageQueue *queue = data->queue;
    const char *name = data->name;
    
    srand(time(NULL) + (unsigned long)pthread_self());
    
    while (1) {
        char buf[MAX_MSG_LEN + 1];
        int received = msgRecv(queue, buf, sizeof(buf));
        
        printf("[%s] %s\n", name, buf);
        
        usleep(rand() % 1000000 + 1000000); 
    }
    
    return NULL;
}

int main() {
    MessageQueue queue;
    queueInit(&queue);
    
    const int num_clients = 2;
    const int num_servers = 2;
    
    pthread_t clients[num_clients];
    pthread_t servers[num_servers];
    
    ThreadData client_data[num_clients];
    ThreadData server_data[num_servers];
    
    for (int i = 0; i < num_clients; i++) {
        snprintf(client_data[i].name, sizeof(client_data[i].name), "Client%d", i+1);
        client_data[i].queue = &queue;
        pthread_create(&clients[i], NULL, clientThread, &client_data[i]);
    }
    
    for (int i = 0; i < num_servers; i++) {
        snprintf(server_data[i].name, sizeof(server_data[i].name), "Server%d", i+1);
        server_data[i].queue = &queue;
        pthread_create(&servers[i], NULL, serverThread, &server_data[i]);
    }
    
    for (int i = 0; i < num_clients; i++) {
        pthread_join(clients[i], NULL);
    }
    
    for (int i = 0; i < num_servers; i++) {
        pthread_join(servers[i], NULL);
    }
    
    queueDestroy(&queue);
    
    return 0;
}