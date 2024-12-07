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
    int valores[4];          // Vetor para armazenar até 4 valores
    nodeB* filhos[5];        // Vetor para até 5 filhos (um a mais que os valores)
    int quantidadeValores;   // Número atual de valores no nó
    bool folha;            // Indica se o nó é uma folha ou não
    bool raiz;             // Indica se o nó é a raiz da árvore

    // Construtor para inicializar o nó
    nodeB() {
        quantidadeValores = 0;
        folha = true;      // Por padrão, um novo nó é considerado folha
        raiz = false;      // Por padrão, um novo nó não é a raiz
        for (int i = 0; i < 5; i++) filhos[i] = nullptr;
    }
} nodeB;

typedef nodeB* nodeBPoint; // Ponteiro para nodeB
#endif // TYPE_H