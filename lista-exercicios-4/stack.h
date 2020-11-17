#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/**
 * Creates an instancy of stack cell.
**/
typedef struct Pilha {
    int32_t value;
    struct Pilha *prox;
}Stack;

/**
 * Creates the head stack cell and returns it.
**/
Stack * createStack() {
    Stack *pHead;
    pHead =(Stack*) malloc(sizeof(Stack));
        pHead->value=0;
        pHead->prox=NULL;
    return pHead;
}

/**
 * Stack another cell whit the value parameter in the Stack ED. 
   The second parameter always be the stack head's pointer.
**/
void stackPush(int32_t value, Stack *pHead) { 
    Stack *newStackCell;
    newStackCell = (Stack*)malloc(sizeof(Stack));
        newStackCell->value=value;
        newStackCell->prox=pHead->prox;
    pHead->prox=newStackCell;
}

/**
 * Pulls the first cell in the head of the Stack an return his value.
**/
int32_t stackPull(Stack *pHead) {
    int32_t value=0;
    Stack *markedStackCell;
        markedStackCell = pHead->prox;
        value = markedStackCell->value;
    pHead->prox=markedStackCell->prox;
    
    free(markedStackCell);
    return value;
}

/**
 * Prints the Stack ED starting by the top of the Stack
**/
void stackPrint(Stack *pHeadProx) {
    if(!pHeadProx) return;
    if(pHeadProx->prox == NULL) printf("%d\n", pHeadProx->value);    
    else printf("%d ", pHeadProx->value);
    stackPrint(pHeadProx->prox);
}

