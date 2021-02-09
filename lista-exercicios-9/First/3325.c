#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int key;
    struct Lista * prox;
}Lista;

// parametro M = dias de aula
Lista ** create_list (int M) {
    Lista ** lista = (Lista **) malloc( M * sizeof(Lista) );

    return lista;
}

Lista * create_head () {
    Lista * lista = (Lista *) malloc( sizeof(Lista) );
    
    return lista;
}

Lista * add_noh ( Lista * head, int value ) {
    Lista * novo = (Lista *) malloc( sizeof(Lista) );
    
    novo->key = value;
    novo->prox = NULL;

    head->prox = novo;

    return novo;
}


void initialize( int * dir, int * alt , int quantity) {
    for (int v = 0; v < quantity; v++)
    {
        dir[v] = v;
        alt[v] = 0;
    }
}

void Union ( int * dir, int * alt, int r, int s ) {
    if ( alt[r] > alt[s] ) dir[s] = r;
    else dir[r] = s;
    
    if ( alt[r] == alt[s] )
    alt[s] = alt[r] + 1 ;
}

int Find (int v, int * dir) {
    if (v != dir[v])
    {
        int next = dir[v];
        dir[v] = Find( next, dir);
    }
    return dir[v];
}

int componentes(int * dir, int * alt, int n, int arestas) {
    int i = 0; int ch = 0;
    int c = n;

    for ( i = 0; i < arestas; i++)
    {
        int u = dir[ch++];
        int v = dir[ch++];
        int r = Find(u, dir);
        int s = Find(v, dir);

        if (r != s)
        {
            Union(dir, alt, r, s);
            --c;
        }
        

    }
    
    return c;
}


int main(int argc, char const *argv[])
{
    int N = 0; int * dir; int * alt;
    int M = 0;
    int T = 0;
    int target = 0;
    int arestas = 0;
    
    Lista ** lista;
    Lista * auxiliar;

    scanf("%d", &N);
    getchar();

    dir = (int *) malloc ( sizeof (int) * N );
    alt = (int *) malloc ( sizeof (int) * N );

    scanf("%d", &M);
    getchar();

    lista = create_list(M);

    // colocando toda a entrada na Lista.
    for (int i = 0; i < M; i++)
    {
      scanf("%d", &T);
      getchar();

      if (T == 1)
      {
        ++arestas;
        
        lista[i] = create_head();

        add_noh(lista[i], T);

        auxiliar = lista[i];

        for (int count = 0; count < 2; count++)
        {
            scanf("%d", &target);
            getchar();     
            auxiliar = add_noh(auxiliar, target);
        }
      } else {
            lista[i] = create_head();
            add_noh(lista[i], T);
      }

    }


    int altura  = 0;
    int s = 0;
    int r = 0;

    initialize(dir, alt, N);

    for (int  i = 0; i < M; i++)
    {
        if (lista[i]->prox)
        {
            auxiliar = lista[i]->prox;

            if (auxiliar->key == 2) 
            {
                altura = componentes(dir, alt, N, arestas);
    
                printf("%d\n", altura);
            } else {

                auxiliar = auxiliar->prox;
                r = auxiliar->key;
                
                auxiliar = auxiliar->prox;
                s = auxiliar->key;

                Union(dir, alt,r, s);
            }

        }
    }



    return 0;
}
