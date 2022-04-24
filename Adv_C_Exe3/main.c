#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#define SIZE 100

int main()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    initStack(stack);
//    char* str1 = {"He# oll# W#dlro#"};
    
    char str[5];
    str[0] = '1';
    str[1] = '4';
    str[2] = '7';
    str[3] = '9';
    char str2[5] = {"maam"};
    // char str3[6] = {"mrdsd"};
    for (int i = 0; i < 4; i++) {
        push(stack, str[i]);
    }
    rotateStack(stack, 2);
    for (int i = 0; i < 4; i++) {
      printf("%c",pop(stack));
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        push(stack, str2[i]);
    }
    
//    flipBetweenHashes(str1);
    
    if (isPalindrome(stack)) {
        printf("the word is polindrome\n");
    }
    else
    printf("the word is not polindrome\n");
    
    destroyStack(stack);
    
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    
    unsigned int int_str[SIZE];
    
    int_str[0] = 5;
    int_str[1] = 6;
    int_str[2] = 2;
    int_str[3] = 9;

    
    for (int i = 0; i < 4; i++) {
        enqueue(queue,int_str[i]);
    }
    
    unsigned int temp_int;
    rotateQueue(queue);
    for (int i = 0; i < 4; i++) {
        temp_int = dequeue(queue);
        enqueue(queue, temp_int);
        printf("%d\t",temp_int);
    }
    printf("\n");
    cutAndReplace(queue);
    for (int i = 0; i < 4; i++) {
        temp_int = dequeue(queue);
        enqueue(queue, temp_int);
        printf("%d\t",temp_int);
    }
    printf("\n");
    sortKidsFirst(queue);
    
    destroyQueue(queue);

    return 0;
}
