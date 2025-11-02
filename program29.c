#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], ct[20], completed[20] = {0};
    float awt = 0, atat = 0;
    int time = 0, count = 0, min_bt, min_index;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }
 while (count < n) {
        min_bt = 9999;
        min_index = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        time += bt[min_index];
        ct[min_index] = time;
        tat[min_index] = ct[min_index] - at[min_index];
        wt[min_index] = tat[min_index] - bt[min_index];
        completed[min_index] = 1;
        count++;
    }
 for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }
