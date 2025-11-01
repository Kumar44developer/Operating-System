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

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) {
            total_idle += (at[i] - ct[i - 1]);
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }
