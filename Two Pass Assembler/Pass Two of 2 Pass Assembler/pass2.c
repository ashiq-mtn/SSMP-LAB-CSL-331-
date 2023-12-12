#include<stdio.h>
#include<string.h>

void main()
{
    char locctr[15],label[15],opcode[15],operand[15];
    char mnemonic[15],code[3];
    char symbol[15],sym_addr[15];

    int start,count = 0;
    char startAddress[15];int endAddress;

    FILE *f1,*f2,*f3,*f4;

    f1 = fopen("intermediate.txt","r");
    f2 = fopen("optab.txt","r");
    f3 = fopen("symtab.txt","r");
    f4 = fopen("output.txt","w");

    fscanf(f1,"%s%s%s",label,opcode,operand);
    fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);

    while(strcmp(opcode,"END") != 0)
    {
        count++;
        if(strcmp(opcode,"RESW") == 0 || strcmp(opcode,"RESB") == 0)
        {
            count--;
        }

        fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
        endAddress = atoi(locctr);
    }
    endAddress = atoi(locctr);
    count = count * 3;

    rewind(f1);

    fscanf(f1,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START") == 0)
    {
        strcpy(startAddress,operand);
    }

    int totalLength = endAddress - atoi(startAddress);

    fprintf(f4,"H^%s^00%s^0000%x\nT^00%s^%x",label,operand,totalLength,operand,count);
    printf("H^%s^00%s^0000%x\nT^00%s^%x",label,operand,totalLength,operand,count);

    fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);

    while(strcmp(opcode,"END") != 0)
    {
        fscanf(f2,"%s%s",mnemonic,code);
        while(!feof(f2))
        {
            if(strcmp(mnemonic,opcode) == 0)
            {
                fscanf(f3,"%s%s",symbol,sym_addr);
                while(!feof(f3))
                {
                    if(strcmp(symbol,operand) == 0)
                    {
                        fprintf(f4,"^%s%s",code,sym_addr);
                        printf("^%s%s",code,sym_addr);
                        break;
                    }
                    else
                        fscanf(f3,"%s%s",symbol,sym_addr);
                }
                break;
            }
            else
                fscanf(f2,"%s%s",mnemonic,code);
        }

        rewind(f2);
        rewind(f3);

        if(strcmp(opcode,"WORD") == 0)
        {
            fprintf(f4,"^00000%s",operand);
            printf("^00000%s",operand);
        }
        else if(strcmp(opcode,"BYTE") == 0)
        {
            fprintf(f4,"^");
            printf("^");

            int len = strlen(operand);
            for(int i = 2 ; i < len-1 ; i++)
            {
                fprintf(f4,"%x",operand[i]);
                printf("%x",operand[i]);
            }

        }

        fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
    }

    fprintf(f4,"\nE^00%s",startAddress);
    printf("\nE^00%s",startAddress);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

}
