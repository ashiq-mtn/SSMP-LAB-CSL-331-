#include<stdio.h>

typedef struct process{
    int pid,bt,tat,wt,rt;
}process;

void main()
{
    int n,tq;
    float awt,avg_tat;

    printf("Enter the no of Processes : ");
    scanf("%d",&n);

    process p[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the BT of Process %d : ",i+1);
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i+1;
    }

    printf("Enter the Time Quantum : ");
    scanf("%d",&tq);

    int ct = 0 , currentTime = 0 , completed = 0;

    while(completed != n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].rt > 0)
            {
                if(p[i].rt < tq)
                {
                    ct = p[i].rt;
                }
                else
                {
                    ct = tq;
                }

                p[i].rt -= ct;
                currentTime += ct;

                if(p[i].rt == 0)
                {
                    completed++;
                    p[i].tat = currentTime;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
        awt += p[i].wt;
        avg_tat += p[i].tat;
    }

    awt = awt/n;
    avg_tat = avg_tat/n;

    printf("\nPID\tBT\tTAT\tWT\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%P%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].tat,p[i].wt);
    }

    printf("Average TAT : %.2f\n",avg_tat);
    printf("Average WT : %.2f\n",awt);

}
