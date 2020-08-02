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
               u32 size;              /* Size of this structure */
               u32 sched_policy;      /* Policy (SCHED_*) */
               u64 sched_flags;       /* Flags */
               s32 sched_nice;        /* Nice value (SCHED_OTHER,
                                         SCHED_BATCH) */
               u32 sched_priority;    /* Static priority (SCHED_FIFO,
                                         SCHED_RR) */
               /* Remaining fields are for SCHED_DEADLINE */
               u64 sched_runtime;
               u64 sched_deadline;
               u64 sched_period;
           };

 int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
 {
    return syscall(__NR_sched_setattr, pid, attr, flags);
 }

 int main(int argc, char* argv[]) {

     struct sched_attr attr = {
         .size = sizeof(attr),
         .sched_policy = atoi(argv[1]),
         .sched_priority = atoi(argv[2])
     };

     pid_t tid = syscall(SYS_gettid);

     if (sched_setattr(tid, &attr, 0))
         perror("sched_setattr()");

     return 0;
 }
