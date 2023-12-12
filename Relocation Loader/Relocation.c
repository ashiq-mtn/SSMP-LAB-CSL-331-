#include<stdio.h>
#include<string.h>

char bitmask[12],bit[12];

void main()
{
    char input[10];
    char prgrmname[10],h_address[15],h_length[10],relocbit;
    int startaddress,t_address,t_length,opcode,op_address;
    int actualaddress;

    FILE *fin,*fout;

    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fprintf(fout,"---------------------\n");
    fprintf(fout,"Address\tContent\n");
    fprintf(fout,"---------------------\n");


    printf("Enter the actual starting address : ");
    scanf("%x",&startaddress);

    printf("ADDRESS\t\tCONTENT\n");
    fscanf(fin,"%s",input);

    while(strcmp(input,"E") != 0)
    {
        if(strcmp(input,"H") == 0)
        {
            fscanf(fin,"%s",prgrmname);
            fscanf(fin,"%s",h_address);
            fscanf(fin,"%s",h_length);

            fscanf(fin,"%s",input);
        }
        if(strcmp(input,"T") == 0)
        {

            fscanf(fin,"%x",&t_address);
            fscanf(fin,"%x",&t_length);
            fscanf(fin,"%s",bitmask);

            t_address += startaddress;

            convert(bitmask);

            int length = strlen(bit);
            if(length >= 11)
                length = 10;

            for(int i = 0 ; i < length ; i++)
            {
                fscanf(fin,"%x",&opcode);
                fscanf(fin,"%x",&op_address);

                relocbit = bit[i];

                if(relocbit == '0')
                {
                    actualaddress = op_address;
                }
                else
                {
                    actualaddress = op_address + startaddress;
                }
                fprintf(fout,"\n%x\t\t%x%x\n",t_address,opcode,actualaddress);
                printf("\n%x\t\t%x%x\n",t_address,opcode,actualaddress);
                t_address += 3;
            }

            fscanf(fin,"%s",input);
        }
    }
    fprintf(fout," ----------------------------\n");

    fclose(fin);
    fclose(fout);

}

void convert(char h[12])
{
    strcpy(bit,"");
    int len = strlen(h);
    for(int i = 0 ; i < len ; i++)
    {
        switch (h[i])
        {
            case '0':
                strcat(bit,"0");
                break;
            case '1':
                strcat(bit,"1");
                break;
            case '2':
                strcat(bit,"10");
                break;
            case '3':
                strcat(bit,"11");
                break;
            case '4':
                strcat(bit,"100");
                break;
            case '5':
                strcat(bit,"101");
                break;
            case '6':
                strcat(bit,"110");
                break;
            case '7':
                strcat(bit,"111");
                break;
            case '8':
                strcat(bit,"1000");
                break;
            case '9':
                strcat(bit,"1001");
                break;
            case 'A':
                strcat(bit,"1010");
                break;
            case 'B':
                strcat(bit,"1011");
                break;
            case 'C':
                strcat(bit,"1100");
                break;
            case 'D':
                strcat(bit,"1101");
                break;
            case 'E':
                strcat(bit,"1110");
                break;
            case 'F':
                strcat(bit,"1111");
                break;

        }
    }
}
