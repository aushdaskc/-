#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* create(size_t cap)
{
    queue* q = (queue*)malloc(sizeof(queue));  
    
    if(q == NULL)
    {
        perror("malloc fail");
        return NULL;
    }

    q->data = (elem_t*)malloc(cap * sizeof(elem_t));

    if(q->data == NULL)
    {
        perror("malloc fail");
        free(q);
        return NULL;
    }

    q->head = q->tail = 0;
    q->cap = cap;
    q->len = 0;

    return q;
}

void destroy(queue* q)
{
    free(q->data);
    free(q);
}

void clear(queue* q)
{
    q->head = q->tail = 0;
    q->len = 0;
}

int empty(queue* q)
{
    return !q->len;
}

int full(queue* q)
{
    return q->len == q->cap;
}

size_t size(queue* q)
{
    return q->len;
}

void push_back(queue* q, elem_t data)
{
    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % q->cap;
    q->len++;
}

void pop_front(queue* q)
{
    q->head = (q->head + 1) % q->cap;
    q->len--;
}

elem_t* front(queue* q)
{
    return q->data + q->head;
}

elem_t* back(queue* q)
{
    return q->data + (q->tail ? q->tail - 1 : q->cap - 1);
}

elem_t* at(queue* q, int pos)
{
    if(pos < 0 || pos >= q->len) return NULL;

    return q->data + (q->head + pos) % q->cap;
}