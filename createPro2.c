#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
pid_t pid;
pid=fork();
if(pid < 0 ){
	perror("Process Creation failed");
	exit(-1);   
}else if(pid >0){
	wait(NULL);
	printf("root node created\n");
	printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
	pid_t pid1 = fork();
	if(pid1 > 0){
		wait(NULL);
		pid_t pid2 = fork();
		if(pid2 > 0){
			wait(NULL);
		}else if(pid2 == 0){
			printf("Child 3 created\n");
			printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid2);
		}
	}else if(pid1 == 0){
		printf("Child 2 created\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
	}
	} else if(pid == 0){
		printf("Child 1 created\n");
		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);

	}
}
// 	pid_t pid1=fork();
// 	if(pid1 < 0){
// 		perror("  child2 of root is not created\n");
// 		exit(-1);
// 	}else if(pid1 > 0){
// 		printf("root node\n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
// 		sleep(5);
// 	}else if(pid1==0){
// 		printf("child2 node \n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
// 		sleep(5);
// 	pid1=fork();
// 	if(pid1 < 0){
// 		perror("  child3 of root is not created\n");
// 		exit(-1);
// 	}else if(pid1 > 0){
// 		printf("root node\n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
// 		sleep(5);
// 	}else if(pid1==0){
// 		printf("child3 node \n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid1);
// 		sleep(5);
	
// 	}
// 	}
// 	}else if(pid==0){
// 		if(pid < 0){
// 		perror("  child1 of root is not created\n");
// 		exit(-1);
// 	}else if(pid > 0){
// 		printf("root node\n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
// 		sleep(5);
// 	}else if(pid ==0){
// 		printf("child1 node \n");
// 		printf("Parent pid:%d\tSelf Pid:%d\t pid:%d\n",getppid(),getpid(),pid);
// 		sleep(5);
// 	}
// }
//}
		
	
	
