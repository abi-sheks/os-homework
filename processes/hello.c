#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
    // the given task can be accomplished easily using wait()
    // as for solving it without wait()
    // Without calling wait() is hard, and not really the main point. What you did -- learning about signals on your own -- is a good sign,
    // showing you will seek out deeper knowledge. Good for you!
    // Later, you'll be able to use a shared memory segment, and either condition variables or semaphores, to solve this problem.
    // - The author of this book, as seen on SO.
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(stdout, "hello \n");
        exit(0);
    }
    else
    {
        int rc_wait = wait(NULL);
        fprintf(stdout, "goodbye \n");
    }
    return 0;
}