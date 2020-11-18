#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"list.h"

int main(int argc, char const *argv[])
{
    Estrutura * lista1 = createList();
    Estrutura * lista2 = createList();
    int32_t N = 0;
    int32_t value = 0;

    scanf("%d", &N);
    getchar();

    for(int32_t i=0; i<N; i++){
        scanf("%d", &value);
        getchar();
        addEstructure(value, lista1);
    }
    for(int32_t i=0; i<N; i++){
        scanf("%d", &value);
        getchar();
        addEstructure(value, lista2);
    }
    
    N = (N*2);
    int32_t data[N];
    int32_t i = N;
    while(i){
        if((i%2)){
             data[i-1] = removeEstructure(lista1);
        }else{
            data[i-1] = removeEstructure(lista2);
        }
        --i;
    }
    
    for(i=0;i<N;i++) printf("%d\n", data[i]);


    free(lista1);
    free(lista2);
    return 0;
}
