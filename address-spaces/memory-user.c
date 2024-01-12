#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"
typedef long long ll;

int main(int argc, char **argv)
{
    // command-line arguments -->  1. space to be allocated in MB
    //                            2. time to execute for

    //memory usage increases accordingly when checked with free.
    //observation -> memory is not used unless array elements are actually streamed in some way.

    ll arr_len = 1000 * 1000 * atoi(argv[1]) * sizeof(char);
    time_t start, runtime, end;
    start = time(NULL);
    runtime = atoi(argv[2]);
    end = start + runtime;
    char *arr;
    arr = (char *)malloc(arr_len);

    if (arr == NULL)
    {
        fprintf(stderr, "ERROR : could not allocate");
        exit(1);
    }

    fprintf(stdout, "Running process %d... \n", getpid());
    fprintf(stdout, "Terminate with CTRL+C \n");
    char a;
    while (start < end)
    {
        for (ll i = 0; i < arr_len; i++)
        {
            arr[i] = i;
        }
        start = time(NULL);
    }
    return 0;
}
