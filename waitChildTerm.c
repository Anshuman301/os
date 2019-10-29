#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
int i,status;
pid_t pid;
pid=fork();
if(pid < 0){
perror("process failure");
exit(-1);
}else if(pid>0){
wait(NULL);
printf("Even No.\n");
for(int i=0;i<=10;i+=2)
printf("%3d ",i);
printf("Parent Process ends\n");
}else if(pid==0){
printf("Odd no.");
for(int i=1;i<10;i+=2)
printf("%3d ",i);
printf("Child Process ends\n");
}
}
