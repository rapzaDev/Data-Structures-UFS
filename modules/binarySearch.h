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

int32_t binarySearchIndex(int32_t value, int32_t quantity, int32_t * array) {
    int32_t left = 0, right = (quantity -1);

    int32_t mid = 0;
    mid = (left + right)/2;
    
    while(value != array[mid]){
      mid = (left + right)/2;

      if (value > array[mid]) left = mid + 1;
      else right = mid - 1;
    }
    
    return mid;
}