#include<stdio.h>
#include<string.h>

void main()
{
    int start_addr,i,j;
    int len1 = 0,len2 = 0;
    char name[50],line[50],start[50];

    FILE *f1;

    f1 = fopen("input.txt","r");

    fscanf(f1,"%s",line);

    for(i = 2 ; line[i] != '^' ; i++)
    {
        name[len1] = line[i];
        len1++;
    }
    i++;
    for(j = i ; line[j] != '^' ; j++)
    {
        start[len2] = line[j];
        len2++;
    }

    printf("\nPROGRAM NAME : %s\n",name);

    start_addr = atoi(start);

    while(!feof(f1))
    {
        fscanf(f1,"%s",line);

        int length = strlen(line);

        if(line[0] == 'T')
        {
            i = 12;
            while(i < length)
            {
                if(line[i] != '^')
                {
                    printf("%d\t%c%c\n",start_addr,line[i],line[i+1]);
                    start_addr++;

                    i = i+2;
                }
                else
                    i++;
            }
        }
    }

    fclose(f1);
}
