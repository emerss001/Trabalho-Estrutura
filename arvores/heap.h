#ifndef Heap_H
#define Heap_H

#include <iostream>
#include "../types/type.h"
using namespace std;

/**
 * @brief Troca dois elementos no array.
 * 
 * @param primeiro Referência para o primeiro elemento.
 * @param segundo Referência para o segundo elemento.
 */
void trocarValor(int &primeiro, int &segundo) {
    int temp = primeiro;
    primeiro = segundo;
    segundo = temp;
}

/**
 * @brief Garante a propriedade do heap após inserção (heapify-up).
 * 
 * @param heap Referência para a estrutura do heap.
 * @param IndiceNovoValorInserido Índice do novo valor inserido.
 */
void heapifyUp(heap &heap, int IndiceNovoValorInserido) {
    int paiNovoValor = (IndiceNovoValorInserido - 1) / 2;
    while (IndiceNovoValorInserido > 0 && heap.valor[IndiceNovoValorInserido] > heap.valor[paiNovoValor]) {
        trocarValor(heap.valor[IndiceNovoValorInserido], heap.valor[paiNovoValor]);
        IndiceNovoValorInserido = paiNovoValor;
        paiNovoValor = (IndiceNovoValorInserido - 1) / 2;
    }
}

/**
 * @brief Garante a propriedade do heap após remoção (heapify-down).
 * 
 * @param heap Referência para a estrutura do heap.
 * @param index Índice do valor a ser ajustado.
 */
void heapifyDown(heap &heap, int index) {
    while (true) {
        int filhoEsquerdo = (2 * index) + 1;
        int filhoDireito = (index + 1) * 2;
        int maior = index;

        if (filhoEsquerdo < heap.tamanho && heap.valor[filhoEsquerdo] > heap.valor[maior]) {
            maior = filhoEsquerdo;
        }
        if (filhoDireito < heap.tamanho && heap.valor[filhoDireito] > heap.valor[maior]) {
            maior = filhoDireito;
        }

        if (maior != index) {
            trocarValor(heap.valor[index], heap.valor[maior]);
            index = maior;
        } else {
            break;
        }
    }
}

/**
 * @brief Insere um valor no heap.
 * 
 * @param heap Referência para a estrutura do heap.
 * @param valor Valor a ser inserido.
 */
void inserir(heap &heap, int valor) {
    if (heap.tamanho >= 50) {
        cout << "Heap está cheio!" << endl;
        return;
    }

    heap.valor[heap.tamanho] = valor;
    heapifyUp(heap, heap.tamanho);
    heap.tamanho++;
    cout << "Valor " << valor << " inserido com sucesso!" << endl;
}

/**
 * @brief Remove o valor da raiz do heap.
 * 
 * @param heap Referência para a estrutura do heap.
 */
void removerValor(heap &heap) {
    if (heap.tamanho == 0) {
        cout << "Heap está vazio!" << endl;
        return;
    }

    heap.valor[0] = heap.valor[heap.tamanho - 1];
    heap.tamanho--;
    heapifyDown(heap, 0);
    cout << "Valor removido com sucesso!" << endl;
}

/**
 * @brief Busca um valor no heap.
 * 
 * @param heap Referência para a estrutura do heap.
 * @param valor Valor a ser buscado.
 */
void buscarValor(heap &heap, int valor) {
    for (int i = 0; i < heap.tamanho; i++) {
        if (heap.valor[i] == valor) {
            cout << "Valor " << valor << " encontrado na posição: " << i << endl;
            return;
        }
    }
    cout << "Valor " << valor << " não encontrado no heap!" << endl;
}

/**
 * @brief Exibe os valores do heap por nível.
 * 
 * @param h Estrutura do heap.
 */
void exibirPorNivel(heap h) {
    if (h.tamanho == 0) {
        cout << "Heap vazia." << endl;
        return;
    }

    int nivel = 0;
    int indexAtual = 0;

    while (indexAtual < h.tamanho) {
        int inicioNivel = (1 << nivel) - 1; // 2^nivel - 1
        int fimNivel = (1 << (nivel + 1)) - 2; // 2^(nivel+1) - 2

        // Evita ultrapassar o tamanho da heap
        if (fimNivel >= h.tamanho) {
            fimNivel = h.tamanho - 1;
        }

        cout << "Nível " << nivel << ": ";
        for (int i = inicioNivel; i <= fimNivel; i++) {
            cout << h.valor[i] << " ";
        }
        cout << endl;

        nivel++;
        indexAtual = (1 << nivel) - 1; // Avança para o início do próximo nível
    }
}

/**
 * @brief Exibe os valores do heap em pré-ordem.
 * 
 * @param heap Referência para a estrutura do heap.
 * @param indice Índice do nó atual (padrão é 0, a raiz).
 */
void exibirPreOrdem(heap &heap, int indice = 0) {
    if (indice >= heap.tamanho) return;

    cout << heap.valor[indice] << " ";

    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;

    exibirPreOrdem(heap, filhoEsquerdo);
    exibirPreOrdem(heap, filhoDireito);
}

/**
 * @brief Exibe os valores do heap em ordem.
 * 
 * @param heap Referência para a estrutura do heap.
 * @param indice Índice do nó atual (padrão é 0, a raiz).
 */
void exibirEmOrdem(heap &heap, int indice = 0) {
    if (indice >= heap.tamanho) return;

    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;

    exibirEmOrdem(heap, filhoEsquerdo);
    cout << heap.valor[indice] << " ";
    exibirEmOrdem(heap, filhoDireito);
}

/**
 * @brief Exibe os valores do heap em pós-ordem.
 * 
 * @param heap Referência para a estrutura do heap.
 * @param indice Índice do nó atual (padrão é 0, a raiz).
 */
void exibirPosOrdem(heap &heap, int indice = 0) {
    if (indice >= heap.tamanho) return;

    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;

    exibirPosOrdem(heap, filhoEsquerdo);
    exibirPosOrdem(heap, filhoDireito);
    cout << heap.valor[indice] << " ";
}

#endif