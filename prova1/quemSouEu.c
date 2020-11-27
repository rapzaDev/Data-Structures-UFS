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
    Stack * Topo;
    int32_t TopoValue = 0;

    int32_t filaValue = 0;
    Fila * Primeiro;
    int32_t PrimeiroValue = 0;

    scanf("%d", &value);
    

    if(control == 1){
        fila = addFila(value, fila);
        stackPush(value, stack);
    }else{
        Topo = stack->prox;
        TopoValue = Topo->value;

        Primeiro = fila->prox;
        PrimeiroValue = Primeiro->value;

        filaValue = removeFila(fila);
        stackValue = stackPull(stack);

        if(filaValue == value){
            filaControl[0] = 1;
        }else{
            filaControl[0] = 0;
        }

        if(stackValue == value){
            stackControl[0] = 1;
        }else{
            stackControl[0] = 0;
        }

    }

    return fila;
}

Fila * operations(
    Stack * stack,
    Fila * fila, 
    int32_t counterCases,
    int32_t * stackControl,
    int32_t * filaControl
) {
    int32_t qtOperations = 0;

    scanf("%d", &qtOperations);
    getchar();

    int32_t control = 0;
    // int32_t *stackControl;
    // stackControl = (int32_t *) malloc(sizeof(int32_t));
    // stackControl[0] = 0;

    // int32_t *filaControl;
    // filaControl = (int32_t *) malloc(sizeof(int32_t));
    // filaControl[0] = 0;

    int32_t counter = 0;
    int32_t adicionar = 0;
    int32_t remover = 0;
    while (qtOperations)
    {
        scanf("%d", &control);
        getchar();
        fila = Controller(control, stack, stackControl, fila, filaControl);
        

        if(control == 1) ++adicionar;    

        if(control == 2){

            // if(stackControl[0] == 1){
            //     if(filaControl[0] ==1){
            //         printf("caso %d: ambas\n", counterCases);
                    
            //     }else{
            //         printf("caso %d: pilha\n", counterCases);
                    
            //     }
            // }else{
            //     if(filaControl[0] == 1){
            //         if(stackControl[0] ==1){
            //             printf("caso %d: ambas\n", counterCases);
                        
            //         }else{
            //             printf("caso %d: fila\n", counterCases);
                        
            //         }
            //     }else{
            //         printf("caso %d: nenhuma\n", counterCases);
                    
            //     }
            // }

            ++remover;
        }

        
        --qtOperations;
    }

    if(adicionar){
        if(!remover) printf("caso %d: ambas\n", counterCases);
    }

    // free(stackControl);
    // free(filaControl);

    removeAllStack(stack);
    removeAllFila(fila);

    return fila;
    
}

void whoAmI(Stack * stack, Fila * fila) {
    int32_t cases = 0;
    int32_t counterCases = 1;

    int32_t *stackControl;
    stackControl = (int32_t *) malloc(sizeof(int32_t));
    

    int32_t *filaControl;
    filaControl = (int32_t *) malloc(sizeof(int32_t));
    // filaControl[0] = 0;

    scanf("%d", &cases);
    getchar();

    while (cases)
    {
       stackControl[0] = 0;
       filaControl[0] = 0;

       fila = operations(stack, fila, counterCases, stackControl, filaControl);

        if(stackControl[0] == 1){
            if(filaControl[0] ==1){
                printf("caso %d: ambas\n", counterCases);
                    
            }else{
                printf("caso %d: pilha\n", counterCases);
                    
            }
        }else{
            if(filaControl[0] == 1){
                if(stackControl[0] ==1){
                    printf("caso %d: ambas\n", counterCases);
                        
                }else{
                    printf("caso %d: fila\n", counterCases);
                        
                }
            }else{
                printf("caso %d: nenhuma\n", counterCases);
            
            }
        }

       ++counterCases;
 
        free(stackControl);
        free(filaControl);

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

    // removeAllFila(fila);
    // removeAllStack(stack);

    // free(stack);
    // free(fila);
    return 0;
}
