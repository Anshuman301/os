#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
pid_t pid;
pid=fork();
if(pid < 0 ){
	perror("Process Creation failed");
	exit(-1);
}else if(pid >0){
	printf("root node created\n");
	printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
	sleep(5);
}else if(pid==0){
	pid_t pid1=fork();
	if(pid1 < 0){
		perror("Child of child1 is not created\n");
		exit(-1);
	}else if(pid1 > 0){
		printf("leve 1 node\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	}else if(pid1==0){
		printf("level 2 node \n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	}
}
}
		
	
	
