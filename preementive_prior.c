#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int pr;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main() {

    int n;
    float avgtat, avgwt;
    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        p[i].pid=i+1;

        printf("Enter arrival time for process %d: ",i+1);
        scanf("%d",&p[i].at);

        printf("Enter burst time for process %d: ",i+1);
        scanf("%d",&p[i].bt);

        printf("Enter priority for process %d: ",i+1);
        scanf("%d",&p[i].pr);

        p[i].rt=p[i].bt;
    }

    int completed=0,time=0;
    float sum_tat=0,sum_wt=0;

    while(completed<n){

        int highest=-1;
        int best_pr=9999;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0){
                if(p[i].pr<best_pr){
                    best_pr=p[i].pr;
                    highest=i;
                }
            }
        }

        if(highest==-1){
            time++;
            continue;
        }

        p[highest].rt--;
        time++;

        if(p[highest].rt==0){

            completed++;
            p[highest].ct=time;
            p[highest].tat=p[highest].ct-p[highest].at;
            p[highest].wt=p[highest].tat-p[highest].bt;

            sum_tat+=p[highest].tat;
            sum_wt+=p[highest].wt;
        }
    }

    printf("\nProcess Table (Preemptive Priority Scheduling)\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);
    }

    avgtat=sum_tat/n;
    avgwt=sum_wt/n;

    printf("Average TAT = %.2f\n",avgtat);
    printf("Average WT = %.2f\n",avgwt);

    return 0;
}