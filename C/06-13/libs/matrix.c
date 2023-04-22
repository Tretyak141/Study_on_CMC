#include <stdio.h>
#include <stdlib.h>

int** generate(int n,int m)
{
    int **a;
    a = (int**)calloc(n,sizeof(int*));
    for (int i=0;i<n;i++) a[i] = (int*)calloc(m,sizeof(int));
    return a;
}

void input(int **a,int n,int m)
{
    for (int i=0;i<n;i++) 
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
}

void output(int **a,int n,int m)
{
    for (int i=0;i<n;i++) 
    {
        for (int j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void clean(int **a,int n)
{
    for (int i=0;i<n;i++)
        free(a[i]);
    free(a);
}

int **pmul(int**a,int**b,int n,int m,int k)
{
    int **ans;
    ans = generate(n,k);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<k;j++)
        {
            ans[i][j] = 0;
            for (int l=0;l<m;l++) ans[n][k] += a[i][l]*b[l][j];
        }
    }
    return ans;
}