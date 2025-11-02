#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], p[20];
    float awt = 0, atat = 0;
    int temp;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

 wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i];
        atat += tat[i];
    }
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}












