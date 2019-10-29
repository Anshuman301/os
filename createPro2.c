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
	pid_t pid1=fork();
	if(pid1 < 0){
		perror("  child2 of root is not created\n");
		exit(-1);
	}else if(pid1 > 0){
		printf("root node\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	}else if(pid1==0){
		printf("child2 node \n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	pid1=fork();
	if(pid1 < 0){
		perror("  child3 of root is not created\n");
		exit(-1);
	}else if(pid1 > 0){
		printf("root node\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	}else if(pid1==0){
		printf("child3 node \n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
		sleep(5);
	
	}
	}
	}else if(pid==0){
		if(pid < 0){
		perror("  child1 of root is not created\n");
		exit(-1);
	}else if(pid > 0){
		printf("root node\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
		sleep(5);
	}else if(pid ==0){
		printf("child1 node \n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
		sleep(5);
	}
}
}
		
	
	
