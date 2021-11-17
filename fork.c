#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Parent PID %d is running to catch its children! (initial message)\n", getpid());

    int status,w;
    srand(time(NULL));
    int slec;
    int f1 = fork();
    int f2 = fork();
    // printf("Parent %d\tchild1 %d\t child2 %d\n",getpid(),f1,f2);

    if (f1 && f2) { // parent
        printf("Actually... parent PID %d will wait for a child to stop\n", getpid());
        w = wait(&status);
        printf("parent %d ended because child %d woke up from sleeping for %d seconds\n", getpid(), w, WEXITSTATUS(status));
        printf("parent ended\n");
    }
    else if (f1 || f2) { // child of the main parent only
        slec = 2+(rand())%4;
        printf("Child PID %d with parent %d will sleep for %d seconds\n", getpid(), getppid(), slec);
        sleep(slec);
        printf("Child PID %d has awoken\n", getpid());
        return slec;
    }

    return 0;
}