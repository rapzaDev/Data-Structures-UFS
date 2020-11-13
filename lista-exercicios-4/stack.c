#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"stack.h"

void solutionP() {
    Stack *pHead;
    pHead = createStack();

    char comando[11];
    int32_t value=0;

    char * Empilhar="Empilhar";
    char * Finalizar="Finalizar";
    char * Desempilhar="Desempilhar";
    char * Imprimir="Imprimir";

    int32_t check = 1;
    int32_t emp = 1;
    int32_t desemp = 1;
    int32_t imp = 1;
    while (check)
    {
        scanf("%s", comando);
        check = strcmp(comando,Finalizar);
        if(!check){
            freeAll(pHead);
            return;
        } 

        emp = strcmp(comando,Empilhar);
        desemp = strcmp(comando,Desempilhar);
        imp = strcmp(comando,Imprimir);

        if(imp && desemp){
            scanf("%d", &value);
            getchar();
        }

        if(!emp){
            stackPush(value,pHead);
        }
        if(!desemp){
            stackPull(pHead);
        }
        if(!imp){
            stackPrint(pHead->prox);
        }

    }
    
}

int main(int argc, char const *argv[])
{
    solutionP();
   
    return 0;
}
