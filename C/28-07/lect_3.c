#include <stdio.h>
#define n 6

void input_array(int a[],int N){
    for (int i=0;i<N;i++){
        int d;
        scanf("%d",&d);
        a[i] = d;
    }
    return;
}

void output_array(int a[],int N){
    for (int i=0;i<N;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return;
}

int found_ind(int a[],int N,int find){
    int ind = -1; //if element not found, -1 return
    for (int i=0;i<N;i++){
        if (a[i]==find){
            ind = i;
            break;
        }
    }
    return ind;
}

double middle(int a[],int N){
    double mid = 0;
    for (int i=0;i<N;i++){
        mid+=a[i];
    }
    mid/=N;
    return mid;
}

int sorted(int a[],int N){
    int flag = 1; //started think: array is sorted
    for (int i=1;i<N;i++){
        if (a[i]<a[i-1]){
            flag = 0;
            break;
        }
    }
    return flag;
}

void minims(int a[],int N,int k[]){
    for (int i=1;i<n;i++){
        if (a[k[0]]>=a[i]){
            k[1] = k[0];
            k[0] = i;
        }
        else{
            if (a[k[1]]>a[i]){
                k[1] = i;
            }
        }
    }
    return;
}


int main(){
    int a[n];
    int k[2] = {0,1};
    input_array(a,n);
    output_array(a,n);
    int s = found_ind(a,n,10);
    double l = middle(a,n);
    int m = sorted(a,n/2);
    int d = sorted(a+n/2+1,n/2);
    printf("%d %lf %d %d Пидрила \n",s,l,m,d);
    minims(a,n,k);
    output_array(k,2);
    return 0;
}
