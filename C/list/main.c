#include <stdio.h>
#include "list.h"
#define N 1
#define M 2

int main()
{
    struct node *L = create_list(N);
    pr_list(L);
    printf("%f %d\n",middle(L),sorted_q(L));

    struct node *L1 = create_list(M);
    struct node* Ll=new_list(L,L1);
    pr_list(Ll);
    del_list(&L1);
    del_list((&(L)));
    del_list(&Ll);
}