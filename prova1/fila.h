#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct Fila {
    int32_t value;
    struct Fila *prox;
}Fila;

Fila * createFila() {
    Fila * pHead;
    pHead = (Fila *) malloc(sizeof(Fila));
        pHead->value=0;
        pHead->prox=pHead;
    return pHead;
}       

/**
 * This function creates a new cell and put the parameter value in the head cell
 * and his referency is now the new created cell.
*/
Fila * addFila(int32_t value, Fila * pHead) {
    Fila * newCell;
    newCell = (Fila *)malloc(sizeof(Fila));
        newCell->prox = NULL;
        newCell->value = 0;
        
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

void printFila(Fila * pHead) {
    if( pHead->prox->value == pHead->value ) {printf("\n"); return;}
    else printf("%d ", pHead->value);
    return printFila(pHead->prox); 
}

int32_t checkFila(Fila * pHead) {
    if(pHead->prox->value == pHead->value) return 0;
    else return 1;
}

void removeAllFila(Fila * fila){
    if(fila->prox == fila) return;
    Fila * proximo = fila->prox;
    while(proximo != fila){
        fila->prox = proximo->prox;
        free(proximo);
        proximo = fila->prox;
    }
}

