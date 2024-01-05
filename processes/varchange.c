#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
    int x;
    x = 100;
    int rc = fork();
    if(rc < 0)
    {
        //fork failed
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if(rc == 0)
    {
        //changes x
        x = 120;
        fprintf(stdout, "The value of x in the child %d is %d \n", rc,  x);
    }
    else
    {
        //even if we wait, the child processes' change of x is not reflected in the parent.
        //shows it has an isolated environment
        //changes in x in child process dont show up in parent
        // int rc_wait = wait(NULL); 
        fprintf(stdout, "The value of x in the parent of %d is %d \n", rc, x);
    }
    return 0;
}