// imports
#include <stdio.h>
#include <sched.h>
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
