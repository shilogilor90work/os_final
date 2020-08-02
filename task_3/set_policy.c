// #include <sys/types.h>
#include <sched.h>
#include <stdio.h>
// #include <sys/time.h>
// #include <sys/resource.h>

int main(int argc,char* argv[])
{
  int status;
  // if missing argument

    if(argc<3)
        printf("please enter the process id and priorty...\n");
    // if argument exists
    if(argc>=3)
    {
      struct sched_param sp;
      int policy = atoi(argv[1]);
      int pid = atoi(argv[2]);

      sched_setsched(policy, pid, &sp);
      // switch (argv[1])
      // ​{
      //     case DEADLINE_SCHED:
      //       // statements
      //       break;
      //
      //     case SCHED_OTHER:
      //       // statements
      //       break;
      //     case SCHED_RR:
      //       // statements
      //       break;
      //     case SCHED_IDLE:
      //       // statements
      //       break;
      //     case SCHED_FIFO:
      //       // statements
      //       break;
      //     default:
      //       // default statements
      //       printf("not vaild priorty value\n");
      // }
    }
    return 0;
}
