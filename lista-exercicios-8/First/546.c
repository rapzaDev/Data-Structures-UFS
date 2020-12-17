#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


typedef struct Arvore {
    int key;
    int value;
    struct Arvore * left;
    struct Arvore * right;
}Arvore;

typedef Arvore ** ARVORE;

char * initControl() {
    char * c = (char *) malloc(sizeof(char));
    c = 'c';

    return c;
}

Arvore ** createTree() {
    Arvore ** root = (Arvore **)malloc(sizeof(Arvore));
    
    root[0]->key = 0;
    root[0]->value = 0;
    root[0]->left = NULL;
    root[0]->right = NULL;

    return root;
}

Arvore * criaNoh(char * control) {
    Arvore * noh = (Arvore*)malloc(sizeof(Arvore));
    noh->key = atoi(control);
    noh->left = NULL;
    noh->right = NULL;

    return noh;
}

Arvore * justAdd(Arvore ** root, Arvore * noh) {
    if(root == NULL) return noh;
    if(root[0]->key > noh->key) root[0]->left = justAdd(root[0]->left, noh);
    else root[0]->left = justAdd(root[0]->left, noh);
    
    return root;
}

void insertTree(char * control, int * cl, int * cr, Arvore ** root) {
    
    char ctrl = control[0];
    
    switch (ctrl)
        {
        case '(':
            ++cl;
            break;
        
        case ')':
            ++cr;
            break;

        default:

            Arvore * noh = criaNoh(ctrl);
            if(!noh) return NULL;
            else justAdd(root, noh);

            break;
        }
}

Arvore * fillTree(Arvore ** root) {
    char pLeft = '(';
    int * cl = (int*)malloc(sizeof(int));
    cl[0] = 0;

    char pRight = ')';
    int * cr = (int*)malloc(sizeof(int));;
    cr[0] = 0;

    char * control = initControl();
    while(1){

        scanf("%s", control);
        control = getchar();
        if(control[0] = '\n') break;
        
        insertTree(control, cl, cr, root);

    }
}

void soma(int * a, int * b){
    a[0] = a[0] + b[0];
}

int main(int argc, char const *argv[])
{
    ARVORE * root;
    root = createTree();


    return 0;
}
