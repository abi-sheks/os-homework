#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"

int main()
{
    //mvp

    // only "What about now?" prints, if close() is called in child, reinforcing the fact that it holds its own environment
    // nothing prints if close() is called at top level, as these descriptors are passed to the child as well (from book)
    // placing close in the else block prints child message! this is because at the time environment is captured, descriptor was open
    // envision the creation of a child process as a "branch" of kinds. at the time of this branch, the environment is captured and sent to the child process. SUBSEQUENT CHANGES do NOT reflect (case 3).

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Some output printed! \n");
    }
    else
    {
        close(STDOUT_FILENO);
        printf("What about now? \n");
        // nothing
    }
    return 0;
}
