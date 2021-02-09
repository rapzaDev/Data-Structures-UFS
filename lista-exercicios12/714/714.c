#include<stdio.h>
#include<stdlib.h>

int boyermoore2 (char * vetA, char * vetB, int m, int n) {
    int *jump = malloc ((m+1) * sizeof (int));

    int h = m, k = m-1;
    
    while (h >= 0 && k >= 0) {
      int i = m, j = k; 
      while (i >= h && j >= 0)
         if (vetA[i] == vetA[j]) --i, --j;
         else i = m, j = --k;
      jump[h--] = k;
    }
    
    while (h >= 0) jump[h--] = k;

    int  ocorrs = 0;
    k = m;

    while (k <= n) {
        int i = m, j = k;

        while (i >= 0 && vetA[i] == vetB[j]) 
            if( vetA[i] == vetB[j]) return j;
            --i, --j;   
        // if (i < 0) ++ocorrs;
        if (i == m) k += 1;
        else k += m - jump[i+1];
    }

    // return ocorrs;
    return -1;
}

int main(int argc, char const *argv[])
{
    
    char * vetB = malloc( 50 * sizeof(char));
    char * vetA = malloc( sizeof(char));

    scanf("%s", vetB);
    scanf("%s", vetA);

    int i = 0;
    while(vetB[i]) ++i; 

    --i;

    int count = boyermoore2(vetA, vetB, 0, i);

    printf("%d\n", count);



    return 0;
}
