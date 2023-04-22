#include <stdio.h>
#include "string.h"

#define N 201

int check(char a[],int n)
{
    int i=0;
    while ((a[i]!=0)&&(i<n))
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
    printf("\n");
}

int main()
{
    int a = 0;
    char s[N];
    char s_new[N];
    input_string(s,&a);
    if (check(s,a)==1) firstrule(s,s_new,a);
    else secondrule(s,s_new,&a);
    output_string(s_new,a);
    return 0;
}