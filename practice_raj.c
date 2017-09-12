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

    FILE *labelFile;
    labelFile = fopen("labels.txt","w+");

    // FILE EMPTY???
    fseek(labelFile,0,SEEK_END);
    int filesize = ftell(labelFile);

    if(filesize==0)
        printf("File is empty\n");
    else
        printf("File is not Empty\n");

    // PRINTING LABELS TO THE FILE
    printf("Labels are printed in file\n");
    int flag;
    char *buf;
    for(i=0;i<count;i++)
    {
        if(oprn[i].label != NULL)
        {
            //fprintf(labelFile,"%s\n",oprn[i].label);

            if(i==0)
                fprintf(labelFile,"%s\n",oprn[i].label);
            else
            {
                flag=0;

                // CHECK FOR DUPLICATE BEFORE INSERTION
                fseek(labelFile,0,SEEK_SET);
                while(fgets(str,sizeof(str),labelFile))
                {
                    buf = strdup(oprn[i].label);
                    strcat(buf,"\n");

                    if(strcmp(str,buf)==0)
                    {
                            flag = 1;
                            break;
                    }
                }
                if(flag==0)
                {
                    fprintf(labelFile,"%s\n",oprn[i].label);
                }
                else
                {
                    printf("\n%s is a duplicate label\n\n",oprn[i].label);
                }
            }
        }
    }

    fseek(labelFile,0,SEEK_END);
    filesize = ftell(labelFile);

    if(filesize==0)
        printf("File is empty\n");
    else
        printf("File is not Empty\n");




    return 0;
}
