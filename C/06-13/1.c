#include <stdio.h>

int main(int argc,char **argv)
{
    for (int i=1;i<argc;i++)
    {
        int flagx = 0;
        int j=0;
        while (argv[i][j]!='\0')
        {
            if (argv[i][j]=='x') flagx = 1;
            j++;
        }
        if (argv[i][j-1]=='t') printf("%s\n",argv[i]);
    }
    return 0;
}