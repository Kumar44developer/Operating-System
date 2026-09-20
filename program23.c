#include <stdio.h>

int main() {
    int n, bt[20], p[20], pri[20], wt[20], tat[20];
    float awt = 0, atat = 0;
    int temp;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time and Priority for P%d (lower number = higher priority): ", i + 1);
        scanf("%d%d", &bt[i], &pri[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pri[i] > pri[j]) {
                temp = pri[i]; pri[i] = pri[j]; pri[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}
