#include <stdio.h>
#include <string.h>
struct code
{
    char label[20];
    char opcode[20];
    char operand[20];
};

struct op
{
    char ops[10];
};

int main()
{
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    struct code c[20];
    struct op o[10];
    char str[100];
    char str1[100];

    char *token;
    char *token1;
    int i=0,j=0,p=0,q=0,k=0,f=0;
    fp = fopen("New Text Document.txt","r");
    while(!feof(fp))
    {
        i=0;
        fscanf(fp,"%[^\n]\n",str);
        strcpy(str1,str);
        token = strtok(str," ");

        while(token != NULL)
        {
            i++;
            token = strtok(NULL, " ");
        }
        printf("%d\n",i);
        if(i==3)
        {
            k=0;
            token1 = strtok(str1," ");
            while(token1!=NULL)
            {
                if(k==0)
                    strcpy(c[j].label,token1);
                if(k==1)
                    strcpy(c[j].opcode,token1);
                if(k==2)
                    strcpy(c[j].operand,token1);

                k++;
                token1= strtok(NULL," ");
            }
        }

        if(i==2)
        {
            strcpy(c[j].label,"   ");
            k=0;
            token1 = strtok(str1," ");
            while(token1!=NULL)
            {

                if(k==0)
                    strcpy(c[j].opcode,token1);
                if(k==1)
                    strcpy(c[j].operand,token1);
                k++;
                token1 = strtok(NULL," ");

            }
        }

        if(i==1)
        {
            strcpy(c[j].opcode,"   ");
            strcpy(c[j].operand,"   ");
            token1 = strtok(str1," ");
            while(token1!=NULL)
            {
                strcpy(c[j].label,token1);
                token1 = strtok(NULL," ");

            }
        }
        j++;
    }
    fclose(fp);

    for(p=0;p<j;p++)
    {
        printf("%s\t",c[p].label);
        printf("%s\t",c[p].opcode);
        printf("%s\n",c[p].operand);
    }

    fp1 = fopen("Labels.txt","r+");
    fseek (fp1, 0, SEEK_END);
    int size = ftell(fp1);
    int flag=0;
    if (0 == size) {
         for(p=0;p<j;p++)
            {
                flag=0;
                for(q=0;q<p;q++)
                {
                    if(!strcmp(c[p].label,c[q].label))
                       flag = 1;
                      // break;
                }
                if(flag==0)
                    fprintf(fp1,"%s\n",c[q].label);

            }
    }
    else{
        printf("\nFile is not empty\n");
    }




    fclose(fp2);
}
