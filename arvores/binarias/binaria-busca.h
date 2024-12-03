#ifndef BINARIA_BUSCA_H
#define BINARIA_BUSCA_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

// Adiciona um nó na árvore, retornando a nova raiz
nodePoint adicionarNo(nodePoint raiz, nodePoint novoNo) {
    if (raiz == nullptr) return novoNo;

    if (novoNo->valor < raiz->valor) {
        raiz->esquerda = adicionarNo(raiz->esquerda, novoNo);
    } else if (novoNo->valor > raiz->valor) {
        raiz->direita = adicionarNo(raiz->direita, novoNo);
    } else {
        cout << "O valor " << novoNo->valor << " já existe na árvore." << endl;
        delete novoNo;
    }

    return raiz;
}

// Busca um nó na árvore
nodePoint buscaNo(nodePoint raiz, int valor) {
    if (raiz == nullptr) return raiz;
    if (raiz->valor == valor) return raiz;

    if (raiz->valor > valor) return buscaNo(raiz->esquerda, valor);
    return buscaNo(raiz->direita, valor);
}

// Função auxiliar para encontrar o menor valor em uma subárvore
nodePoint encontraMinimo(nodePoint raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

// Remove um nó com o valor especificado e retorna a nova raiz
nodePoint removerNo(nodePoint raiz, int valor) {
    if (raiz == nullptr) return nullptr;

    // Procura o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        // Caso 1: Nó folha (sem filhos)
        if (raiz->esquerda == nullptr && raiz->direita == nullptr) {
            delete raiz;
            return nullptr;
        }
        // Caso 2: Um único filho
        else if (raiz->esquerda == nullptr) {
            nodePoint temp = raiz->direita;
            delete raiz;
            return temp;
        } else if (raiz->direita == NULL) {
            nodePoint temp = raiz->esquerda;
            delete raiz;
            return temp;
        }
        // Caso 3: Dois filhos
        else {
            nodePoint temp = encontraMinimo(raiz->direita); // Sucessor in-order
            raiz->valor = temp->valor; // Substitui pelo valor do sucessor
            raiz->direita = removerNo(raiz->direita, temp->valor); // Remove o sucessor
        }
    }
    return raiz;
}

#endif
