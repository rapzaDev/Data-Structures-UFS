#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

// This functions returns the index of the word in the alfabeto or -1 in fealure case.
int32_t alfabeto(char * value) {

    char alfabeto[26] = {
        'A', 'B', 'C', 'D', 'E', 
        'F', 'G', 'H', 'I', 'J',
        'K', 'L','M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    for(int32_t i=0; i<26; i++) if(alfabeto[i] == value[0]) return i;

    return -1;

}

void hashFunction() {

    int32_t roundValue = 0;

    int32_t charIndex = -1;
    int32_t indexValue = 0;
    int32_t result = 0;
    int32_t hash_code = 0;

    char value[1];
    int32_t testNumbers = 0;
    scanf("%d", &testNumbers);
    getchar();

    for(int32_t i = 0; i < testNumbers; i++){

        while(1){

            value[0] = getchar();
            if(value[0] == '\n') break;

            ++charIndex;

            indexValue = alfabeto(value);

            result = (indexValue + roundValue + charIndex);

            hash_code = hash_code + result;
        }
        
        charIndex = -1;
        indexValue = 0;


        ++roundValue;
    }

    printf("%d\n", hash_code);

}


int main(int argc, char const *argv[])
{
    int32_t numberCases = 0;
    int32_t roundValue = 0; 

    scanf("%d", &numberCases);
    getchar();

    while (numberCases)
    {
        hashFunction(roundValue);

        ++roundValue;
        --numberCases;
    }

   

    return 0;
    
}
