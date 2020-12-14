#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Table{
    int32_t key;
    int32_t quantity;
    struct Table * lastCellTable;

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
        table->lastCellTable = NULL;
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

// addTable() Variation
// Always pass at 2 param the last list of table cell.
Table * putAndGetNewTable(int32_t key, Table *tbLast) {
    Table *nova;
    nova = (Table *) malloc(sizeof(Table));

    nova->key = key;
    nova->prox = tbLast->prox;
    tbLast->prox = nova;

    return nova;
}

// ----------------------------------

int32_t generateHash(int32_t value, int32_t M) {
    int32_t hx = (value % M);
    
    return hx;  
}

void addToHashTable(int32_t hash_code, int32_t key, Table ** hash_table, int32_t M) {
    if(!hash_table[hash_code]){
        Table * table = createTable();

        hash_table[hash_code] = table;

        putAndGetNewTable(key, table);

        table->quantity+=1;

    }else{
        Table * roundTable = hash_table[hash_code];

        addTable(key, roundTable);

        roundTable->quantity+=1;

    }
}

//addToHashTableV2() Variation
void addToHashTableV2(int32_t key, Table ** hash_table, int32_t M) {
    Table * lastCell;
    int32_t hash_code = (key % M);
    
    if(!hash_table[hash_code]){
        Table * table = createTable();  

        hash_table[hash_code] = table;
        
        lastCell = putAndGetNewTable(key, table);

        table->quantity+=1;
        table->lastCellTable = lastCell;

    }else{
        
        Table * table = hash_table[hash_code];

        lastCell = table->lastCellTable;

        lastCell = putAndGetNewTable(key, lastCell);

        table->quantity+=1;
        table->lastCellTable = lastCell;


    }
}
//----------------------------------

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

    //loop variables

    Table * lastCellTable = NULL;
    int32_t key = 0;
    int32_t hash_code = 0;
    char stop = 's';
    while (stop != '\n')
    {
        scanf("%d", &key);
        stop = getchar();

        addToHashTableV2(key, hash_table, M);
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
