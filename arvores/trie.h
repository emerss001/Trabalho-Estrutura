#ifndef Trie_H
#define Trie_H

#include <iostream>
#include "../types/type.h"
#include <string>
using namespace std;

/**
 * @brief Mapeia um caractere para um índice correspondente.
 * 
 * @param letra Caractere a ser mapeado.
 * @return int Índice correspondente ao caractere.
 */
int mapearIndice(char letra) {
    return (int)letra - (int)'a';
}

/**
 * @brief Insere uma palavra na árvore Trie.
 * 
 * @param raiz Ponteiro para o nó raiz da Trie.
 * @param palavra Palavra a ser inserida.
 */
void inserirPalavra(nodeTriePoint raiz, string palavra) {
    nodeTriePoint atual = raiz;
    for (int i = 0; i < palavra.size(); i++) {
        int indice = mapearIndice(palavra[i]);
        if (atual->filhos[indice] == nullptr) {
            atual->filhos[indice] = new nodeTrie; // Cria um novo nó se não existir
        }
        atual = atual->filhos[indice]; // Move para o próximo nó
    }
    atual->retorno = true; // Marca o final da palavra
}

/**
 * @brief Busca uma palavra na árvore Trie.
 * 
 * @param raiz Ponteiro para o nó raiz da Trie.
 * @param palavra Palavra a ser buscada.
 */
void buscar(nodeTriePoint raiz, string palavra) {
    nodeTriePoint atual = raiz;
    for (int i = 0; i < palavra.size(); i++) {
        int indice = mapearIndice(palavra[i]);
        if (atual->filhos[indice] == nullptr) {
            cout << "Palavra não encontrada" << endl;
            return;
        }
        atual = atual->filhos[indice]; // Move para o próximo nó
    }
    if (atual->retorno) {
        cout << "Palavra encontrada" << endl;
    } else {
        cout << "Palavra não encontrada" << endl;
    }
}

/**
 * @brief Função auxiliar para coletar palavras completas a partir de um nó.
 * 
 * @param no Ponteiro para o nó atual.
 * @param prefixo Prefixo acumulado até o nó atual.
 * @param resultados Array para armazenar as palavras encontradas.
 * @param contador Contador de palavras encontradas.
 */
void coletarPalavras(nodeTrie* no, string prefixo, string resultados[], int& contador) {
    if (no == nullptr) return;

    if (no->retorno) {
        resultados[contador++] = prefixo; // Armazena o prefixo como uma palavra completa
    }

    for (int i = 0; i < 26; i++) {
        if (no->filhos[i] != nullptr) {
            char proximaLetra = 'a' + i; // Calcula a próxima letra
            coletarPalavras(no->filhos[i], prefixo + proximaLetra, resultados, contador);
        }
    }
}

/**
 * @brief Busca palavras na árvore Trie que começam com um determinado prefixo.
 * 
 * @param raiz Ponteiro para o nó raiz da Trie.
 * @param prefixo Prefixo a ser buscado.
 */
void buscarPorPrefixo(nodeTrie* raiz, string prefixo) {
    nodeTrie* atual = raiz;
    for (int i = 0; i < prefixo.size(); i++) {
        int indice = mapearIndice(prefixo[i]);
        if (indice == -1 || atual->filhos[indice] == nullptr) {
            cout << "Nenhuma palavra encontrada com o prefixo \"" << prefixo << "\"." << endl;
            return;
        }
        atual = atual->filhos[indice]; // Move para o próximo nó
    }

    // Coletar todas as palavras que começam com o prefixo
    const int TAMANHO_MAXIMO = 100; // Limite de palavras encontradas
    string resultados[TAMANHO_MAXIMO];
    int contador = 0;
    coletarPalavras(atual, prefixo, resultados, contador);

    if (contador == 0) {
        cout << "Nenhuma palavra encontrada com o prefixo \"" << prefixo << "\"." << endl;
    } else {
        cout << "Palavras encontradas com o prefixo \"" << prefixo << "\":" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "- " << resultados[i] << endl;
        }
    }
}

/**
 * @brief Remove uma palavra da árvore Trie.
 * 
 * @param raiz Ponteiro para o nó raiz da Trie.
 * @param palavra Palavra a ser removida.
 */
void remover(nodeTriePoint raiz, string palavra) {
    nodeTriePoint atual = raiz;
    for (int i = 0; i < palavra.size(); i++) {
        int indice = mapearIndice(palavra[i]);
        if (atual->filhos[indice] == nullptr) {
            cout << "Palavra não encontrada" << endl;
            return;
        }
        atual = atual->filhos[indice]; // Move para o próximo nó
    }
    if (atual->retorno) {
        atual->retorno = false; // Marca o final da palavra como falso
        cout << "Palavra removida" << endl;
    } else {
        cout << "Palavra não encontrada" << endl;
    }
}

#endif