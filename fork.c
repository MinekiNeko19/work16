#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Parent PID %d is running to catch its children!\n", getpid());

    int status,w;
    srand(time(NULL));
    int slec = 2+(rand()%4);
    int f1 = fork();
    int f2 = fork();
    // printf("Child PID %d and Child PID %d are sleep running!\n\n", f1, f2);

    // printf("seconds to sleep: %d\n",slec);
    if (f1 && f2) {
        if (f1) {
            printf("child PID %d is here!\n",f1);
        }
        if (f2){
            printf("child PID %d is here!\n",f2);
        }
    }
    else {
        printf("no grandchildren here...\n");
    }

    return 0;
}