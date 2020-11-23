#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include"list.h"

typedef struct Pilha{
    Estrutura * list;
    struct Pilha * prox;
}Stack;

Stack * createStack(){
    Stack * pHead;
    pHead = (Stack *) malloc(sizeof(Stack));
        pHead->list = NULL;
        pHead->prox = NULL;
    return pHead;
}

void stackPush(Stack * pHead, Estrutura * list) {
    Stack * newStackCell;
    newStackCell = (Stack *) malloc(sizeof(Stack));
        newStackCell->list = list;
        newStackCell->prox = pHead->prox;
    pHead->prox = newStackCell;
}

Estrutura * stackPop(Stack * pHead) {
    Estrutura * markedList = NULL;
    Stack * markedStack;
        markedStack = pHead->prox;
        markedList = markedStack->list;
    pHead->prox = markedStack->prox;

    free(markedStack);
    return markedList;
}

Estrutura * adicionar(int32_t value, Estrutura * list) {
    Estrutura * nova;
    nova = (Estrutura *) malloc(sizeof(Estrutura));
        nova->num = value;
        nova->prox = list->prox;
    list->prox = nova;
    return nova;
}

void stackController(char * command, Stack * stack) {
    char * push = "PUSH";
    char * pop = "POP";

    int32_t pushControl = strcmp(push, command);
    int32_t popControl = strcmp(pop, command);

    char control = 'c';
    int32_t value = 0;
    if(!pushControl){
        Estrutura * list;
        list = createList();

        Estrutura * auxiliar = list;
        while(control != '\n'){
            scanf("%d", &value);
            auxiliar = adicionar(value, auxiliar);
            control = getchar();
        }

        stackPush(stack, list);
    }
    if(!popControl){
        if(!stack->prox){
            printf("EMPTY STACK\n");
            return;
        }
        Estrutura * list;
        list = stackPop(stack);
        
        Estrutura * auxiliar = list->prox;

        int32_t size = 0;
        while(auxiliar){
            if(!auxiliar->prox) printf("%d\n", auxiliar->num);
            else printf("%d ", auxiliar->num);
            auxiliar = auxiliar->prox;
            ++size;
        }

        for(int32_t i = 0; i < size ; i++){
            removeEstructure(list);
        }
    }

}

void stackCommands(Stack * stack){
    char check;
    char command[4];
    while(scanf("%s", command) != EOF){
        getchar();
        stackController(command, stack);
    }
}

int main(int argc, char const *argv[])
{
    Stack * stack;
    stack = createStack();

    stackCommands(stack);

    free(stack);
    return 0;
}
