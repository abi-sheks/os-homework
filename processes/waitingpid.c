#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
    //nothing special
    //cant hijack the parent from the child, as wait and waitpid operate exclusively on children.
    int rc = fork();
    int parent_id = getpid(); 
    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(stdout, "child does stuff... \n");
        //does fuck all
        waitpid(parent_id, NULL, 0);
    }
    else
    {
        int rc_wait = waitpid(rc, NULL, 0);
        fprintf(stdout, "...then parent \n");
    }
    return 0;
}