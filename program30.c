#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], ct[20], completed[20] = {0};
    float awt = 0, atat = 0;
    int time = 0, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }
 printf("\nGantt Chart:\n");

    while (count < n) {
        int min_bt = 9999, index = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                index = i;
            }
        }

        if (index == -1) {
            time++;
            continue;
        }

        printf("| P%d ", index + 1);
        time += bt[index];
        ct[index] = time;
        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - bt[index];
        completed[index] = 1;
        count++;
    }
