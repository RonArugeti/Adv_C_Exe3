#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
    charNode* temp = (charNode*)malloc(sizeof(charNode));
    s->head = temp;
    s->head = NULL;
}

void destroyStack(Stack* s)
{
    charNode* toDestroy = s->head;
    charNode* next;
    if (s->head == NULL)
    {
        printf("list is empty");
        return;
    }
    while (toDestroy != NULL)
    {
        next = toDestroy->next;
        free(toDestroy);
        toDestroy = next;
    }

    s->head = NULL;//update list
}

void push(Stack* s, char data)
{
    charNode* newnode = (charNode*)malloc(sizeof(charNode));
    if (newnode == NULL){ printf("push: memory allocation problem\n"); exit(1);}
    newnode->data = data;
    newnode->next = s->head;
    s->head = newnode;
}

char pop(Stack* s)
{
    charNode* temp = s->head;
    char item;
    if (isEmptyStack(s)) {
        printf("STACK IS EMPTY\n");
        return '\0';
    }
    item = s->head->data;
    s->head = s->head->next;
    free(temp);
    return item;
}

int isEmptyStack(const Stack* s)
{
    int x = 0;
    if(s->head == NULL)
        x = 1;
    return x;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
  Stack* temp = (Stack*)malloc(sizeof(Stack));
    while (sentence != NULL) {
    while (*sentence != '#') {
        printf("%c",*(sentence));
        sentence++;
    }
  sentence++;
    
  while (*sentence != '#') {
      push(temp, *(sentence));
      sentence++;
    }
        sentence++;
    while (!isEmptyStack(temp)) {
        printf("%c",pop(temp));
    }
    }
}

int isPalindrome(Stack* s)
{
    char str1[SIZE], str2[SIZE];
    int i = 0;
    while (s->head->next != NULL) {
        str1[i] = pop(s);
        i++;
    }
    i--;
    for (int j = 0; i >= 0; i--) {
        str2[i] = str1[j];
        j++;
    }
    return !(int)strcmp(str2, str1);
}

void rotateStack(Stack* s, int n)
{
    Stack* temp1 = (Stack*)malloc(sizeof(Stack));
    Stack* temp2 = (Stack*)malloc(sizeof(Stack));
    if (n < 0) return;
    
    while (!isEmptyStack(s)) {
        push(temp1, pop(s));
    }
    for (int i = 0; i < n; i++) {
        push(temp2, pop(temp1));
    }
    while (!isEmptyStack(temp1)){
        push(s, pop(temp1));
    }
    for (int i = 0; i < n; i++) {
        push(s, pop(temp2));
    }
}

