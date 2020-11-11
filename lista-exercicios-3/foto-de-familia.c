#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void quickSort(double* correctFotosHeight, int32_t first, int32_t last ) {
    int32_t i, j, pivo;
    double temp;

    if(first<last){
        pivo=first;
        i=first;
        j=last;

        while(i<j){
            while( (correctFotosHeight[i]<=correctFotosHeight[pivo]) && i<last)
                i++;
            while(correctFotosHeight[j]>correctFotosHeight[pivo])
                j--;
            if(i<j){
                temp = correctFotosHeight[i];
                correctFotosHeight[i]=correctFotosHeight[j];
                correctFotosHeight[j]=temp;
            }
        }


        temp = correctFotosHeight[pivo];
        correctFotosHeight[pivo] = correctFotosHeight[j];
        correctFotosHeight[j] = temp;
        quickSort(correctFotosHeight,first,j-1);
        quickSort(correctFotosHeight,j+1,last);
    }
}

void fotosHeight(double *alturas) {
    double correctFotosHeight[4];

    for(int32_t i=0; i<4; i++) correctFotosHeight[i] = alturas[i];

    int32_t first = 0;
    int32_t last = (4-1);
    quickSort(correctFotosHeight, first, last);

    double temp;
    // first array change
        temp = correctFotosHeight[1];
        correctFotosHeight[1] = correctFotosHeight[2];
        correctFotosHeight[2] = temp;
    //second change
        temp = correctFotosHeight[2];
        correctFotosHeight[2] = correctFotosHeight[3];
        correctFotosHeight[3] = temp;
    
    for(int32_t i=0; i<4; i++) printf("%.2f\n", correctFotosHeight[i]);

}

int main(int argc, char const *argv[])
{
    double alturas[4];
    double altura;


    for(int32_t i=0; i<4; i++){
        scanf("%lf", &altura);
        alturas[i] = altura;
        getchar();
    }
    
    fotosHeight(alturas);
    
    return 0;
}
