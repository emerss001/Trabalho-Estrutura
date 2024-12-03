#ifndef FUNCOES_COMPARTILHADAS_H
#define FUNCOES_COMPARTILHADAS_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

nodePoint criaNovoNo(int valor) {
    nodePoint novoNo = new node;
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Pré-ordem
void preOrdem(nodePoint raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";    // Visita a raiz
        preOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        preOrdem(raiz->direita);       // Percorre a subárvore direita
    }
}

// Em ordem
void emOrdem(nodePoint raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esquerda);       // Percorre a subárvore esquerda
        cout << raiz->valor << " ";    // Visita a raiz
        emOrdem(raiz->direita);        // Percorre a subárvore direita
    }
}

// Pós-ordem
void posOrdem(nodePoint raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        posOrdem(raiz->direita);       // Percorre a subárvore direita
        cout << raiz->valor << " ";    // Visita a raiz
    }
}

// Calcula a altura da árvore
int altura(nodePoint raiz) {
    if (raiz == nullptr)
        return 0;
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    return 1 + max(alturaEsquerda, alturaDireita);
}

// Imprime todos os nós de um nível específico
void imprimeNivel(nodePoint raiz, int nivel) {
    if (raiz == nullptr)
        return;
    if (nivel == 1) { // Imprime o nó se estiver no nível desejado
        cout << raiz->valor << " ";   
    } else if (nivel > 1) {
        imprimeNivel(raiz->esquerda, nivel - 1);
        imprimeNivel(raiz->direita, nivel - 1);
    }
}

// Imprime os nós por nível (da raiz para baixo)
void porNivel(nodePoint raiz) {
    int h = altura(raiz); // Calcula a altura da árvore
    for (int i = 1; i <= h; i++) {
        imprimeNivel(raiz, i); // Imprime os nós do nível `i`
        cout << endl;          // Adiciona uma nova linha após cada nível
    }
}

#endif
