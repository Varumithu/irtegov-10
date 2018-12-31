#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("need arguments\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();

    if (pid < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // we are child
        if (execvp(argv[1], argv + 1) == -1) {
            perror("exec");
        }
    }
    else { // we are parent
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("child process exited with status = %d", WEXITSTATUS(status));
        }
    }
    return 0;
}
