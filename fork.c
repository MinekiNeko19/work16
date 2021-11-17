#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Parent PID %d prefork\n", getpid());

    int status,w,f1,f2;
    srand(time(NULL));
    int slec;
    f1 = fork();
    f2 = fork();

    // if (f1||f2) {
    //     printf("still the parent %d\n", getpid());
    //     f2 = fork();
    //     printf("parent %d\tchild1 %d\tchild2 %d\n", getpid(), f1, f2);

    // } else {
    //     printf("child %d parent %d\n", getpid(), getppid());
    // }
    printf("pid: %d\tppid: %d\n", getpid(), getppid());

    return 0;
}