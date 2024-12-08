#ifndef Trie_H
#define Trie_H

#include <iostream>
#include "../types/type.h"
#include <string>
using namespace std;

int mapearIndice(char letra) {
    return (int)letra - (int)'a';
}

void inserirPalavra(nodeTriePoint raiz, string palavra) {
    nodeTriePoint atual = raiz;
    for (int i = 0; i < palavra.size(); i++) {
        int indice = mapearIndice(palavra[i]);
        if (atual->filhos[indice] == nullptr) {
            atual->filhos[indice] = new nodeTrie;
        }
        atual = atual->filhos[indice];
    }
    atual->retorno = true;
}

void buscar(nodeTriePoint raiz, string palavra) {
    nodeTriePoint atual = raiz;
    for (int i = 0; i < palavra.size(); i++) {
        int indice = mapearIndice(palavra[i]);
        if (atual->filhos[indice] == nullptr) {
            cout << "Palavra não encontrada" << endl;
            return;
        }
        atual = atual->filhos[indice];
    }
    if (atual->retorno) {
        cout << "Palavra encontrada" << endl;
    } else {
        cout << "Palavra não encontrada" << endl;
    }
}

// Função auxiliar para coletar palavras completas a partir de um nó
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

void buscarPorPrefixo(nodeTrie* raiz, string prefixo) {
    nodeTrie* atual = raiz;
    for (int i = 0; i < prefixo.size(); i++) {
        int indice = mapearIndice(prefixo[i]);
        if (indice == -1 || atual->filhos[indice] == nullptr) {
            cout << "Nenhuma palavra encontrada com o prefixo \"" << prefixo << "\"." << endl;
            return;
        }
        atual = atual->filhos[indice];
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

#endif