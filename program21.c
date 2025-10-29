#include <stdio.h>

int main()
{
    int i, n, bu[10], wa[10], tat[10], ct[10];
    int t, temp = 0, max, completed = 0;
    float awt = 0, att = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  
    }

    printf("Enter the size of time slice: ");
    scanf("%d", &t);

    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i])
            max = bu[i];
    }
  
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (bu[i] > 0) {
                if (bu[i] <= t) {
                    temp += bu[i];
                    tat[i] = temp;
                    bu[i] = 0;
                    completed++;
                } else {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nThe Average Turnaround Time is: %.2f", att / n);
    printf("\nThe Average Waiting Time is: %.2f\n", awt / n);

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
 
