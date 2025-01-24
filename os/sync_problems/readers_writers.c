#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <unistd.h> 
#include <signal.h>
#include <sys/types.h>

#define R_NUM 15
#define W_NUM 5

sem_t *lock, *wrt;
int *r_cnt;
pid_t* pids;

void sigint_handler(int sig);
void reader(int i);
void writer(int i);
void create_processes();
void wait_p();
int main();

void sigint_handler(int sig) {
    for (int i = 0; i < R_NUM + W_NUM; i++) {
        kill(pids[i], 9);
    }
    wait_p();

    sem_destroy(lock);
    sem_destroy(wrt);

    munmap(pids, sizeof(pid_t) * (R_NUM + W_NUM));
    munmap(r_cnt, sizeof(int));
    munmap(lock, sizeof(sem_t));
    munmap(wrt, sizeof(sem_t));
    exit(0);
}

void reader(int i) {
    do {
        sem_wait(lock);
        *r_cnt += 1;
        if (*r_cnt == 1) {
            sem_wait(wrt);
        }
        sem_post(lock);

        printf("reader %d is reading\n", i);

        sem_wait(lock);
        *r_cnt -= 1;
        if (*r_cnt == 0) {
            sem_post(wrt);
        }
        sem_post(lock);
        sleep(1);
    } while(1);
    exit(0);
}

void writer(int i) {
    do {
        sem_wait(wrt);
        printf("writer %d is writing\n", i);
        sem_post(wrt);
        sleep(1);
    } while(1);

    exit(0);
}

void create_processes() {
    pid_t p;
    int j = 0;
    for (int i = 0; i < R_NUM; i++) {
        p = fork();
        if (p < 0) {
            perror("fork");
            exit(1);
        }
        if (p == 0) {
            pids[j] = p;
            j += 1;
            reader(i + 1);
        }
    }

    for (int i = 0; i < W_NUM; i++) {
        p = fork();
        if (p < 0) {
            perror("fork");
        }
        if (p == 0) {
            pids[j] = p;
            j += 1;
            writer(i + 1);
        }
    }
}

void wait_p() {
    for (int i = 0; i < R_NUM + W_NUM; i++) {
        if (wait(0) < 0) {
            perror("wait");
        }
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    r_cnt = (int*) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    lock = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    wrt = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pids = (pid_t*) mmap(NULL, sizeof(pid_t) * (R_NUM + W_NUM), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *r_cnt = 0;

    sem_init(lock, 1, 1);
    sem_init(wrt, 1, 1);

    create_processes();
    wait_p();

    sem_destroy(lock);
    sem_destroy(wrt);

    munmap(pids, sizeof(pid_t) * (R_NUM, W_NUM));
    munmap(r_cnt, sizeof(int));
    munmap(lock, sizeof(sem_t));
    munmap(wrt, sizeof(sem_t));
}