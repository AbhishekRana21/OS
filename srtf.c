#include <stdio.h>

struct process{
        int pid;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
};

struct remaining{
	int inqueue;
	int bt;
};

int main(){
    int n, it = 0, tt, sumTAT = 0, sumWT = 0;
    float atat, awt, cpuUtil, cpuIdle;
    struct process temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    struct remaining rem[n];
    int totalCompleted = 0;
    for(int i=0; i<n; ++i){
        printf("For Process %d Enter:-\n",i+1);
        p[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);
        printf("Burst Time: ");
        scanf("%d",&p[i].bt);
        rem[i].inqueue = 0;
        rem[i].bt = p[i].bt;
    }
    
    int executing = 0;
    int time = 0;
    int noExec;
    int minProcess = p[0].bt;
    rem[0].inqueue = 1;
    rem[0].bt = p[0].bt;
    
    while(totalCompleted < n){
    	++time;
    	noExec = 1;
    	for(int i=0; i<n; ++i){
            if(rem[i].inqueue){
            	noExec = 0;
                if(rem[i].bt < minProcess){
                	minProcess = rem[i].bt;
                	executing = i;
                }
            }
        }
        if(noExec){
        	++it;
        }
        else{
		if(--rem[executing].bt == 0){
			rem[executing].inqueue = 0;
			p[executing].ct = time;
			++totalCompleted;
			minProcess = 10000;
		}
	}
        for(int i=0; i<n; ++i){
            if(p[i].at == time){
                rem[i].inqueue = 1;
            }
        }
    }


    tt = time;

    for(int i=0; i<n; ++i){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sumTAT += p[i].tat;
        sumWT += p[i].wt;
    }

    atat = sumTAT/(float)n;
    awt = sumWT/(float)n;

    cpuUtil = (tt - it)/(float)tt * 100;
    cpuIdle = (it)/(float)tt * 100;

    printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for(int i=0; i<n; ++i){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("ATAT = %f\n", atat);
    printf("AWT = %f\n", awt);
    printf("CPU Util = %f\n", cpuUtil);
    printf("CPU Idle = %f\n", cpuIdle);

    return 0;
}
