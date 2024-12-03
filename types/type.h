#ifndef TYPE_H
#define TYPE_H

typedef struct node {
    int valor;
    struct node *direita;
    struct node *esquerda;
} node;

typedef node* nodePoint; // Ponteiro para node

typedef struct nodeAVL {
    int valor;
    int altura;
    struct nodeAVL *direita;
    struct nodeAVL *esquerda;
} nodeAVL;

typedef nodeAVL* nodeAVLPoint; // Ponteiro para nodeAVL


typedef struct nodeB {
    int valores[4];
    struct nodeB *filhos[5];
    int numValores; 
    bool folha;
} nodeB;

typedef nodeB* nodeBPoint; // Ponteiro para nodeB
#endif // TYPE_H