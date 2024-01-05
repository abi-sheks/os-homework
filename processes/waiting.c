#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
    //simple enough, nothing happens on calling wait inside the child
    //as there is no child process to wait for
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(stdout, "child does stuff... \n");
        wait(NULL);
    }
    else
    {
        wait(NULL);
        fprintf(stdout, "...then parent \n");
    }
    return 0;
}