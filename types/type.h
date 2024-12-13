#ifndef TYPE_H
#define TYPE_H

// nó de arvore binária genérica e de busca binária
typedef struct node {
    int valor;
    struct node *direita;
    struct node *esquerda;
} node;

typedef node* nodePoint; // Ponteiro para node

// nó de arvore AVL
typedef struct nodeAVL {
    int valor;
    int altura;
    struct nodeAVL *direita;
    struct nodeAVL *esquerda;
} nodeAVL;

typedef nodeAVL* nodeAVLPoint; // Ponteiro para nodeAVL

// nó de arvore B
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


// nó de arvore Trie
typedef struct nodeTrie {
    bool retorno;          // Indica se o nó é uma folha ou não
    nodeTrie* filhos[26];  // Vetor para até 26 filhos (uma para cada letra do alfabeto)

    // Construtor para inicializar o nó
    nodeTrie() {
        retorno = false;      // Por padrão, um novo nó não é considerado folha
        for (int i = 0; i < 26; i++) filhos[i] = nullptr;
    }
} nodeTrie;

typedef nodeTrie* nodeTriePoint; // Ponteiro para nodeTrie

struct heap {
    int valor[50];
    int tamanho;

    heap() {
        tamanho = 0;
    }
};


#endif // TYPE_H