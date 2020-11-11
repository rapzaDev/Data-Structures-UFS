#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int32_t *Rafael( int32_t *arrayMain, int32_t *array, int32_t numeroDeVariaveis ){
    int32_t arrayRafael[numeroDeVariaveis];
    int32_t i=0;

    for(i; i<numeroDeVariaveis; i++){
        arrayRafael[i] = array[i];
    }

    int32_t resultadoRodada = 0;
    int32_t valor1 = 0;
    int32_t valor2 = 0;
    int32_t indiceMain=0;
    for( i=0; i<numeroDeVariaveis; i++ ){
        valor1 = ( 3 * arrayRafael[i++] );
        valor1 = pow( valor1 , 2 );

        valor2 = arrayRafael[i];
        valor2 = pow( valor2, 2 );

        resultadoRodada = ( valor1 + valor2 );
        arrayMain[indiceMain++] = resultadoRodada;
    }   
    
    return arrayMain;
}

int32_t *Beto( int32_t *arrayMain, int32_t *array, int32_t numeroDeVariaveis ){
    int32_t arrayRafael[numeroDeVariaveis];
    int32_t i=0;

    for(i; i<numeroDeVariaveis; i++){
        arrayRafael[i] = array[i];
    }

    int32_t resultadoRodada = 0;
    int32_t valor1 = 0;
    int32_t valor2 = 0;
    int32_t indiceMain=0;
    for( i=0; i<numeroDeVariaveis; i++ ){
        valor1 = arrayRafael[i++];
        valor1 = ( 2 * pow(valor1 , 2) );

        valor2 = ( 5 * arrayRafael[i] );
        valor2 = pow( valor2, 2 );
            
        resultadoRodada = ( valor1 + valor2 );
        arrayMain[indiceMain++] = resultadoRodada;
    }    
    
    return arrayMain;
}

int32_t *Carlos( int32_t *arrayMain, int32_t *array, int32_t numeroDeVariaveis ){    
    int32_t arrayRafael[numeroDeVariaveis];
    int32_t i=0;

    for(i; i<numeroDeVariaveis; i++){
        arrayRafael[i] = array[i];
    }

    int32_t resultadoRodada = 0;
    int32_t valor1 = 0;
    int32_t valor2 = 0;
    int32_t indiceMain=0;
    for( i=0; i<numeroDeVariaveis; i++ ){
        valor1 = ( (-100 * arrayRafael[i++]) );
        valor2 = pow( arrayRafael[i], 3 );
        resultadoRodada = ( valor1 + valor2 );
        arrayMain[indiceMain++] = resultadoRodada;
    }    
    
    return arrayMain;
}

void mainFunction(
int32_t *rafael, 
int32_t *beto, 
int32_t *carlos, 
int32_t numeroDeCasos
){
    int32_t r=0;
    int32_t b=0;
    int32_t c=0;

    for( int32_t i=0; i<numeroDeCasos; i++ ){
        ((rafael[i]>beto[i]) ? r++ : b++);
        ((rafael[i]>carlos[i]) ? r++ : c++);
        ((beto[i]>carlos[i]) ? b++ : c++);

        if((r>=b && r>=c)) printf("Rafael Ganhou\n");
        if((b>=r && b>=c)) printf("Beto Ganhou\n");
        if((c>=r && c>=b)) printf("Carlos Ganhou\n");

        r=0;
        b=0;
        c=0;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    int32_t numeroCasos = 0;
    int32_t auxNumeroCasos;

    scanf("%d", &numeroCasos);
    int32_t arrayResultadosRafael[numeroCasos];
    int32_t arrayResultadosBeto[numeroCasos];
    int32_t arrayResultadosCarlos[numeroCasos];
    int32_t numeroDeVariaveis=(numeroCasos*2);

    int32_t *arrayCasos = malloc(numeroDeVariaveis*sizeof(int32_t));
    int32_t x = 0;
    int32_t y = 0;
    int32_t contagem=0;
    auxNumeroCasos = numeroCasos;
    while (numeroCasos)
    {
        scanf("%d",&x);
        arrayCasos[contagem++]=x;
        scanf("%d",&y);
        arrayCasos[contagem++]=y;
        --numeroCasos;
    }
    
    mainFunction(
        Rafael(arrayResultadosRafael, arrayCasos, numeroDeVariaveis),
        Beto(arrayResultadosBeto, arrayCasos, numeroDeVariaveis),
        Carlos(arrayResultadosCarlos, arrayCasos, numeroDeVariaveis),
        auxNumeroCasos
    );

    free(arrayCasos);
        

    return 0;
}
