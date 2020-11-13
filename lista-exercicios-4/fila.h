#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct Fila {
    int32_t value;
    struct Fila *prox;
}Fila;

/**
 * This function creates a new cell and put the parameter value in the head cell
 * and his referency is now the new created cell.
*/
Fila * addFila(int32_t value, Fila * pHead) {
    Fila * newCell;
    newCell = (Fila *)malloc(sizeof(Fila));
    newCell->prox = pHead->prox;
    pHead->prox = newCell;
    pHead->value = value;
    return newCell;
}

int32_t removeFila(Fila * pHead) {
    int32_t value=0;
    Fila * markedCell;
        markedCell = pHead->prox;
        value = markedCell->value;
    pHead->prox = markedCell->prox;

    free(markedCell);
    return value;
}

void printFila(Fila * pHeadProx) {
    if(!pHeadProx->value) return;
    printf("%d ", pHeadProx->value);
    printFila(pHeadProx->prox);
}