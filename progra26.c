#include <stdio.h>

int main() {
    int n, at[20], bt[20], ct[20], wt[20], tat[20];
    float awt = 0, atat = 0, cpu_utilization;
    int total_idle = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }
