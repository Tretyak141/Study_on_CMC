struct node
{
    int elem;
    struct node * next;
};

struct node* create_list(int);
void del_list(struct node**);
void pr_list(struct node*);
double middle(struct node* L);
void pop(struct node**);
int sorted_q(struct node*);
struct node* new_list(struct node*,struct node*);