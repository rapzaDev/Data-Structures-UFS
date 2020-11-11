#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void quickSort(int32_t* array, int32_t first, int32_t last ) {
    int32_t i, j, pivo;
    double temp;

    if(first<last){
        pivo=first;
        i=first;
        j=last;

        while(i<j){
            while( (array[i]<=array[pivo]) && i<last)
                i++;
            while(array[j]>array[pivo])
                j--;
            if(i<j){
                temp = array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }


        temp = array[pivo];
        array[pivo] = array[j];
        array[j] = temp;
        quickSort(array,first,j-1);
        quickSort(array,j+1,last);
    }
}

void decreaseArrayFunction(int32_t *array, int32_t first, int32_t last) {
    quickSort(array, first, last);

    int32_t counter = last;
    while(!!counter){
        printf("%d ", array[counter]);
        counter--;  
    }
    printf("%d\n", array[counter]);

}

void invertArrayFunction(int32_t *array, int32_t first, int32_t last) {
    int32_t temp;
    int32_t tempForLast = last;
    for(int32_t i = first; i<(last+1); i++){
        if(tempForLast <= i){
            if(i==last) printf("%d\n", array[i]);
            else printf("%d ", array[i]);  
        }else{
            temp = array[i];
            array[i] = array[tempForLast];  
            array[tempForLast--] = temp;
            printf("%d ", array[i]);
        }
    }

}

void turnToLeftFunction(int32_t *array, int32_t first, int32_t last) {
    int32_t tempPrincipal=0;
    int32_t truly = 1;
    int32_t temp;
    int32_t counterFor = last+1;
    int32_t counterLast = last;

    for(counterFor; counterFor>first; counterFor--){
        if((counterLast) >= 0){
            if(truly){
                tempPrincipal = array[counterLast-1];
                array[counterLast-1] = array[counterLast];
                truly=0;
                counterLast--;
            }else{
                if(counterLast == 0){
                    temp = tempPrincipal;
                    array[last] = temp;
                }else{
                    temp = tempPrincipal;
                    tempPrincipal = array[counterLast-1];
                    array[counterLast-1] = temp;
                    counterLast--;
                }
            }
        }
    }

    for(int32_t i=0; i<(last+1) ; i++){
        if(i==last) printf("%d\n", array[i]);
        else printf("%d ", array[i]);
    }
}

int main(int argc, char const *argv[])
{
    int32_t quantidadeNum;

    scanf("%d", &quantidadeNum);
    int32_t invertedArray[quantidadeNum];
    int32_t turnLeftedArray[quantidadeNum];
    int32_t decreasingArray[quantidadeNum];

    int32_t numero;
    for(int32_t i=0; i<quantidadeNum; i++){
        scanf("%d", &numero);
        invertedArray[i] = numero;
        turnLeftedArray[i] = numero;
        decreasingArray[i] = numero;
    }
    
    int32_t first = 0;
    int32_t last = (quantidadeNum - 1);

    invertArrayFunction(invertedArray, first, last);
    turnToLeftFunction(turnLeftedArray, first, last);
    decreaseArrayFunction(decreasingArray, first, last);

    return 0;
}
