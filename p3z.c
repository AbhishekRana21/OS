#include<stdio.h>
#include<unistd.h>

int main(){
	int x = fork();
	if(x == 0){
		sleep(5);
		printf("Child Process ID: %d\n", getpid());
		printf("Child Terminated After 5 Seconds");
	}
	else{
		
		printf("Parent Process ID: %d\n", getpid());
		printf("Child has become a zombie");
		printf("Parent Terminated");
	}
	return 0;
}
