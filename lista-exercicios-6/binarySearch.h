#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// int32_t binarySearch(int32_t value, int32_t n, int32_t * array) {
//     int32_t left = -1, right = n;

//     int32_t m = 0;
//     while (left < right-1) {  
      
//       m = (left + right)/2;

//       if (array[m] < value) left = m;
//       else right = m; 
      
//     }

//    return right;
// }

/*
* This function searches along the array an specify value. If find it, returns
the matching array index, else returns -1. 
*/


int32_t binarySearchIndexInt(int32_t value, int32_t quantity, int32_t * array) {
    int32_t left = -1, mid = 0; 
    int32_t right = quantity;

    while(left < right-1){

      mid = (left + right)/2;

      if(value == array[mid]) break;

      if (value > array[mid]) left = mid;
      else right = mid;
    }

    if(value != array[mid]) mid = -1;
    
    return mid;
}

int32_t binarySearchIndexFloat(float value, int32_t quantity, float * array) {
    int32_t left = -1, mid = 0; 
    int32_t right = quantity;

    while(left < right-1){

      mid = (left + right)/2;

      if(value == array[mid]) break;

      if (value > array[mid]) left = mid;
      else right = mid;
    }

    if(value != array[mid]) mid = -1;
    
    return mid;
}

void quickSortInt(int32_t * array, int32_t firstIndex, int32_t lastIndex) {
  
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
        quickSortInt(array,firstIndex,j-1);
        quickSortInt(array,j+1,lastIndex);
    }   

}

void quickSortFloat(float * array, int32_t firstIndex, int32_t lastIndex) {
    int32_t i, j, pivo;
    float temp;

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
        quickSortFloat(array,firstIndex,j-1);
        quickSortFloat(array,j+1,lastIndex);
    }   

}