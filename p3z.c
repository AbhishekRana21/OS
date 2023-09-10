#include<stdio.h>
#include<unistd.h>

int main(){
	int x = fork();
	if(x == 0){
		printf("Child Process ID: %d\n", getpid());
		printf("Child Terminated\n");
	}
	else{
		sleep(5);
		printf("Parent Process ID: %d\n", getpid());
		printf("Child has become a zombie\n");
		printf("Parent Terminated After 5 Seconds\n");
	}
	return 0;
}
