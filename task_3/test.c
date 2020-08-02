// https://stackoverflow.com/questions/50082317/is-sched-deadline-officially-supported-in-ubuntu-16-04

#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sched.h>
#include <linux/sched.h>
#include <sys/types.h>
// https://man7.org/linux/man-pages/man2/sched_setattr.2.html

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
