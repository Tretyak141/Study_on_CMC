#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node * create_list(int n)
{
    int x;
    struct node* L = NULL, *last;
    for (int i=0;i<n;i++)//задача 2 по вводу до конца файла сдана, теперь по количеству символов
    {
        scanf("%d",&x);
        if (L==NULL)
        {
            L = malloc(sizeof(struct node));
            L->elem = x;
            L->next = NULL;
            last = L;
        }
        else
        {
            last->next = malloc(sizeof(struct node));
            last = last->next;
            last->elem = x;
            last->next = NULL;
        }
    }
    return L;
}

void del_list(struct node** L){
  if (!(*L)) return;
  del_list(&(*L)->next);
  free(*L);
  *L= NULL;
}


void pr_list(struct node* L)
{
   while (L)
   {
      printf("%d ",L->elem);
      L = L->next;
   }
   printf("\n");
}

double middle(struct node* L)
{
    if (L==NULL)
    {
        return 0.0;
    }
    double ans=0.0;
    int counter=0;
    while (L)
    {
        ans+=(L->elem);
        L = L->next;
        counter++;
    }
    return ans/counter;
}

void pop(struct node** L)
{
    struct node* last = (*L)->next;
    struct node* prelast = (*L);
    if ((prelast->next)==NULL)
    {
        del_list(&prelast);
    }
    else
    {
        while (last->next)
        {
            last = last->next;
            prelast = prelast->next;
        }
        del_list(&(prelast->next));
    }
}



int sorted_q(struct node* L)
{
    if (L==NULL)
    {
        return 1;
    }
    int last = L->elem;
    L = L->next;
    while(L)
    {
        if (last>(L->elem)) return 0;
        last = L->elem;
        L = L->next;
    }
    return 1;
}



struct node* new_list(struct node* l1,struct node* l2)
{
    struct node* l = NULL;
    struct node* last;
    while (l2&&l1)
    {
        if (l)
            {
            last->next = malloc(sizeof(struct node));
            last = last->next;
            if ((l1->elem)<=(l2->elem))
            {
                last->elem = l1->elem;
                l1 = l1->next;
                last->next = NULL;
            }
            else
            {
                last->elem = l2->elem;
                l2 = l2->next;
                last->next = NULL;
            }
        }
        else
        {
            l = malloc(sizeof(struct node));
            if ((l1->elem)<=(l2->elem))
            {
                l->elem = l1->elem;
                l1 = l1->next;
                l->next = NULL;
            }
            else
            {
                l->elem = l2->elem;
                l2 = l2->next;
                l->next = NULL;
            }
            last = l;
        }
    }
    while (l1)
    {
        if (l)
        {
            last->next = malloc(sizeof(struct node));
            last = last->next;
            last->elem = l1->elem;
            l1 = l1->next;
            last->next = NULL;
        }
        else
        {
            l = malloc(sizeof(struct node));
            l->elem = l1->elem;
            l1 = l1->next;
            l->next = NULL;
            last = l;
        }
    }
    while (l2)
    {
        if (l)
        {
            last->next = malloc(sizeof(struct node));
            last = last->next;
            last->elem = l2->elem;
            l2 = l2->next;
            last->next = NULL;
        }
        else
        {
            l = malloc(sizeof(struct node));
            l->elem = l2->elem;
            l2 = l2->next;
            l->next = NULL;
            last = l;
        }
    }
    return l;
}