#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
    int rem;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    int time, done = 0, i;
    float avgtat, avgwt;


    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", (i + 1));
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", (i + 1));
        scanf("%d", &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].completed = 0;
    }
for (time = 0; done < n; time++) {
int shortest = -1;
for (i = 0; i < n; i++) {
if (!p[i].completed && p[i].at <= time) {
if (shortest == -1 || p[i].rem < p[shortest].rem) {
shortest = i;
}}}

if (shortest == -1) continue;
p[shortest].rem--;
if(p[shortest].rem == 0) {
p[shortest].completed = 1;
p[shortest].ct = time + 1;
done++;
        }
    }


    int sum_tat = 0, sum_wt = 0;
    printf("\nProcess Table:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sum_tat += p[i].tat;
        sum_wt += p[i].wt;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    avgtat = (float)sum_tat / n;
    avgwt = (float)sum_wt / n;

    printf("\nAverage TAT = %.2f\n", avgtat);
    printf("Average WT = %.2f\n", avgwt);

    return 0;
}
