#ifndef BINARIA_H
#define BINARIA_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

// Adiciona um nó na árvore, retornando a nova raiz
nodePoint adicionarNoBinaria(nodePoint raiz, nodePoint novoNo) {
    if (raiz == nullptr) return novoNo;  // Se a raiz estiver vazia, novo nó será a raiz.

    // Se o nó à esquerda estiver vazio, adiciona lá.
    if (raiz->esquerda == nullptr) {
        raiz->esquerda = novoNo;
    } 
    // Caso contrário, tenta adicionar na direita.
    else if (raiz->direita == nullptr) {
        raiz->direita = novoNo;
    } 
    // Se ambos os lados já estão preenchidos, insere recursivamente à esquerda.
    else {
        raiz->esquerda = adicionarNoBinaria(raiz->esquerda, novoNo);
    }

    return raiz;  // Retorna a raiz atualizada.
}

// Busca um nó na árvore
nodePoint buscaNoBinaria(nodePoint raiz, int valor) {
    if (raiz == nullptr) return raiz;
    if (raiz->valor == valor) return raiz;

    if (raiz->esquerda->valor == valor) return raiz->esquerda;
    if (raiz->direita->valor == valor) return raiz->direita;
    
    return buscaNoBinaria(raiz->esquerda, valor);
}

// Remover um nó com o valor especificado e retorna a nova raiz
nodePoint removerNoBinaria(nodePoint raiz, int valor) {
    if (raiz == nullptr) return nullptr;

    //Procurar o nó a ser removido
    if (raiz->valor == valor) {
         if (raiz->esquerda != nullptr && raiz->direita == nullptr) {
            nodePoint temp = raiz->esquerda;
            delete raiz;
            return temp;
        } 
        
        else if (raiz->esquerda == nullptr) {
            delete raiz;
            return nullptr;
        }

        else {
            nodePoint temp = raiz->direita;
            raiz->valor = temp->valor;
            
            raiz->direita = removerNoBinaria(raiz->direita, temp->valor);
        }

    } else if (raiz->esquerda->valor == valor) {
        raiz->esquerda = removerNoBinaria(raiz->esquerda, valor);
    } else {
        raiz->direita = removerNoBinaria(raiz->direita, valor);
    }

    return raiz;
}

#endif
