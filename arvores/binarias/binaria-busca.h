#ifndef BINARIA_BUSCA_H
#define BINARIA_BUSCA_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

/**
 * @brief Adiciona um nó na árvore binária de busca, retornando a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param novoNo Ponteiro para o novo nó a ser adicionado.
 * @return nodePoint Ponteiro para a nova raiz da árvore.
 */
nodePoint adicionarNo(nodePoint raiz, nodePoint novoNo) {
    if (raiz == nullptr) return novoNo; // Se a raiz estiver vazia, novo nó será a raiz.

    if (novoNo->valor < raiz->valor) {
        raiz->esquerda = adicionarNo(raiz->esquerda, novoNo); // Adiciona na subárvore esquerda.
    } else if (novoNo->valor > raiz->valor) {
        raiz->direita = adicionarNo(raiz->direita, novoNo); // Adiciona na subárvore direita.
    } else {
        cout << "O valor " << novoNo->valor << " já existe na árvore." << endl;
        delete novoNo; // Se o valor já existe, não adiciona o nó.
    }

    return raiz; // Retorna a raiz atualizada.
}

/**
 * @brief Busca um nó na árvore binária de busca.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser buscado na árvore.
 * @return nodePoint Ponteiro para o nó encontrado ou nullptr se não encontrado.
 */
nodePoint buscaNo(nodePoint raiz, int valor) {
    if (raiz == nullptr) return raiz; // Se a árvore estiver vazia, retorna nullptr.
    if (raiz->valor == valor) return raiz; // Se o valor for encontrado na raiz, retorna a raiz.

    if (raiz->valor > valor) return buscaNo(raiz->esquerda, valor); // Busca na subárvore esquerda.
    return buscaNo(raiz->direita, valor); // Busca na subárvore direita.
}

/**
 * @brief Função auxiliar para encontrar o menor valor em uma subárvore.
 * 
 * @param raiz Ponteiro para o nó raiz da subárvore.
 * @return nodePoint Ponteiro para o nó com o menor valor.
 */
nodePoint encontraMinimo(nodePoint raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda; // Percorre até encontrar o nó mais à esquerda.
    return raiz;
}

/**
 * @brief Remove um nó com o valor especificado e retorna a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor do nó a ser removido.
 * @return nodePoint Ponteiro para a nova raiz da árvore.
 */
nodePoint removerNo(nodePoint raiz, int valor) {
    if (raiz == nullptr) return nullptr; // Se a árvore estiver vazia, retorna nullptr.

    // Procura o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor); // Remove da subárvore esquerda.
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor); // Remove da subárvore direita.
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
    return raiz; // Retorna a raiz atualizada.
}

#endif