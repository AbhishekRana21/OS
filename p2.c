#include<stdio.h>
#include<unistd.h>

int main(){
	int arr[8] = {1,2,3,4,5,6,7,8}, sumOdd = 0, sumEven = 0;
	int x = fork();
	if(x==0){
		//Child : Odd Sum
		printf("\nChild PID: %d", getpid());
		
		for(int i=0; i<8; ++i){
			if(arr[i] & 1){
				sumOdd+=arr[i];
			}
		}
		printf("\nSum of Odd: %d", sumOdd);
	}
	else{
		//Parent : Even Sum
		printf("\nParent PID: %d", getpid());
		
		for(int i=0; i<8; ++i){
			if(!(arr[i] & 1)){
				sumEven+=arr[i];
			}
		}
		printf("\nSum of Even: %d", sumEven);
	}
	return 0;
}
