
#include <stdio.h>
#include <sched.h>
 int main(int argc, char* argv[]) {
   // print process id
   pid_t pid = getpid();
   printf("pid: %d\n", pid);

     const struct sched_param attr = {
         .sched_priority = atoi(argv[2])
     };

     sched_setscheduler(0, atoi(argv[1]), &attr);
     while(1){
       sleep(1);
     };
     return 0;
 }
