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

 
