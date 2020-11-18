#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/**
    Estructures's interface
**/
typedef struct Estrutura{
    int32_t num;
    struct Estrutura *prox;
} Estrutura;

Estrutura * createList() {
    Estrutura * pHead;
    pHead = (Estrutura *) malloc(sizeof(Estrutura));
        pHead->num=0;
        pHead->prox=NULL;
    return pHead;
}

/**
    This function adds my new cell in anywhere of the list.
    It always be between the pointer who was called by reference
    and the next pointer in his sequence.
**/
void addEstructure(int32_t value, Estrutura *le) {
    Estrutura *nova;
    nova = (Estrutura*)malloc(sizeof(Estrutura));
    nova->num = value;
    nova->prox = le->prox;
    le->prox = nova;
}

/**
    This function search a especify cell in the list. 
    If the cell doesn't exists, It returns a NULL value.
**/
Estrutura * search(int32_t value, Estrutura *le){
    if(!le) return NULL;
    if(value == le->num) return le;
    else search(value, le->prox);       
}

/**
    This function removes a especify cell in the list. 
**/
int32_t removeEstructure(Estrutura *le) {
    if(!le->prox) return 0;
    Estrutura *markedCell; 
    markedCell = le->prox;
    int32_t value = markedCell->num;
    le->prox = markedCell->prox;
    free(markedCell);
    return value;
}

/**
    This function prints cell by cell of entire struct list recursively.
**/
void printEstructure(Estrutura *le){
    if(le){
        printf("%d\n", le->num);
        printEstructure(le->prox);
    }
}

/**
    This function fills a list of structures passing the values of array
    for the cells values
**/
void fillEstructure(int32_t *array,int32_t counter, Estrutura *le) {
    if(array){
        le->num = array[counter];
        fillEstructure(array, ++counter, le->prox);
    }
}

/**
    This function return the size of the list.
**/
int32_t sizeList(Estrutura *le, int32_t counter) {
    if(!le) return counter;
    ++counter;
    sizeList(le->prox,counter);
}