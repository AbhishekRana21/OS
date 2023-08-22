#include<stdio.h>
#include<unistd.h>

int main(){
	int x = fork();
	if(x == 0){
		printf("Child Process ID: %d\n", getpid());
		printf("Child is Orphan\n");
		printf("Child Terminated");
		
	}
	else{
		sleep(5);
		printf("Parent Process ID: %d\n", getpid());
		printf("Parent Terminated After 5 Seconds");
	}
	return 0;
}
