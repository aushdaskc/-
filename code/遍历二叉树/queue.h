#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct node
{
    int data;                
    struct node* left, *right;  

} node;

typedef node* elem_t;

typedef struct
{
    elem_t* data;  
    int head;      
    int tail;      
    size_t len;   
    size_t cap;    

} queue;


queue* create(size_t cap);
void destroy(queue* q);
void clear(queue* q);
int empty(queue* q);
int full(queue* q);
size_t size(queue* q);
void push_back(queue* q, elem_t data);
void pop_front(queue* q);
elem_t* front(queue* q);
elem_t* back(queue* q);

#endif