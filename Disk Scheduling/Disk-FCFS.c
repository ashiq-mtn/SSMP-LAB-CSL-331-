#include<stdio.h>

void main()
{
    int n,hp,seek = 0;

    printf("Enter the no of Tracks : ");
    scanf("%d",&n);

    printf("Enter the HP : ");
    scanf("%d",&hp);

    int track[n];

    printf("Enter the Tracks : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&track[i]);
    }

    int diff = 0;

    printf("%d ==> ",hp);

    for(int i = 0 ; i < n ; i++)
    {
        diff = hp - track[i];

        if(diff < 0)
        {
            diff = track[i] - hp;
        }

        hp = track[i];

        printf("%d ==> ",track[i]);

        seek += diff;
    }
    printf("\nTotal Seek Time : %d",seek);

}
