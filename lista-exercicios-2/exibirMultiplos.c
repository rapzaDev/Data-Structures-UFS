#include<stdio.h>
#include<stdlib.h>

void valoresMultiplos(int *valores) {
    int i = valores[0];
    int f = valores[1];
    int terceiroValor = valores[2];

    int indice=0;

    int menor = (i<f ? i : f);
    int maior = (i>f ? i : f);

    int atual=menor;

    for(atual; atual<=maior; atual++){
        if(!(atual%terceiroValor)){
            ++indice;
        }
    }

    int *novosValores = malloc(indice*sizeof(int));

    atual=menor;
    indice=0;

    for(atual; atual<=maior; atual++){
        if(!(atual%terceiroValor)){
            novosValores[indice]=atual;
            printf("%d\n",novosValores[indice]);
            ++indice;
        }
    }
    
}

int main(void){
    int *valores = malloc(3*sizeof(int));
    int i=0;
    int valor=0;

    for (i; i<3; i++){
        scanf("%d", &valor);
        valores[i]=valor;
    }

    valoresMultiplos(valores);

    free(valores);
    return 0;
}

