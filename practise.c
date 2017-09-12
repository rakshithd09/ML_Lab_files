#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct inst{
    char *label;
    char *opcode;
    char *opernd;
};
int main()
{
    struct inst oprn[100];
    char str[256];
    const char s[2] = " ";
    int i=0;
    char *token;
    FILE *fp;
    fp = fopen("stringsource.txt","r");
    int count;

   //fscanf(fp,"%s",str);
    while(fgets(str,sizeof(str),fp))
    {
         /* get the first token */

        token = strtok(str," ");
        //strcpy(oprn[i].label,token);
        oprn[i].label = strdup(token);
        token = strtok(NULL," ");
        //strcpy(oprn[i].opcode,token);
        oprn[i].opcode = strdup(token);
        token = strtok(NULL," ");
        //strcpy(oprn[i].opernd,token);
        oprn[i].opernd = strdup(token);

        if(oprn[i].opernd == NULL && oprn[i].opcode!=NULL)
        {
            oprn[i].opernd=oprn[i].opcode;
            oprn[i].opcode=oprn[i].label;
            oprn[i].label=NULL;
        }

        else if(oprn[i].opernd == NULL && oprn[i].opcode==NULL)
        {
            oprn[i].opernd=NULL;
            oprn[i].opcode=oprn[i].label;
            oprn[i].label=NULL;
        }

        printf( "%s\t%s\t%s\n",oprn[i].label,oprn[i].opcode,oprn[i].opernd);
        /* walk through other tokens */
        /*while( tokens[i][j] != NULL )
        {
            printf( "tokens[%d][%d] = %s\n",i,j,tokens[i][j] );
            j++;
            tokens[i][j] = strtok(NULL, s);
        }*/
        i++;

    }
    count=i;
    fclose(fp);
    //printf("%s   %d",oprn[1].label,count);


    FILE *labelFile;
    labelFile = fopen("labels.txt","w+");
    //FILE EMPTY?
    fseek(labelFile,0,SEEK_END);
    int lsize = ftell(labelFile);
    if(lsize==0)
        printf("label file is empty..\n");
    else
        printf("label file not empty..\n");
    printf("labels are being stored in the file..\n");
    for(i=0;i<count;i++)
    {
        if(oprn[i].label!=NULL)
        {
           // fseek(labelFile,0,SEEK_SET);
            fprintf(labelFile,"%s\n",oprn[i].label);
            printf("%s\n",oprn[i].label);
        }
    }
        fseek(labelFile,0,SEEK_END);
        lsize = ftell(labelFile);
    if(lsize==0)
        printf("file is empty..\n");
    else
        printf("file not empty..\n");


    FILE *oprndFile;
    oprndFile = fopen("operand.txt","w+");
    //FILE EMPTY?
    fseek(oprndFile,0,SEEK_END);
    lsize = ftell(oprndFile);
    if(lsize==0)
        printf("operand file is empty..\n");
    else
        printf("operand file not empty..\n");
    printf("operands are being stored in the file..\n");
    for(i=0;i<count;i++)
    {
        if(oprn[i].opernd!=NULL)
        {
           // fseek(labelFile,0,SEEK_SET);
            fprintf(oprndFile,"%s\n",oprn[i].opernd);
            printf("Operand=%s\tLength=%d\n",oprn[i].opernd,(strlen(oprn[i].opernd)-1));
        }
    }
        fseek(oprndFile,0,SEEK_END);
        lsize = ftell(oprndFile);
    if(lsize==0)
        printf("operand file is empty..\n");
    else
        printf("operand file not empty..\n");

    return 0;
}
