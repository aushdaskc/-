#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



node* bt_create(void)
{
    int n;

    scanf("%d", &n);
    if(n == -1) return NULL;

    node* root = (node*)malloc(sizeof(node));
    root->data = n;
  
    root->left = bt_create();
  
    root->right = bt_create();

    return root;
}

void bt_destroy(node* bt)
{
    if(bt == NULL) return;
   
    bt_destroy(bt->left);
   
    bt_destroy(bt->right);
  
    free(bt);
}

void show(node* bt)
{
    printf("%d ", bt->data);
}
void traverse(node* bt, void(*visit)(node*), int order)
{
    if(bt == NULL) return;
    if(order == 1) visit(bt);   // 先序遍历 pre_order
    traverse(bt->left, visit, order);
    if(order == 2) visit(bt);   // 中序遍历 mid_order
    traverse(bt->right, visit, order);
    if(order == 3) visit(bt);   // 后序遍历 last_order
}

// 层序遍历
void level_order(node* bt)
{
    queue* q = create(100);
    node* p = NULL;

    push_back(q, bt);
    while(q->len != 0)
    {
        p = *front(q);
        printf("%d ", p->data);
        pop_front(q);
        if(p->left != NULL) push_back(q, p->left);
        if(p->right != NULL) push_back(q, p->right);
    }
    destroy(q);
}

void tra(node* bt, int order)
{
    if(order <= 3 && order >=1) traverse(bt, show, order);
    if(order == 4) level_order(bt);
}

int main()
{
    node* bt = bt_create();
    int order;
    printf("输入遍历方式(1.先序 2.中序 3.后序 4.层序):");
    scanf("%d", &order);

    bt_destroy(bt);

    return 0;
}