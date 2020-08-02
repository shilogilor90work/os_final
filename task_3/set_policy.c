#include <sched.h>



int main(int argc,char* argv[])
{
  int status;
  // if missing argument
    if(argc<3)
        printf("please enter the process id and priorty...\n");
    // if argument exists
    if(argc>=3)
    {
      sched_setscheduler( argv[2], argv[1], NULL)
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
