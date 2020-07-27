//
// #define WARNING_SIGNAL 0
//
// int main(int argc, char** argv)
// {
//   if (argc ==1) {
//     print("please enter the process id");
//   }
//   else {
//     int sig =0;
//     kill(atoi(argv[1]), WARNING_SIGNAL)
//   }
//     return 0;
// }

#include <errno.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
  int status;
    if(argc==1)
        printf("please enter the process id\n");
    if(argc>=2)
    {
      status = kill(atoi(argv[1]), 0);
      if (status != 0){
        if (errno == EPERM) {
           printf("Process %d exists but we have no permission.", atoi(argv[1]));
        }
        else if (errno == ESRCH) {
          printf("Process %d does not exist", atoi(argv[1]));

        }
      } else {
        printf("Process %d exists.", atoi(argv[1]));
      }
    }
    return 0;
}
