#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>

#define PH_N 5

sem_t* forks[PH_N];
sem_t* table;

int main();
void create_p();
void wait_p();
void dude();

void dude(int i) {
    do {
        sem_wait(table);
        sem_wait(forks[i]);
        sem_wait(forks[(i + 1) % PH_N]);

        printf("Dude %d is eating spaghette\n", i + 1);

        sem_post(forks[(i + 1) % PH_N]);
        sem_post(forks[i]);
        sem_post(table);
        sleep(0);
    } while(1);

    exit(0);
}

void create_p() {
    pid_t p;
    for (int i = 0; i < PH_N; i++) {
        p = fork();
        if (p < 0) {
            perror("fork");
        }
        if (p == 0) {
            dude(i);
        }
    }
}

void wait_p() {
    for (int i = 0; i < PH_N; i++) {
        if (wait(0) < 0) {
            perror("wait");
        }
    }
}

int main() {
    for (int i = 0; i < PH_N; i++) {
        forks[i] = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        sem_init(forks[i], 1, 1);
    }

    table = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_init(table, 1, PH_N - 1);

    create_p();
    wait_p();

    sem_destroy(table);
    munmap(table, sizeof(sem_t));

    for (int i = 0; i < PH_N; i++) {
        sem_destroy(forks[i]);
        munmap(forks[i], sizeof(sem_t));
    }
}