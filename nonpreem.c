#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n = 4;
    float avgtat, avgwt;
    struct process p[5];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", (i + 1));
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", (i + 1));
        scanf("%d", &p[i].bt);
    }


    for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }}}

    float sum_tat = 0, sum_wt = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p[i].ct = p[i].at + p[i].bt;
        } else {
            if (p[i].at > p[i-1].ct) {
                p[i].ct = p[i].at + p[i].bt;
            } else {
                p[i].ct = p[i-1].ct + p[i].bt;
            }
        }

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        sum_tat += p[i].tat;
        sum_wt += p[i].wt;
    }
   printf("\nSorted Process Table (by Arrival Time):\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }


avgtat = sum_tat / n;
    avgwt = sum_wt / n;

    printf("Average TAT = %f\n", avgtat);
    printf("Average WT = %f\n", avgwt);

    return 0;
}
