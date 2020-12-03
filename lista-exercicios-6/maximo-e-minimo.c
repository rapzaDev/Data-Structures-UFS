#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"binarySearch.h"

int32_t * generateArray(int32_t value) {
    int32_t * dinamicArray;
    dinamicArray = (int32_t *) malloc( value * sizeof(int32_t));
    
    return dinamicArray;
}

int32_t * freeGeneratedArray( int32_t * array) {
    free(array);
    return NULL;
}

void fillArray(int32_t * array, int32_t quantity) {
    int32_t arrayValue = 0;
    for( int32_t i = 0; i<quantity; i++ ){
        scanf("%d", &arrayValue);
        getchar();
        array[i] = arrayValue;
    }
}

void quickSort(int32_t * array, int32_t firstIndex, int32_t lastIndex) {
    int32_t i, j, pivo;
    int32_t temp;

    if(firstIndex<lastIndex){
        pivo=firstIndex;
        i=firstIndex;
        j=lastIndex;

        while(i<j){
            while( (array[i]<=array[pivo]) && i<lastIndex)
                i++;
            while(array[j]>array[pivo])
                j--;
            if(i<j){
                temp = array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }


        temp=array[pivo];
        array[pivo] = array[j];
        array[j]=temp;
        quickSort(array,firstIndex,j-1);
        quickSort(array,j+1,lastIndex);
    }   

}

int32_t getMaxValue(int32_t * array, int32_t quantity) {
    int32_t maxValue = array[0];

    for(int32_t i = 0; i<quantity; i++){
        if((i+1) == quantity) break;
        if(maxValue < array[i+1]) maxValue = array[i+1];
    } 
    
    return maxValue;
}

int32_t getMinValue(int32_t * array, int32_t quantity) {
    int32_t minValue = array[0];

    for(int32_t i = 0; i<quantity; i++){
        if((i+1) == quantity) break;
        if(minValue > array[i+1]) minValue = array[i+1];
    } 
    
    return minValue;
}


void maxAndMin(int32_t * array, int32_t quantity) {
    int32_t arrayForMax[quantity] , arrayForMin[quantity];

    for(int32_t i=0; i<quantity; i++){
        arrayForMax[i] = array[i]; 
        arrayForMin[i] = array[i];
    }    

    int32_t maxValue = getMaxValue(arrayForMax, quantity);
    int32_t minValue = 0;
    minValue = getMinValue(arrayForMin, quantity);

    int32_t getMaxValueIndex = 0;
    int32_t maxValueCounter = 0;
    
    getMaxValueIndex = binarySearchIndex(maxValue, quantity ,arrayForMax);

    while (getMaxValueIndex != -1)
    {
        ++maxValueCounter;

        if(!minValue) arrayForMax[getMaxValueIndex] = -1;
        else arrayForMax[getMaxValueIndex] = 0;

        quickSort(arrayForMax, 0, (quantity-1));
        
        getMaxValueIndex = binarySearchIndex(maxValue, quantity, arrayForMax);

    }
    printf("Maior: %d apareceu %d vezes\n", maxValue, maxValueCounter);


    int32_t getMinValueIndex = 0;
    int32_t minValueCounter = 0;

    getMinValueIndex = binarySearchIndex(minValue, quantity, arrayForMin);

    while (getMinValueIndex != -1)
    {
        ++minValueCounter;

        if(!minValue) arrayForMin[getMinValueIndex] = -1;
        else arrayForMin[getMinValueIndex] = 0;

        quickSort(arrayForMin, 0, (quantity-1));
        
        getMinValueIndex = binarySearchIndex(minValue, quantity, arrayForMin);

    }
    printf("Menor: %d apareceu %d vezes\n", minValue, minValueCounter);

}

void mainController() {

    int32_t quantity = 0;
    scanf("%d", &quantity);
    getchar();

    int32_t * dinamicArray;
    dinamicArray = generateArray(quantity);

    fillArray(dinamicArray, quantity);

    int32_t firstIndex = 0;
    int32_t lastIndex = (quantity - 1);
    quickSort(dinamicArray, firstIndex, lastIndex);


    maxAndMin(dinamicArray, quantity);

    dinamicArray = freeGeneratedArray(dinamicArray);
}

int main(int argc, char const *argv[])
{
    mainController();

    return 0;
}
