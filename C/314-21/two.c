#include <stdio.h>

void my_strcat(char *to,const char *from){
    while (*to++);
    *to--;
    while(*to++ = *from++);
}

int my_strchar(const char *to,char c)
{
    int k = -1;
    int i = 0;
    while (*to)
    {
        if ((*to)==c){
            k = i;
            return k;
        }
        i++;
        *to++;
    }
    return k;
}

int my_strrchar(const char *to,char c)
{
    int k = -1;
    int i = 0;
    while (*to)
    {
        if ((*to)==c){
            k = i;
        }
        i++;
        *to++;
    }
    return k;
}