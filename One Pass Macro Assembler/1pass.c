#include<stdio.h>
#include<string.h>

struct mdt{
    char label[10],opcode[10],operand[10];
}d[10];

void main()
{
    char label[10],opcode[10],operand[10];
    char macroname[10];

    int lines;

    FILE *f1,*f2,*f3;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    f3 = fopen("deftab.txt","w");

    fscanf(f1,"%s%s%s",label,opcode,operand);

    while(strcmp(opcode,"END") != 0)
    {
        if(strcmp(opcode,"MACRO") == 0)
        {
            strcpy(macroname,label);
            fscanf(f1,"%s%s%s",label,opcode,operand);
            //lines = 0;

            while(strcmp(opcode,"MEND") != 0)
            {
                fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);

                strcpy(d[lines].label,label);
                strcpy(d[lines].opcode,opcode);
                strcpy(d[lines].operand,operand);
                fscanf(f1,"%s%s%s",label,opcode,operand);
                lines++;
            }
        }
        else if(strcmp(opcode,macroname) == 0)
        {
            for(int i = 0 ; i < lines ; i++)
            {
                fprintf(f2,"%s\t%s\t%s\n",d[i].label,d[i].opcode,d[i].operand);
            }
        }
        else
        {
            fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
        }

        fscanf(f1,"%s%s%s",label,opcode,operand);
    }

    fprintf(f2,"%s\t%s\t%s",label,opcode,operand);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("WORKED");
}
