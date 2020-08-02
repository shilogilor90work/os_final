#include <sched.h>


int main(int argc,char* argv[])
{
  struct sched_param sp;
  sched_setsched(atoi(argv[1]), atoi(argv[2]), &sp);
  return 0;
}
