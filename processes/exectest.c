#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        //on googling, found out reasons for so many frontends (all these functions wrap the syscall execve) is they are different ways 
        //to exec. even execve wraps around exec. the actual syscall exec is wrapped by these libc calls. 
        char *lsargs[3];
        lsargs[0] = strdup("/bin/ls");
        lsargs[1] = strdup(".");
        lsargs[2] = NULL;
        // executes file lsargs[0], with arguments lsargs[0] (arg0), lsargs[1] and a null pointer marks termination of these args
        fprintf(stdout, "using execlp \n");
        execlp(lsargs[0], lsargs[0], lsargs[1], NULL);
        fprintf(stdout, "using execl \n");
        execl(lsargs[0], lsargs[0], lsargs[1], NULL);
        // e - specifies environment. useful in building pipe operations. (environment is passed down)
        // no environment here, so just a NULL pointer is passed
        // execvpe not available in this system
        fprintf(stdout, "using execvpe \n");
        fprintf(stdout, "using execle \n");
        execle(lsargs[0], lsargs[0], lsargs[1], NULL, NULL);
        // executes lsargs[0] with args lsargs
        fprintf(stdout, "using execv \n");
        execv(lsargs[0], lsargs);
        fprintf(stdout, "using execvp \n");
        execvp(lsargs[0], lsargs);

        //on error on all
        fprintf(stderr, "shouldn't print");
        exit(1);
    }
    else
    {
        // nothing
    }
    return 0;
}