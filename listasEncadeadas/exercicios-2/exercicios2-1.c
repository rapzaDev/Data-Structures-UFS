#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"list.c"

int main(int argc, char const *argv[])
{
    Estrutura *le;
    le = malloc(sizeof(Estrutura));
        le->num = 0;
        le->prox = NULL;
    

    return 0;
}
