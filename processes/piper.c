#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"

int main()
{
    // fairly straightforward way (theres better more sensible ones)
    // file descriptor for pipe
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    //fd now describes ends of a pipe

    // didnt know this typedef was a thing
    pid_t p1 = fork();
    if (p1 < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (p1 == 0)
    {
        char *message = "hey from child 1";
        int message_size = 17;
        write(fd[1], message, message_size);
        close(fd[1]);
    }
    else
    {
        int p1_wait = wait(NULL);
        pid_t p2 = fork();
        if (p2 < 0)
        {
            fprintf(stderr, "fork failed");
            exit(1);
        }
        else if (p2 == 0)
        {
            char buf[17];
            read(fd[0], buf,17);
            fprintf(stdout, "Message received from %d is %s \n", p1_wait, buf);
            close(fd[0]);
        }
    }

    return 0;
}