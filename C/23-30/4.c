#include <stdio.h>

int breakes(char a[]){
    int i=0;
    int counter=0;
    while (a[i]!='\0')
    {
        counter += (a[i]==' ');
        i++;
    }
    return counter;
}

int main(int argc,char *argv[])
{
    for (int i=1;i<argc;i++)
    {
        printf("String: %s\n",argv[i]);
        int j=0;
        int counter=0;
        while (argv[i][j]!='\0')
        {
            counter++;
            j++;
        }
        printf("Length: %d\n",counter);
        printf("Last: %c\n",argv[i][counter-1]);
        printf("Breakes: %d\n\n",breakes(argv[i]));
    }
    return 0;
}