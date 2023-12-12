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
    printf("asdasd ad");
    for(int i = head ; i < n+2 ; i++)
    {
        printf("%d ==> ",t[i]);
    }
    for(int i = head-1 ; i >= 1 ; i--)
    {
        printf("%d ==> ",t[i]);
    }
    printf("%d",t[0]);

    seek = (max - hp) + (max - t[0]);

    printf("\nTotal Seek Time : %d",seek);

}

