#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"list.h"


void invertionList(Estrutura * list, int32_t size) {
    if(!list->prox) return;
    Estrutura * invertedList;
    invertedList = (Estrutura *) malloc(sizeof(Estrutura));

    Estrutura * pHeadProx = list->prox;
    for(int32_t i=0; i < size; i++){
        addEstructure(pHeadProx->num, invertedList);
        pHeadProx = pHeadProx->prox;
        removeEstructure(list);
    }
    list = invertedList;
    pHeadProx = list->prox;
    
    for(int32_t i=0; i < size; i++){
        if((i+1) == size){
            printf("%d\n", pHeadProx->num);
        }else{
            printf("%d ", pHeadProx->num);
            pHeadProx = pHeadProx->prox;
        } 
    }
}

void adicionar(int32_t value, Estrutura * lista) {
    if(lista->prox) return adicionar(value, lista->prox);
    else{
        Estrutura * nova;
        nova = (Estrutura *) malloc(sizeof(Estrutura));
        nova->num = value;
        nova->prox = lista->prox;
        lista->prox = nova;
        return;
    }
}

int main(int argc, char const *argv[])
{
    Estrutura * list;
    list = createList();

    int32_t value;
    int32_t size = 0;

    char check;
    while(check != '\n'){
        scanf("%d", &value);
        adicionar(value, list);
        ++size;
        check = getchar();
    }

    invertionList(list, size);

    for(int32_t i=0; i < size; i++){
        removeEstructure(list);
    }

    free(list);
    return 0;
}
