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
            --i, --j;   
        if (i < 0) ++ocorrs;
        if (i == m) k += 1;
        else k += m - jump[i+1];
    }

    return ocorrs;
}

void execute () {
    char * vetA, *vetB;
    int sizeVet = 1000000;
    vetA = (char *) malloc( sizeVet * sizeof(char) );
    vetB = (char *) malloc( sizeVet * sizeof(char) );
    
    gets(vetB);
    gets(vetA);

    int n = 0;
    while (vetB[n] != '\000') ++n;
    
    int m = 0;
    while (vetA[m] != '\000') ++m;

    --n;
    --m;

    int counter = boyermoore2(vetA, vetB, m, n);

    printf("%d\n", counter);

}

int main(int argc, char const *argv[])
{
    
    execute();

    return 0;
}
