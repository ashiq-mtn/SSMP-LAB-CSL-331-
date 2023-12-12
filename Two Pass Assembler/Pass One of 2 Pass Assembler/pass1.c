#include<stdio.h>
#include<string.h>

void main()
{
    char label[15],opcode[15],operand[15];
    char mnemonic[15],code[3];

    int start,locctr;

    FILE *f1,*f2,*f3,*f4;

    f1 = fopen("input.txt","r");
    f2 = fopen("optab.txt","r");
    f3 = fopen("intermediate.txt","w");
    f4 = fopen("symtab.txt","w");

    fscanf(f1,"%s%s%s",label,opcode,operand);

    if(strcmp(opcode,"START") == 0)
    {
        start = atoi(operand);
        locctr = start;
    }
    else
    {
        start = 0;
        locctr = 0;
    }

    fprintf(f3,"\t%s\t%s\t%s\n",label,opcode,operand);

    fscanf(f1,"%s%s%s",label,opcode,operand);

    while(strcmp(opcode,"END") != 0)
    {
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

        if(strcmp(label,"-") != 0)
        {
            fprintf(f4,"%s\t%d\n",label,locctr);
        }

        fscanf(f2,"%s%s",mnemonic,code);

        while(strcmp(mnemonic,"END") != 0)
        {
            if(strcmp(mnemonic,opcode) == 0)
            {
                locctr += 3;
                break;
            }

            fscanf(f2,"%s%s",mnemonic,code);
        }

        rewind(f2);

        if(strcmp(opcode,"WORD") == 0)
        {
            locctr += 3;
        }
        else if (strcmp(opcode,"RESW") == 0)
        {
            locctr += 3*atoi(operand);
        }
        else if (strcmp(opcode,"RESB") == 0)
        {
            locctr += atoi(operand);
        }
        else if (strcmp(opcode,"BYTE") == 0)
        {
            if(operand[0] == 'C')
            {
                int len = strlen(operand);
                locctr += len-3;
            }
            else
                locctr++;
        }

        fscanf(f1,"%s%s%s",label,opcode,operand);
    }

    fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

    int totalLength = locctr - start;

    printf("Length : %d",totalLength);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}
