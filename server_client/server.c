#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void handler_sigint(int);
void handler_sigusr();
int global_counter = 0;

int main()
{
  // print process id
  pid_t pid = getpid();
  printf("pid: %d", pid);
  // attach handler for SIGINT and SIGUSR1
  signal(SIGINT,handler_sigint);
  signal(SIGUSR1,handler_sigusr);
  // to keep process alive
  while(1){};
  return(0);
}


void handler_sigint(int signum)
{
  ++global_counter;
    printf("SIGINT recieved from :\n", signum);
}
void handler_sigusr()
{
    printf("SIGUSER1 recieved, and restarting the counter\n");
    global_counter = 0;
}
