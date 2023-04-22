#include <stdio.h>
#define N 5

void input_array(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void output_array(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap_array(int a[],int i,int j)
{
    int k;
    k = a[j];
    a[j] = a[i];
    a[i] = k;
}

void choise_sort(int a[],int n)
{
    int s=0,r=0;
    for (int i=0;i<(n-1);i++)
    {
        int min=a[i],min_ind=i;
        for (int j=i+1;j<n;j++)
        {
            s++;
            if (min>a[j])
            {
                min = a[j];
                min_ind = j;
            }
        }

        if (a[i]!=a[min_ind]) 
        {
            swap_array(a,i,min_ind);
            r++;
        }
    }
    printf("Перестановок и сравнений соответсвенно %d и %d\n",r,s);
    output_array(a,n);
}

void bubble_sort(int a[],int n)
{ 
    int r=0,s=0;
    int i,j;
    for (i=n-1;i>0;i--)
    {
        for (j=0;j<i;j++){
            if (a[j+1]<a[j])
            {
                swap_array(a,j,j+1);
                r++;
            }
            s++;
        }
    }
    printf("Перестановок и сравнений соответсвенно %d и %d\n",r,s);
    output_array(a,n);
}





int main()
{
    //Тут сортировка простым выбором
    int a[N] = {1,2,3,4,5}; //Сортированный
    choise_sort(a,N); 
    int b[N] = {5,4,3,2,1}; //Сортированный в обр порядке
    choise_sort(b,N);
    int c[N] = {5,5,5,5,5}; //Все элементы равны
    choise_sort(c,N);
    int d[N] = {1,3,-15,20,6}; //Рандом
    choise_sort(d,N);
    int e[N] = {50,12,60,70,12}; //Рандом
    choise_sort(e,N);

    //А теперь для пузырьковой сортировки то же самое

    int f[N] = {1,2,3,4,5};
    bubble_sort(f,N);
    int g[N] = {5,4,3,2,1};
    bubble_sort(g,N);
    int h[N] = {5,5,5,5,5};
    bubble_sort(h,N);
    int t[N] = {1,3,-15,20,6};
    bubble_sort(t,N);
    int u[N] = {50,12,60,70,12};
    bubble_sort(u,N);
}