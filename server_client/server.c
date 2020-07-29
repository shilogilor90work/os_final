#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void handler_function(int);
void handler_function2(int);
int global_counter = 0;

int main()
{
  pid_t pid = getpid();

 printf("pid: %d", pid);
    /*
     * attach handler for SIGINT
     */

    signal(SIGINT,handler_function);
    signal(SIGUSR1,handler_function2);

    while(1)
    {
        printf("Program executing (1s delay between updates)...\n");
        sleep(1);
    }

    return(0);
}


void handler_function(int signum)
{
  ++global_counter;
    printf(">>> Caught signal: %d; executing handler <<<\n", signum);
}
void handler_function2(int signum)
{
    printf(">>> counter: %d\n", global_counter);
}
