#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <locale.h>

#define READERS 5
#define WRITERS 10
pthread_mutex_t db;
pthread_mutex_t mutex;
int readcount = 0;


void read_data_base(void);
void use_data_base(void);
void think_up_data(void);
void write_on_data_base(void);


void leitor(){
    while(1){
        pthread_mutex_lock(&mutex);
        readcount++;
        if(readcount == 1){
            pthread_mutex_lock(&db);
        }
        pthread_mutex_unlock(&mutex);
        read_data_base();
        pthread_mutex_lock(&mutex);
        readcount--;
        if(readcount == 0){
            pthread_mutex_unlock(&db);
        }
        pthread_mutex_unlock(&mutex);
        use_data_base();
    }
}

void escritor(){
    while(1){
        think_up_data();
        pthread_mutex_lock(&db);
        write_on_data_base();
        pthread_mutex_unlock(&db);
    }
}

void read_data_base(){
    setlocale(LC_ALL, "Portuguese");

    int read_time = rand() % 5;

    printf("Leitor %d está lendo o banco de dados. Total de %d leitores LENDO agora.\n", pthread_self(), readcount);
    sleep(read_time);
} 

void use_data_base(){
    setlocale(LC_ALL, "Portuguese");

    int use_time = rand() % 5;

    printf("Leitor utilizando conhecimento adquirido. Total de %d leitores LENDO agora.\n", readcount);
    sleep(use_time);
}

void think_up_data(){
    setlocale(LC_ALL, "Portuguese");

    int think_time = rand() % 10;

    printf("Escritor %d está pensando em novos dados para escrever.\n", pthread_self());
    sleep(think_time);
}

void write_on_data_base(){
    setlocale(LC_ALL, "Portuguese");

    int write_time = rand() % 10;

    printf("Escritor %d está escrevendo no banco de dados.\n", pthread_self());
    sleep(write_time);
}

int main(){
    pthread_t readers[READERS], writers[WRITERS];
    pthread_mutex_init(&db, NULL);
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < READERS; i++){
        pthread_create(&readers[i], NULL, (void *) leitor, NULL);
    }

    for(int i = 0; i < WRITERS; i++){
        pthread_create(&writers[i], NULL, (void *) escritor, NULL);
    }

    for(int i = 0; i < READERS; i++){
        pthread_join(readers[i], NULL);
    }

    for(int i = 0; i < WRITERS; i++){
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&db);
    pthread_mutex_destroy(&mutex);

    return 0;
}