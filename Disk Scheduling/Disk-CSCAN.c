#include<stdio.h>

void main()
{
    int n,hp,max,seek = 0;

    printf("Enter the no of Tracks : ");
    scanf("%d",&n);

    printf("Enter the HP : ");
    scanf("%d",&hp);

    printf("Enter the MAX Track : ");
    scanf("%d",&max);

    int t[n+2],q[n];

    printf("Enter the Tracks : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&q[i]);
        t[i] = q[i];
    }

    t[n] = hp;
    t[n+1] = max;

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < n+1-i ; j++)
        {
            if(t[j] > t[j+1])
            {
                int temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    int head;

    for(int i = 0 ; i < n+2 ; i++)
    {
        if(t[i] == hp)
        {
            head = i;
        }
    }

    for(int i = head ; i < n+2 ; i++)
    {
        printf("%d ==> ",t[i]);
    }
    printf("0 == > ");
    for(int i = 0 ; i < head ; i++)
    {
        printf("%d ==> ",t[i]);
    }

    seek = (max - hp) + max + t[head-1];

    printf("\nTotal Seek Time : %d",seek);

}


