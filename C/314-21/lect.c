#include <stdio.h>
#include <stdarg.h>

int max(int n,int first,...)
{
    va_list p;
    int i,k;
    va_start(p,first);
    for (int i=1;i<n;i++){
        k = va_arg(p,int);
        if (k>first) first=k;
    }
    return first;
}

int my_strlen(const char *s){
    const char *s1 = s;
    while (*s++!=0){
    }
    return s-s1-1;
}

void my_strcpy(char *to,const char *from){
    while (*to++);
    *to--;
    while(*to++ = *from++);
}

int main(){
    printf("%d\n",max(4,1,2,3,6));
    printf("%d\n", my_strlen("Akunamatata"));
    char to[40]="Hui";
    const char from[30] = "Pizda";
    my_strcpy(to,from);
    printf("%s\n",to);
    return 0;
}