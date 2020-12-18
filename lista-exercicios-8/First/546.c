#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
typedef struct Arvore {
    int key;
    int value;
    struct Arvore * dad;
    struct Arvore * left;
    struct Arvore * right;
}Arvore;

// char * initControl() {
//     char * c = (char *) malloc(sizeof(char));
//     c[0] = 'c';

//     return c;
// }

Arvore * createTree() {
    Arvore * root = (Arvore *)malloc(sizeof(Arvore));
    
    return root;
}

Arvore * criaNoh(char control) {
    char * c = (char*)malloc(sizeof(char));
    c[0] = control;

    Arvore * noh = (Arvore*)malloc(sizeof(Arvore));
    noh->key = atoi(c);
    noh->left = NULL;
    noh->right = NULL;

    return noh;
}

Arvore * lefty(Arvore * root, Arvore * noh) {
    if(!root) {return noh;}
    else {
        root->left = lefty(root->left, noh);
        
        Arvore * leftNoh = root->left;
        leftNoh->dad = root;
    }

    return root;
}

Arvore * righty(Arvore * root, Arvore * noh) {
    if(root == NULL) {return noh;}
    else {
        root->right = righty(root->right, noh);
        
        Arvore * rightNoh = root->right;
        rightNoh->dad = root;
    }
    
    return root;
}

int searchy(Arvore * root, int check) {
    if(!root) {
        check = 1;
        return check;
    }
    if(root->left) {
        
        if(root->left > root) {
            printf("FALSO\n");
            exit(0);
        }
        else { return searchy(root->left, check); }

    }

    if(root->right) {
        
        if(root < root->dad) {
            printf("FALSO\n");
            exit(0);
        }
        else { return searchy(root->right, check); }

    }

    return check;
}

Arvore * populateTree(Arvore * root) {
    int leftCode = -1;
    int cl = 0;

    int rightCode = -1;
    int cr = 0;

    // char * control = initControl();
    char ctrl = 'c';
    while(1){
        
        // scanf("%s", control);
        scanf("%c", &ctrl);

        if(ctrl == '\n') break;
        if(ctrl == ' ') scanf("%c", &ctrl);     

        Arvore * noh;
        switch (ctrl)
        {

        case '(':
            ++cl;
            leftCode = 1;
            break;
        
        case ')':
            ++cr;
            rightCode = 1;
            break;

        default:

            noh = criaNoh(ctrl);

            if(!noh->key) return NULL;

            if(leftCode == 1){
                root = lefty(root, noh);
                leftCode = -1;
            }

            if(rightCode == 1){
                root = righty(root, noh);
                rightCode = -1;
            }

            break;
        }

    }

    if(cl != cr) root = NULL;

    return root;
}


void rootTreeAnalysis(Arvore * root) {
    int value = searchy(root, 1);

    if(value) printf("VERDADEIRO\n");
    
}


int main(int argc, char const *argv[])
{
    Arvore * root;
    root = createTree();

    root = populateTree(root);

    if(!root) {
        printf("FALSO\n");
        return 0;
    }

    rootTreeAnalysis(root);


    return 0;
}
