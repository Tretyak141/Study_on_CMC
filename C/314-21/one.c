#include <stdio.h>
#include <stdarg.h>

double middle(unsigned int n,int first,...)
{
    va_list p;
    int i,k;
    va_start(p,first);
    double ans=first;
    for (i=1;i<n;i++){
        k = va_arg(p,int);
        ans+=k;
    }
    va_end(p);
    return ans/n;
}

int main()
{
    printf("%f\n",middle(5,1,2,3,4,5));
    return 0;
}