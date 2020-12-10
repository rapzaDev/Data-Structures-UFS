#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"..//binarySearch.h"

/*
    Usar um outro array, para quando eu mudar tudo em um
    o outro ainda esteja  do mesmo jeito 
*/

typedef struct dataInfo{
    double value;
    int32_t oldIndex;
}dataInfo;

dataInfo * generateA101() {
    dataInfo * a101;
    a101 = (dataInfo *) malloc(sizeof(dataInfo) * 101);

    return  a101;
}

void quickSort(dataInfo * array, int32_t firstIndex, int32_t lastIndex) {
  
    int32_t i, j, pivo;
    // float tempValue;
    dataInfo dataTemp;

    if(firstIndex<lastIndex){
        pivo=firstIndex;
        i=firstIndex;
        j=lastIndex;

        while(i<j){
            while( (array[i].value<=array[pivo].value) && i<lastIndex)
                i++;
            while(array[j].value>array[pivo].value)
                j--;
            if(i<j){
                
                //value changing
                dataTemp = array[i];
                array[i] = array[j];
                array[j] = dataTemp;
                
            }
        }

        //value changing
        dataTemp = array[pivo];
        array[pivo] = array[j];
        array[j] = dataTemp;

        //recursion
        quickSort(array,firstIndex,j-1);
        quickSort(array,j+1,lastIndex);
    }   

}

void fillArray101( dataInfo * a101 ) { 
    
    double value;

    printf("Digite a sequencia de numero:\n");
    for(int32_t i=0; i<101; i++){
        scanf("%lf", &value);
        getchar();

        printf("%f\n", value);
        a101[i].value = value;
        a101[i].oldIndex = i;
        //agora a posição i do array desorganizado tem o valor e o aintigo indice dele no lugar certos.
    }

}

int32_t binarySearch(float value, float markedCell, int32_t quantity, dataInfo * array) {
    int32_t left = -1, mid = 0; 
    int32_t right = quantity;

    while(left < right-1){

      mid = (left + right)/2;

      if(value == array[mid].value) {

        array[mid].value = markedCell;

        return mid;
      }

      if (value > array[mid].value) left = mid;
      else right = mid;
    }

    if(value != array[mid].value) mid = -1;
    
    return mid;
}


void the101s() {
    
    dataInfo * a101 = generateA101();

    fillArray101(a101); 

    float markedValue = a101[100].value;


    // this part of the function helps me to set a logic checkpoint
        quickSort(a101, 0, 100);

        float markedCell = a101[0].value;
        if(!markedCell) markedCell = -1;
        else markedCell = (markedCell-1);
    //-------------------------------------------------------------

    int32_t oldIndex = 0;
    int32_t index = binarySearch(markedValue, markedCell, 101, a101);

    printf("Indice no qual o numero desejado aparece:\n");
    while(index != -1){

        oldIndex = a101[index].oldIndex;
        
        quickSort(a101, 0, 100);
    
        printf("%d\n", oldIndex);

        index = binarySearch(markedValue, markedCell, 101, a101);

    }

}

int main(int argc, char const *argv[])
{
    // the101s();

    float vl = 0;
    scanf("%f", &vl);

    printf("%f\n", vl); 
    
    return 0;
}
