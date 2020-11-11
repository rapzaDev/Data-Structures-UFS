#include <stdio.h>
#include <stdlib.h>

void allUppercase(char *name){
   while ((name=getchar()) != EOF) printf("%c", toupper(name));
   printf("\n");
}

int main (void){
    char name[100];

    allUppercase(name);
    
    return 0;
}