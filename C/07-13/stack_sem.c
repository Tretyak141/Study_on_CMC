#include <stdio.h>
#define N 100000

void push_stack(int a[],int *k,int l){
    (*k)++;
    a[(*k)] = l;
}

void pop_stack(int a[],int *k,int *m){
    int l;
    (*m) = a[*k];
    (*k)--;
}


int main(){
    int top=-1;
    int stack[N];
    int l;
    while (((l=getchar())!=EOF)){
        int m;
        if (((stack[top]=='(')&&(l==')'))||(((stack[top]=='{')&&(l=='}')))||((stack[top]=='[')&&(l==']'))){
            pop_stack(stack,&top,&m);
        }
        else if ((l=='(')||(l==')')||(l=='[')||(l==']')||(l=='{')||(l=='}')){
            push_stack(stack,&top,l);
        }
    }
    if (top==-1){
        printf("\nTrue\n");
    }
    else{
        printf("\nFalse\n");
    } 
}