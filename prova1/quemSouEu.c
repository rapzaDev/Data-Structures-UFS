#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"fila.h"
#include"stack.h"

Fila * Controller
(
    int32_t control, 
    Stack * stack, 
    int32_t *stackControl,
    Fila * fila,
    int32_t *filaControl
) {
    
    int32_t value = 0;
    int32_t stackValue = 0;
    int32_t filaValue = 0;

    scanf("%d", &value);

    if(control == 1){
        fila = addFila(value, fila);
        stackPush(value, stack);
    }else{
        filaValue = removeFila(fila);
        stackValue = stackPull(stack);

        if(filaValue != value) filaControl[0] = 0;
        if(stackValue != value) stackControl[0] = 0;    

    }

    return fila;
}

Fila * operations(Stack * stack, Fila * fila, int32_t counterCases) {
    int32_t qtOperations = 0;

    scanf("%d", &qtOperations);
    getchar();

    int32_t control = 0;
    int32_t *stackControl;
    stackControl = (int32_t *) malloc(sizeof(int32_t));
    stackControl[0] = 1;

    int32_t *filaControl;
    filaControl = (int32_t *) malloc(sizeof(int32_t));
    filaControl[0] = 1;

    while (qtOperations)
    {        
        scanf("%d", &control);
        getchar();
        
        fila = Controller(control, stack, stackControl, fila, filaControl);

        --qtOperations;
    }

    if(stackControl[0] == 1 && filaControl[0] == 1) {
        printf("caso %d: ambas\n", counterCases);
    }else{
        if(stackControl[0] == 1) printf("caso %d: pilha\n", counterCases);
        if(filaControl[0] == 1) printf("caso %d: fila\n", counterCases);
    }
    if(stackControl[0] == 0 && filaControl[0] == 0)printf("caso %d: nenhuma\n", counterCases);

    removeAllStack(stack);
    removeAllFila(fila);

    return fila;
    
}

void whoAmI(Stack * stack, Fila * fila) {
    int32_t cases = 0;
    int32_t counterCases = 1;

    scanf("%d", &cases);
    getchar();

    while (cases)
    {
       fila = operations(stack, fila, counterCases);

       ++counterCases;
 
        --cases;
    }
    
}

int main(int argc, char const *argv[])
{
    Stack * stack;
    stack = createStack();
    
    Fila * fila;
    fila = createFila();

    whoAmI(stack, fila);

    return 0;
}
