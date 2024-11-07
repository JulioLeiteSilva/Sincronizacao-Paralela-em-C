#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void* thread_func1(void* arg) {
    printf("Thread 1: Tentando bloquear mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: mutex1 bloqueado.\n");

    sleep(1); 

    printf("Thread 1: Tentando bloquear mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: mutex2 bloqueado.\n");

    
    printf("Thread 1: Trabalhando com mutex1 e mutex2.\n");

    
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    printf("Thread 1: Liberou mutex1 e mutex2.\n");
    return NULL;
}

void* thread_func2(void* arg) {
    printf("Thread 2: Tentando bloquear mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: mutex2 bloqueado.\n");

    sleep(1); 

    printf("Thread 2: Tentando bloquear mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: mutex1 bloqueado.\n");

    
    printf("Thread 2: Trabalhando com mutex1 e mutex2.\n");

    
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    printf("Thread 2: Liberou mutex1 e mutex2.\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    
    pthread_create(&t1, NULL, thread_func1, NULL);
    pthread_create(&t2, NULL, thread_func2, NULL);

   
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

  
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    printf("Programa encerrado.\n");
    return 0;
}
