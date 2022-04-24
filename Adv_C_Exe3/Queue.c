#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

void destroyQueue(Queue* q)
{
    while (q->head != NULL) {
        dequeue(q);
    }
    free(q);
    q = NULL;
}

void enqueue(Queue* q, unsigned int data)
{
    intNode* newNode = (intNode*)malloc(sizeof(intNode));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmptyQueue(q)) {
          q->head = q->tail = newNode;
       }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

unsigned int dequeue(Queue* q)
{
    if (isEmptyQueue(q))
    {
        printf("Cannot dequeue an empty queue!");
        return 0;
    }
    int int_temp = q->head->data;
    intNode* node_temp = q->head;
    q->head = q->head->next;
    free(node_temp);
    return int_temp;
}

int isEmptyQueue(const Queue* q)
{
    int x = 0;
    if(q->head==NULL && q->tail==NULL)
        x = 1;
    return x;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
    intNode* temp = (intNode*)malloc(sizeof(intNode));
    temp = q->tail;
    while (q->head != temp){
        enqueue(q, dequeue(q));
    }
}

void cutAndReplace(Queue* q)
{
    int count = 0,sum = 0;
    int* num;
    intNode* temp = (intNode*)malloc(sizeof(intNode));
    temp = q->head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    if (count %2) {
        enqueue(q, sum/count);
        count++;
    }
    for (int i = 0; i < count/2; i++) {
        enqueue(q, dequeue(q));
    }
    num = (int*)calloc(sizeof(int), count/2);
    
    for (int i = 0; i < count/2; i++) {
        num[i] = dequeue(q);
    }
    for (int i = count/2 - 1; i >= 0; i--) {
        enqueue(q, num[i]);
    }
    for (int i = 0; i < count/2; i++) {
        enqueue(q, dequeue(q));
    }
}

void sortKidsFirst(Queue* q)
{
    intNode* temp_Node = (intNode*)malloc(sizeof(intNode));
    Queue* temp = (Queue*)malloc(sizeof(Queue));
   
    while(sizeof(temp) <= sizeof(q)){
        temp->head = q->tail;
        temp_Node->data = q->head->data;
    while (q->head != temp->head) {
        enqueue(q, dequeue(q));
        if (q->head->data <= temp_Node->data) {
            temp_Node->data = q->head->data;
        }
    }
    enqueue(temp, temp_Node->data);
    }}
