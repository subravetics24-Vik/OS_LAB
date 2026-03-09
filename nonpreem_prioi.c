#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int pr;
    int ct;
    int tat;
    int wt;
};
int main() {
int n;
float avgtat, avgwt;
struct process p[10];   // allow more processes
printf("\nEnter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
p[i].pid = i + 1;
printf("Enter arrival time for process %d: ", (i + 1));
scanf("%d", &p[i].at);
printf("Enter burst time for process %d: ", (i + 1));
scanf("%d", &p[i].bt);
printf("Enter priority for process %d: ", (i + 1));
scanf("%d", &p[i].pr);}

int completed = 0, time = 0;
float sum_tat = 0, sum_wt = 0;
int done[10] = {0};
while (completed < n) {
        int shortest = -1;
        int best_pr = 9999;

    for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time) {
                if (p[i].pr < best_pr) {
                    best_pr = p[i].pr;
                    shortest = i;
                }}}

if (shortest == -1) {
            time++;
            continue;
        }

        p[shortest].ct = time + p[shortest].bt;
        p[shortest].tat = p[shortest].ct - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;

        sum_tat += p[shortest].tat;
        sum_wt += p[shortest].wt;

        time = p[shortest].ct;
        done[shortest] = 1;
        completed++;
    }

    printf("\nProcess Table (Non-preemptive Priority Scheduling):\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
p[i].pid, p[i].at, p[i].bt, p[i].pr,p[i].ct, p[i].tat, p[i].wt);
    }

    avgtat = sum_tat / n;
    avgwt = sum_wt / n;

    printf("Average TAT = %.2f\n", avgtat);
    printf("Average WT = %.2f\n", avgwt);

    return 0;
}
