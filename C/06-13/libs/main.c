#include <stdio.h>
#include "matrix.h"


int main()
{
    int n,m;
    int **a;
    scanf("%d %d",&n,&m);
    a = generate(n,m);
    input(a,n,m);

    output(a,n,m);
    clean(a,n);
}
