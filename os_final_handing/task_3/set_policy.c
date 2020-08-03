// imports
#include <stdio.h>
#include <sched.h>
#include <sys/types.h>
struct sched_attr {
    uint32_t size;

    uint32_t sched_policy;
    uint64_t sched_flags;

    /* SCHED_NORMAL, SCHED_BATCH */
    int32_t sched_nice;

    /* SCHED_FIFO, SCHED_RR */
    uint32_t sched_priority;

    /* SCHED_DEADLINE (nsec) */
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};
 int main(int argc, char* argv[]) {
   // print process id
   pid_t pid = getpid();
   printf("pid: %d\n", pid);
   // change priority on the struct
   const struct sched_param attr = {
       .sched_priority = atoi(argv[2])
   };
   // http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fs%2Fsched_setscheduler.html
   // change sched policy
   if (atoi(argv[1]) != 6)
   {
     sched_setscheduler(0, atoi(argv[1]), &attr);
   } else
   {
     struct sched_attr sched_attribute = {
         .sched_policy = atoi(argv[1]),
         .sched_priority = atoi(argv[2])
     };
     sched_setattr(0, sched_attribute, 0);
   }
   // keep thread alive
   while(1){
     sleep(1);
   };
   return 0;
 }
