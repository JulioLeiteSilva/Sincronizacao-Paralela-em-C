#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

pthread_t thread_auxiliar;

void signal_handler(int signo) {
    if (signo == SIGUSR1) {
        printf("Thread auxiliar: Sinal SIGUSR1 recebido! Iniciando tarefa...\n");
        
        sleep(1);
        printf("Thread auxiliar: Tarefa concluída.\n");
    }
}

void* thread_func(void* arg) {
    printf("Thread auxiliar: Aguardando o sinal SIGUSR1 para iniciar.\n");

    signal(SIGUSR1, signal_handler);

    pause();
    return NULL;
}

int main() {
    pthread_create(&thread_auxiliar, NULL, thread_func, NULL);

    sleep(2);
    printf("Thread principal: Enviando sinal SIGUSR1 para a thread auxiliar.\n");

    pthread_kill(thread_auxiliar, SIGUSR1);

    pthread_join(thread_auxiliar, NULL);

    printf("Thread principal: Execução concluída.\n");
    return 0;
}
