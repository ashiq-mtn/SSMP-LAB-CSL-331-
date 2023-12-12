#include<stdio.h>

typedef struct process
{
    int pid,at,bt,tat,wt;
}process;

void main()
{
    int n , ct = 0;
    float awt , avg_tat;

    printf("Enter the no of Processes : ");
    scanf("%d",&n);

    process p[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the AT and BT of Process %d : ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid = i+1;
    }
    //Sorting the processes based on ARRIVAL Time in ascending order
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(ct < p[i].at)
        {
            ct = p[i].at + p[i].bt;
        }
        else
        {
            ct = ct + p[i].bt;
        }

        p[i].tat = ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        awt += p[i].wt;
        avg_tat += p[i].tat;
    }
    
    awt = awt/n;
    avg_tat = avg_tat/n;
    //(Optional) - Sorting the processes based on PROCESS ID in ascending order 
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(p[j].pid > p[j+1].pid)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("\nPID\tAT\tBT\tTAT\tWT\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
    }

    printf("Average TAT : %.2f\n",avg_tat);
    printf("Average WT : %.2f\n",awt);

}
