#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"list.h"

int main(int argc, char const *argv[])
{
    Estrutura * lista;
    lista = createList();

    int32_t value;
    int32_t size = 0;

    char check;
    while(check != '\n'){
        scanf("%d", &value);
        addEstructure(value, lista);
        ++size;
        check = getchar();
    }

    int32_t data = 0;
    for(int32_t i=0; i<size; i++){
        data = removeEstructure(lista);
        if((i+1 == size)) printf("%d", data);
        else printf("%d ", data);
    }
    printf("\n");

    free(lista);
    return 0;
}
