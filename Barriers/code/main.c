#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_mutex_t barrier_mutex;
pthread_cond_t barrier_cond;
int barrier_count = 0;

void barrier() {
    pthread_mutex_lock(&barrier_mutex);
    barrier_count++;

    if (barrier_count == NUM_THREADS) {
        barrier_count = 0;
        pthread_cond_broadcast(&barrier_cond);
    } else {
        pthread_cond_wait(&barrier_cond, &barrier_mutex);
    }

    pthread_mutex_unlock(&barrier_mutex);
}

void* thread_work(void* arg) {
    int id = *((int*) arg);

    printf("Thread %d: Fase 1 - Executando tarefa inicial\n", id);

    sleep(1);

    printf("Thread %d: Aguardando na barreira\n", id);
    barrier();

    printf("Thread %d: Passou pela barreira e iniciando Fase 2\n", id);

    sleep(1);

    printf("Thread %d: Fase 2 concluída\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&barrier_mutex, NULL);
    pthread_cond_init(&barrier_cond, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_work, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&barrier_mutex);
    pthread_cond_destroy(&barrier_cond);

    printf("Todas as threads concluíram a execução.\n");
    return 0;
}
