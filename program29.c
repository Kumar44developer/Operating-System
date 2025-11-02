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
