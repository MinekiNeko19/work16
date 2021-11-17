#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Parent PID %d prefork\n", getpid());

    int status,w;
    srand(time(NULL));
    int slec;
    int f1 = fork();
    int f2 = fork();

    return 0;
}