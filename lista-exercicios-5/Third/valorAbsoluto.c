#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include"stack.h"

int32_t maxValueStack(Stack * stackProx, int32_t maxValue) {
    if(!stackProx->prox) return maxValue;
    Stack * proximo = stackProx->prox;
    if(maxValue < proximo->value) maxValue = proximo->value;
    return maxValueStack(proximo, maxValue);
}

int32_t minValueStack(Stack * stackProx, int32_t minValue) {
    if(!stackProx->prox) return minValue;
    Stack * proximo = stackProx->prox;
    if(minValue > proximo->value) minValue = proximo->value;
    return minValueStack(proximo, minValue);
}

void wordsControl(char * word, Stack * stack){
    char * push = "push";
    char * pop = "pop";
    char * abs = "abs";

    int32_t pushValue = strcmp(push, word); 
    int32_t popValue = strcmp(pop, word);  
    int32_t absValue = strcmp(abs, word);

    int32_t value = 0;
    if(!pushValue){
        scanf("%d", &value);
        getchar();
        stackPush(value, stack);
    }
    if(!popValue){
        if(!stack->prox) {return;}
        else {
            int32_t topStack = 0;
            topStack = stackPull(stack);
            printf("%d\n", topStack);
        }
    }
    if(!absValue){
        if(!stack->prox) {return;}
        else{
            int32_t minValue = stack->prox->value;
            int32_t maxValue = stack->prox->value;
            minValue = minValueStack(stack->prox, minValue);
            maxValue = maxValueStack(stack->prox, maxValue);
            
            int32_t result = (maxValue - minValue);
            printf("%d\n", result);
        }
    }

}

void stackFunction(Stack * stack){    
    char word[7];
    while(scanf("%s", word) != EOF){
        getchar();
        wordsControl(word, stack);
    }
}

int main(int argc, char const *argv[])
{
    Stack * stack;
    stack = createStack();

    stackFunction(stack);

    freeStack(stack->prox);
    free(stack);
    return 0;
}
