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
   sched_setscheduler(0, atoi(argv[1]), &attr);
   // keep thread alive
   while(1){
     sleep(1);
   };
   return 0;
 }
