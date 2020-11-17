#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../modules/fila.h"
#include"../modules/stack.h"



void dataOutput(Fila * pHead1, Fila * pHead2, Stack * dataHead, int32_t k) {
    if(!dataHead->prox) return; 
    int32_t dataSize = dataHead->prox->value;
    int32_t data[dataSize];
    stackPull(dataHead);
    
    int32_t counterH2 = dataHead->prox->value;
    stackPull(dataHead);
    int32_t counterH1 = dataHead->prox->value;
    stackPull(dataHead);
    int32_t counterTotal = (counterH1 + counterH2);

    // int32_t auxDataSizeH2 = (dataSize - counterH2);
    int32_t check=0;
    for(int32_t i=0; i<counterTotal; i++){
        if(k==2){
            if(!(i%2)){
                check=checkFila(pHead1);
                if(check){
                    data[i] = removeFila(pHead1);
                }else{
                    check=checkFila(pHead2);
                    if(check){
                        data[i] = removeFila(pHead2);
                    }
                }
                check=0;
            }else{
                check=checkFila(pHead2);
                if(check){
                    data[i] = removeFila(pHead2);
                }else{
                    check=checkFila(pHead1);
                    if(check){
                        data[i] = removeFila(pHead1);
                    }
                }
                check=0;
            }
        }else{
            if((i%2)!=0){
                check=checkFila(pHead1);
                if(check){
                    data[i] = removeFila(pHead1);
                }else{
                    check=checkFila(pHead2);
                    if(check){
                        data[i] = removeFila(pHead2);
                    }
                }
                check=0;
            }else{
                check=checkFila(pHead2);
                if(check){
                    data[i] = removeFila(pHead2);
                }else{
                    check=checkFila(pHead1);
                    if(check){
                        data[i] = removeFila(pHead1);
                    }
                }
                check=0;
            }
        }
    }

    for(int32_t i=0; i<dataSize;i++){
        printf("%d\n", data[i]);
    }
    
    return;
}

void dataInput(Fila * pHead1, Fila * pHead2){

    int32_t n = 0;
    int32_t m = 0;
    int32_t k = 0;
    int32_t value = 0;
    int32_t counter=0;
    Stack * dataHead;
    dataHead = createStack();

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    getchar();

    value=0;
    for(int32_t i=0;i<n;i++) {
        scanf("%d", &value);
        getchar();

        pHead1 = addFila(value, pHead1);
        ++counter;
    }
    stackPush(counter, dataHead);

    int32_t counterAux = 0;
    value = 0;
    for(int32_t i=0;i<m;i++) {
        scanf("%d", &value);
        getchar();

        pHead2 = addFila(value, pHead2);
        ++counter;
        ++counterAux;
    }
    stackPush(counterAux, dataHead);

    stackPush(counter, dataHead);

    dataOutput(pHead1, pHead2, dataHead, k);
}

/*
    Always after using addFila function, have to update pHead pointer.
    pHead = addFila(value: Number, pHead: Fila *);
*/
int main(int argc, char const *argv[])
{
    Fila * pHead1;
    Fila * pHead2;
    pHead1 = createFila();
    pHead2 = createFila();

    dataInput(pHead1, pHead2);

    return 0;
}
