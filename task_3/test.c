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
// SCHED_OTHER : 0
// SCHED_FIFO : 1
// SCHED_RR : 2
// SCHED_BATCH : 4
// SCHED_IDLE : 5
// SCHED_DEADLINE : 6
 // int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
 // {
 //    return syscall(__NR_sched_setattr, pid, attr, flags);
 // }

 int main(int argc, char* argv[]) {
   // print process id
   pid_t pid = getpid();
   printf("pid: %d\n", pid);

     struct sched_attr attr = {
         // .sched_policy = atoi(argv[1]),
         .sched_priority = atoi(argv[2])
     };

     // if (sched_setattr(pid, &attr, 0))
     //     perror("sched_setattr()");
     sched_setscheduler(0, atoi(argv[1]), &attr);
     while(1){};
     return 0;
 }
