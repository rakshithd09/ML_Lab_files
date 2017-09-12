#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct inst{
    char *label;
    char *opcode;
    char *op;
};
int main()
{
    struct inst *oprn;
    char str[256];
    const char s[2] = " ";
    int i=0;
    FILE *fp;
    fp = fopen("stringsource.txt","r");

   //fscanf(fp,"%s",str);
    while(fgets(str,sizeof(str),fp))
    {
         /* get the first token */

        oprn[i].label = strtok(str, s);
        oprn[i].opcode = strtok(NULL, s);
        oprn[i].op = strtok(NULL, s);

        printf( "%s %s %s\n",oprn[i].label,oprn[i].opcode,oprn[i].op);

        /* walk through other tokens */
        /*while( tokens[i][j] != NULL )
        {
            printf( "tokens[%d][%d] = %s\n",i,j,tokens[i][j] );
            j++;
            tokens[i][j] = strtok(NULL, s);
        }*/
        i++;

    }
    fclose(fp);
    return 0;
}
