#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    pid_t pid = fork();
    if (pid < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // we are child

    }
    else { // we are parent

    }
    return 0;
}
