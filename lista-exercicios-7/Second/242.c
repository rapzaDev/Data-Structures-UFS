#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Table{
    int32_t key;
    int32_t quantity;
    struct Table * prox;
}Table;

Table ** createHashTable(int32_t M) {
    Table ** ht;
    ht = (Table **) malloc(M * sizeof(Table));

    return ht;
}

Table * createTable() {
    Table * table;
    table = (Table *) malloc(sizeof(Table));
        table->key = 0;
        table->quantity = 0;
        table->prox = NULL;

    return table;
}

void addTable(int32_t key, Table *tb) {
    while (tb->prox)
    {
        tb = tb->prox;
    }
    
    Table *nova;
    nova = (Table *) malloc(sizeof(Table));

    nova->key = key;
    nova->prox = tb->prox;
    tb->prox = nova;
}

int32_t generateHash(int32_t value, int32_t M) {
    int32_t hx = (value % M);
    
    return hx;  
}

void addToHashTable(int32_t hash_code, int32_t key, Table ** hash_table, int32_t M) {
    if(!hash_table[hash_code]){
        Table * newTable = createTable();

        hash_table[hash_code] = newTable;

        addTable(key, newTable);

        newTable->quantity+=1;

    }else{
        Table * roundTable = hash_table[hash_code];

        addTable(key, roundTable);

        roundTable->quantity+=1;

    }
}

void hashFunction() {

    //base cases
    int32_t M = 0;
    scanf("%d", &M);
    getchar();

    //number of hash code's
    int32_t C = 0;
    scanf("%d", &C);
    getchar();

    //create hashTable

    Table ** hash_table;
    hash_table = createHashTable(M);

    //key extractor

    int32_t key = 0;
    int32_t hash_code = 0;
    char stop = 's';
    while (stop != '\n')
    {
        scanf("%d", &key);
        stop = getchar();

        hash_code = generateHash(key, M);

        addToHashTable(hash_code, key, hash_table, M);
    } 
    
    //data helper
    Table * data_helper;

    //loop for print data
    for (int32_t i = 0; i < M; i++)
    {
        data_helper = hash_table[i];   

        if(!hash_table[i]) {
                                                
            printf("%d -> \\", i);
            printf("\n");
            free(hash_table[i]);

        }else{                                                                                          
            
            data_helper = data_helper->prox;   

            printf("%d -> ", i);  
            while (data_helper->prox)
            {
                printf("%d -> ", data_helper->key);
                data_helper = data_helper->prox;
            }
            printf("%d -> \\", data_helper->key);
            printf("\n");
            
            free(hash_table[i]);
        }
    }

}

int main(int argc, char const *argv[])
{
    //number of rounds
    int32_t N = 0;
    scanf("%d", &N);
    getchar();

    while(N){
        hashFunction();
        --N;
    }


    return 0;
}
