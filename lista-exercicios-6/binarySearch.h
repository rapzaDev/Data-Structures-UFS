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
int32_t binarySearchIndex(int32_t value, int32_t quantity, int32_t * array) {
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