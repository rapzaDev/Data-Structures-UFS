#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct {
    int32_t number;
    char word;
} Control;

void wordPressQuick(Control* control, int32_t first, int32_t last ) {
    int32_t i, j, pivo;
    Control temp;

    if(first<last){
        pivo=first;
        i=first;
        j=last;

        while(i<j){
            while( (control[i].number<=control[pivo].number) && i<last)
                i++;
            while(control[j].number>control[pivo].number)
                j--;
            if(i<j){
                temp = control[i];
                control[i]=control[j];
                control[j]=temp;
            }
        }


        temp=control[pivo];
        control[pivo] = control[j];
        control[j]=temp;
        wordPressQuick(control,first,j-1);
        wordPressQuick(control,j+1,last);
    }
}

int main(int argc, char const *argv[])
{
    int32_t N;
    int32_t M;
    char letra;

    scanf("%d", &N);
    Control control[N];
    for(int32_t i=0; i<N; i++){
        scanf("%d", &M);
        control[i].number=M;
        getchar();
        scanf("%c", &letra);
        getchar();
        control[i].word=letra;
    }
    
    int32_t first = 0;
    int32_t last = N-1;
    wordPressQuick(control, first, last);

    for(int32_t i=0; i<N; i++){
        printf("%c", control[i].word);
    }   
    printf("dasdasd\n");

    return 0;
}
