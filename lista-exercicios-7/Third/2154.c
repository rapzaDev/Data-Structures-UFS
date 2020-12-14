#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Table{
    int32_t key;
    int32_t quantity;

    struct Table * ant;
    struct Table * prox;   
}Table;


typedef Table ** HashTable;

Table * createTable(){
    Table *table = (Table *) malloc(sizeof(Table));
        table->key = -1;
        table->quantity = 0;
        table->ant = NULL;
        table->prox = NULL;

    return table;
}

Table ** createHashTable(int32_t M) {
    Table ** ht;
    ht = (Table **) malloc(M * sizeof(Table));

    return ht;
}

//the table head prox pointer always be the new struct data created
Table * addTable(int32_t key, Table * tbDataHead) {
    Table *nova;
    nova = (Table *) malloc(sizeof(Table));
    nova->key = key;


    Table * dataAux = tbDataHead->prox;
    Table * anterior = tbDataHead;

    if(dataAux){
        
        while (nova->key > dataAux->key) {
            anterior = dataAux;
        
            dataAux = dataAux->prox;
            if(!dataAux) break;
        }
        
        if(dataAux) {
            nova->prox = dataAux;
            dataAux->ant = nova;
        }
        else {
            nova->prox = dataAux;
        }

    }
    else {
        nova->prox = dataAux;
    }

    nova->ant = anterior;
    anterior->prox = nova;

    // tbDataHead->quantity += 1;

    return nova;
}

void dropKey(int32_t key, Table ** hashTable, int32_t sizeHashTable) {
    int32_t hash = (key % sizeHashTable);

    Table * table = hashTable[hash];

    if(!table->quantity) return;

    table = table->prox;
    while (table->key != key) {
        table = table->prox;
        if(!table) return;
    }

    Table * bef = table->ant;
    
    Table * prox = NULL;
    if(table->prox) 
    {
        prox = table->prox;
        prox->ant = bef;
    }

    bef->prox = prox;
    
    free(table);

    hashTable[hash]->quantity -= 1;

}

void addToHashTable(Table ** hashTable, int32_t sizeHashTable, int32_t key) {
    int32_t hash = (key % sizeHashTable);

    if(!hashTable[hash]){
        Table * table = createTable();  

        hashTable[hash] = table;
        
        addTable(key, table);

        table->quantity+=1;

    }else{
        Table * table = hashTable[hash];

        addTable(key, table);

        table->quantity+=1;

    }
}

int32_t getHashTableQuantity(Table ** hashTable, int32_t sizeHashTable) {
    int32_t total = 0;

    for(int32_t i=0; i<sizeHashTable; i++) {
        if(hashTable[i]) total += hashTable[i]->quantity;

    }

    return total;
    
}

void searchHashTable(Table ** hashTable, int32_t key, int32_t sizeHashTable) {
    int32_t hash = (key % sizeHashTable);

    Table * pc = hashTable[hash];
 
    if(!pc) {
        printf("elemento nao encontrado!\n");
        printf("numero de elementos acessados na tabela hash: 0\n");
        return;
    }

    int32_t counter = 0;

    pc = pc->prox;
    while (pc) {
        ++counter;

        if(pc->key == key) break;
        pc = pc->prox;
    }
       

        int32_t numberOfKeys = getHashTableQuantity(hashTable, sizeHashTable);

        printf("BUSCA POR %d\n", key);
        printf("numero de elementos da tabela hash: %d\n", numberOfKeys);
        printf("elemento %d encontrado!\n", pc->key);
        printf("numero de elementos acessados na tabela hash: %d\n", counter);
    
}

void printHashTable(Table ** hashTable, int32_t sizeHashTable) {
    Table * table;
    
    printf("imprimindo tabela hash:\n");
    for(int32_t i = 0; i<sizeHashTable; i++){
        table = hashTable[i];

        int32_t value = 0;
        if(table) value = table->quantity;

        if(!value) {
            printf("[%d]:Lista vazia!\n", i);
        }
        else {
            
            table = table->prox;

            printf("[%d]:", i);    
            while(table){
                printf("%d=>", table->key);
                table = table->prox;
            }
            printf("\n");

        }

    }
}


void hashController(Table ** hashTable, int32_t sizeHashTable) {
    char adicao = 'a';
    char remocao = 'r';
    char impressao = 'i';
    char search = 'p';

    char control = 'x';
    
    // if(control == 'i') return;
    // if(control == 'r') return;

    int32_t key = 0;
    while (control)
    {
        scanf("%c", &control);
        getchar();
        if(control == 'f') break;

        if(control == adicao){
            scanf("%d", &key);
            getchar();

            addToHashTable(hashTable, sizeHashTable, key);

        }
        else {

            if(control == remocao){
                scanf("%d", &key);
                getchar();

                dropKey(key, hashTable, sizeHashTable);
            } 
            else    {
                
                if(control == impressao) {
                printHashTable(hashTable,sizeHashTable);

                }else
                {
                    
                    if(control == search) {
                        scanf("%d", &key);
                        getchar();
                        searchHashTable(hashTable, key, sizeHashTable);
                    }

                }
                

            }

        }
        

    }
    

}


int main(int argc, char const *argv[])
{
    int32_t M = 0;
    scanf("%d", &M);
    getchar();

    Table ** hashTable = createHashTable(M);

    hashController(hashTable, M);


    return 0;
}
