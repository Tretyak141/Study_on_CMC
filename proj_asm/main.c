#include <stdio.h>
#include "string.h"

#define N 201

int check(char a[],int n)
{
    int i=0;
    while (a[i]!=0)
    {
        if ((a[i]>='0' && a[i]<='9')||(a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')) i+=1;
        else return 2;
    }
    return 1;
}

void input_string(char s[],int *n)
{
    int c;
    int i=0;
    while (((c=getchar())!=' ')&&(c!=EOF)&&(c!='\n')&&(c!='\0'))
    {
        s[i] = c;
        i++;
    }
    (*n) = i;
}

void output_string(char s[],int n)
{
    for (int i=0;i<n;i++) putchar(s[i]);
}

int main()
{
    int a = 0;
    char s[N];
    input_string(s,&a);
    firstrule(s,a);
    output_string(s,a);
    return 0;
}