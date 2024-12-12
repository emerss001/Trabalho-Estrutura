#ifndef BINARIA_H
#define BINARIA_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

/**
 * @brief Adiciona um nó na árvore binária, retornando a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param novoNo Ponteiro para o novo nó a ser adicionado.
 * @return nodePoint Ponteiro para a nova raiz da árvore.
 */
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

/**
 * @brief Busca um nó na árvore binária.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser buscado na árvore.
 * @return nodePoint Ponteiro para o nó encontrado ou nullptr se não encontrado.
 */
nodePoint buscaNoBinaria(nodePoint raiz, int valor) {
    if (raiz == nullptr) return raiz;  // Se a árvore estiver vazia, retorna nullptr.
    if (raiz->valor == valor) return raiz;  // Se o valor for encontrado na raiz, retorna a raiz.

    // Verifica se o valor está no nó à esquerda ou à direita.
    if (raiz->esquerda->valor == valor) return raiz->esquerda;
    if (raiz->direita->valor == valor) return raiz->direita;
    
    // Busca recursivamente no lado esquerdo.
    return buscaNoBinaria(raiz->esquerda, valor);
}

/**
 * @brief Remove um nó com o valor especificado e retorna a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor do nó a ser removido.
 * @return nodePoint Ponteiro para a nova raiz da árvore.
 */
nodePoint removerNoBinaria(nodePoint raiz, int valor) {
    if (raiz == nullptr) {
        cout << "A árvore está vazia";
        return nullptr;
    }

    // Procurar o nó a ser removido
    if (raiz->valor == valor) {
        // Caso o nó tenha apenas um filho à esquerda
        if (raiz->esquerda != nullptr && raiz->direita == nullptr) {
            nodePoint temp = raiz->esquerda;
            delete raiz;
            return temp;
        } 
        // Caso o nó não tenha filhos
        else if (raiz->esquerda == nullptr) {
            delete raiz;
            return nullptr;
        }
        // Caso o nó tenha filhos à direita
        else {
            nodePoint temp = raiz->direita;
            raiz->valor = temp->valor;
            raiz->direita = removerNoBinaria(raiz->direita, temp->valor);
        }
    } 
    // Busca recursivamente no lado esquerdo ou direito
    else if (raiz->esquerda->valor == valor) {
        raiz->esquerda = removerNoBinaria(raiz->esquerda, valor);
    } else {
        raiz->direita = removerNoBinaria(raiz->direita, valor);
    }

    return raiz;
}

#endif