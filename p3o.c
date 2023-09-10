#include<stdio.h>
#include<unistd.h>

int main(){
        int x = fork();
        if(x == 0){
                sleep(5);
                printf("\nChild Process ID: %d\n", getpid());
                printf("Child is Orphan\n");
                printf("Child Terminated After 5 Seconds\n");

        }
        else{
                printf("Parent Process ID: %d\n", getpid());
                printf("Parent Terminated\n");
        }
        return 0;
}
