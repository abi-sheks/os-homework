#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"

int main()
{
    int descriptor = open("newfile.txt", O_CREAT | O_WRONLY | O_TRUNC);
    fprintf(stdout, "The file descriptor in the parent is %d \n", descriptor);
    int rc = fork();

    // the descriptor remains the same across fork() calls by design
    // think redirection in a shell, file descriptors cant change for stuff like echo "This" > new.txt
    // context info should be retained for "This" to be written to new.txt instead of stdout
    // concurrent writes causes an error always
    if(rc < 0)
    {
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if(rc == 0)
    {
        int res = write(descriptor, "child wrote this", 17);
        if(res == -1)
        {
            fprintf(stdout, "Write error in child");
        }
        fprintf(stdout, "The descriptor in the child %d is %d \n", rc, descriptor);
    }
    else {
       int res = write(descriptor, "parent wrote this", 18);
       fprintf(stdout, "Write error in parent");
    }
    return 0;
}