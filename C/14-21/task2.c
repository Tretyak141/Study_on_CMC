#include <stdio.h>
//3.48: b
//3.49: h

int main()
{
    int c;
    while ((c=getchar())!= EOF && c!='.'){
        if (c!='-'){
            printf("%c",c);
            if (c=='&'){
                printf("%c",c);
            }
        }
    }
}