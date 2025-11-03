#include <stdio.h>
#include <limits.h>

int main() {
    int n, at[20], bt[20], rt[20], wt[20], tat[20], ct[20];
    int completed = 0, t = 0, minm, shortest = 0, finish_time;
    float awt = 0, atat = 0;
    int check = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
  while (completed != n) {
        minm = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (at[j] <= t && rt[j] > 0 && rt[j] < minm) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            completed++;
            check = 0;
            finish_time = t + 1;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
        t++;
    }
   for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}












