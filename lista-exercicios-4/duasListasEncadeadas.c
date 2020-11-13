#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "list.h"

/**
 * Ask and insert the values choosen by user for estructure A.
**/
void insertA(int32_t N,Estrutura *a) {
    int32_t roundValue = 0;
    int32_t counter = 0;
    for(counter; counter<N; counter++){
        scanf("%d", &roundValue);
        // getchar();
        addEstructure(roundValue, a);
    }
}

/**
 * Ask and insert the values choosen by user for estructure B.
**/
void insertB(int32_t N,Estrutura *b) {
    int32_t roundValue = 0;
    int32_t counter = 0;
    for(counter; counter<N; counter++){
        scanf("%d", &roundValue);
        // getchar();
        addEstructure(roundValue, b);
    }
}

/**
 * this function search if any cell of list B is equal of another cell in A list.
**/
int32_t searchEstructureA(Estrutura *a, Estrutura *b, Estrutura *auxB) {
    if(!a->prox) return 0;
    if(!b->prox && !a->prox) return 0;
    if(!b->prox){
        b = auxB;
        a=a->prox;
    }
    if(b->num == a->num) return 1;
    else searchEstructureA(a, b->prox, auxB);   
}

void isIncluded(Estrutura *a, Estrutura *b){
    int32_t sizeA = sizeList(a->prox, 0);
    int32_t sizeB = sizeList(b->prox, 0);

    if(sizeA>sizeB){
        int32_t check = 0;
        check = searchEstructureA(a->prox,b->prox,b->prox);
        if(check){
            printf("%d\n", check);
            return;
        }else{
            printf("%d\n", check);
            return;
        }
    }else{
        int32_t check = 0;
        printf("%d\n", check);
        return;
    }
}

int main(int argc, char const *argv[])
{
    Estrutura *a;
        a = malloc(sizeof(Estrutura));
        a->num = 0;
        a->prox = NULL;    
    Estrutura *b;
        b = malloc(sizeof(Estrutura));
        b->num = 0;
        b->prox = NULL;     

    int32_t N = 0;    
    scanf("%d", &N);
    getchar();
    insertA(N, a);

    N = 0;    
    scanf("%d", &N);
    getchar();
    insertB(N, b);

    isIncluded(a,b);

    free(a);
    free(b);
    return 0;
}
