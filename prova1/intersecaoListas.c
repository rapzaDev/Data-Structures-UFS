#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"list.h"

void fillLists(Estrutura * lista1, Estrutura * lista2) {
    int32_t value = 0;
    int32_t contagem = 5;

    while(contagem){
        scanf("%d", &value);
        addEstructure(value, lista1);
        getchar();
        --contagem;
    }

    contagem = 5;
    while(contagem){
        scanf("%d", &value);
        addEstructure(value, lista2);
        getchar();
        --contagem;
    }
}

int32_t pegaMenor(Estrutura * pHeadProx) {
    Estrutura * proximo = pHeadProx->prox;
    int32_t value = 0;

    value = pHeadProx->num;
    while(pHeadProx){
        if(!proximo) break;
        if(value > proximo->num) value = proximo->num;
        pHeadProx = pHeadProx->prox;
        proximo = pHeadProx->prox;
    }

    return value;
}

Estrutura * adicionar(int32_t value, Estrutura * list) {
    Estrutura * nova;
    nova = (Estrutura *) malloc(sizeof(Estrutura));
        nova->num = value;
        nova->prox = list->prox;
    list->prox = nova;
    return nova;
}

void remover(Estrutura * marked, Estrutura * list) {
    if(!marked || !list) return;
    while (1)
    {
        if(list->prox == marked){
            list->prox = marked->prox;
            free(marked);
            break;
        }
        list = list->prox;
    }
    
}

Estrutura * compare(Estrutura * lista1, Estrutura * lista2) {
    Estrutura * proximo1 = lista1->prox;
    Estrutura * proximo2 = lista2->prox;
    
    Estrutura * lista3;
    lista3 = createList();


    Estrutura * auxiliar;
    int32_t value = 0;
    while(proximo1){
        value = proximo1->num;
        auxiliar = search(value, lista2);
        if(auxiliar){
            addEstructure(auxiliar->num, lista3);
        }
        proximo1 = proximo1->prox;
    }

    return lista3;
}

void resultante(Estrutura * lista1, Estrutura * lista2) {
    
    Estrutura * lista3;
    lista3 = compare(lista1, lista2);

    if(!lista3->prox){
        printf("VAZIO\n");
        freeList(lista1);
        freeList(lista2);
        return;
    }

    int32_t size = 0;
    size = sizeList(lista3->prox, size);

    Estrutura * final;
    final = createList();
    Estrutura * auxiliar = final;
    Estrutura * marked;

    int32_t value = 0;
    while(lista3->prox){
        value = pegaMenor(lista3->prox);
        marked = search(value, lista3);
        remover(marked, lista3);
        auxiliar = adicionar(value, auxiliar);
    }

    final = final->prox;
    for (int32_t i = 0; i < size; i++)
    {
        printf("%d\n", final->num);
        final = final->prox;
    }
    
    freeList(lista1);
    freeList(lista2);

}

int main(int argc, char const *argv[])
{   
    Estrutura * lista1;
    lista1 = createList();

    Estrutura * lista2;
    lista2 = createList();


    fillLists(lista1, lista2);
    resultante(lista1, lista2);


    free(lista1);
    free(lista2);
    return 0;
}