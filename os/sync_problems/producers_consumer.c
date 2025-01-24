#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 10
#define P_NUM 2
#define C_NUM 14

struct buff {
    int buffer[SIZE];
    int i;
} buff;

sem_t* lock, *empty, *full;
struct buff* b;

int main();
void create_p();
void producer(int i);
void consumer(int i);
void wait_p();

void producer(int i) {
    do {
        sem_wait(empty);
        sem_wait(lock);
        int num = rand() % 100;

        b->buffer[b->i] = num;
        b->i += 1;

        printf("producer %d added %d to buffer\n", i, num);
        sleep(1);

        sem_post(lock);
        sem_post(full);
    } while(1);

    exit(0);
}

void consumer(int i) {
    do {
        sem_wait(full);
        sem_wait(lock);

        int num;
        b->i -= 1;
        num = b->buffer[b->i];
        b->buffer[b->i] = 0;

        printf("consumer %d took %d from buffer\n", i, num);
        sleep(1);

        sem_post(lock);
        sem_post(empty);
    } while(1);

    exit(0);
}

void create_p() {
    pid_t p;
    for (int i = 0; i < P_NUM; i ++) {
        p = fork();
        if (p < 0) {
            perror("fork");
        }
        if (p == 0) {
            srand(getpid() * time(NULL));
            producer(i + 1);
        } 
    }

    for (int i = 0; i < C_NUM; i++) {
        p = fork();
        if (p < 0) {
            perror("fork");
        }
        if (p == 0) {
            consumer(i + 1);
        }
    }
}

void wait_p() {
    for (int i = 0; i < P_NUM + C_NUM; i++) {
        if (wait(0) < 0) {
            perror("wait");
        }
    }
}

int main() {
    lock = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    full = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    empty = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    b = (struct buff*) mmap(NULL, sizeof(struct buff), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    sem_init(lock, 1, 1);
    sem_init(empty, 1, SIZE);
    sem_init(full, 1, 0);

    create_p();
    wait_p();

    b->i = 0;
    for (int i = 0; i < SIZE; i++) {
        b->buffer[i] = 0;
    }

    return 0;
}