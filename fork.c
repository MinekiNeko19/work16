#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Parent PID %d is running to catch its children!\n", getpid());

    int status,w;
    srand(time(NULL));
    int slec;
    int f1 = fork();
    int f2 = fork();
    // printf("Parent %d\tchild1 %d\t child2 %d\n",getpid(),f1,f2);

    if (f1 && f2) { // parent
        printf("Actually... parent PID %d will wait for a child to stop\n", getpid());
        w = wait(&status);
        printf("parent %d ended because a child ended\n", getpid());
    }
    else if (f1 || f2) { // child of the main parent only
        slec = 2+(rand())%4;
        printf("Child PID %d with parent %d is sleep running for %d seconds now\n", getpid(), getppid(), slec);
        sleep(slec);
    }

    return 0;
}