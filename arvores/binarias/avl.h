#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "../../types/type.h"
using namespace std;

/**
 * @brief Cria um novo nó da árvore AVL com o valor fornecido.
 * 
 * @param valor Valor a ser atribuído ao novo nó.
 * @return nodeAVLPoint Ponteiro para o novo nó criado.
 */
nodeAVLPoint criaNovoNoAVL(int valor) {
    nodeAVLPoint novoNo = new nodeAVL;
    novoNo->valor = valor;
    novoNo->altura = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

/**
 * @brief Retorna a altura do maior nó.
 * 
 * @param alturaEsquerda Altura da subárvore esquerda.
 * @param alturaDireita Altura da subárvore direita.
 * @return int A maior altura entre as duas subárvores.
 */
int max(int alturaEsquerda, int alturaDireita) {
    return (alturaEsquerda > alturaDireita) ? alturaEsquerda : alturaDireita;
}

/**
 * @brief Retorna a altura de um nó.
 * 
 * @param alturaDaSubArvore Ponteiro para o nó cuja altura será retornada.
 * @return int Altura do nó.
 */
int altura(nodeAVLPoint alturaDaSubArvore) {
    return alturaDaSubArvore ? alturaDaSubArvore->altura : 0;
}

/**
 * @brief Retorna o fator de balanceamento de um nó.
 * 
 * @param noAtual Ponteiro para o nó cujo fator de balanceamento será retornado.
 * @return int Fator de balanceamento do nó.
 */
int fatorDeBalanceamento(nodeAVLPoint noAtual) {
    return noAtual ? altura(noAtual->esquerda) - altura(noAtual->direita) : 0;
}

/**
 * @brief Realiza uma rotação à direita na subárvore com raiz em raizAtual.
 * 
 * @param raizAtual Ponteiro para a raiz da subárvore.
 * @return nodeAVLPoint Nova raiz da subárvore após a rotação.
 */
nodeAVLPoint rotacaoDireita(nodeAVLPoint raizAtual) {
    nodeAVLPoint novaRaiz = raizAtual->esquerda; // Nova raiz será a subárvore esquerda

    // Ajuste dos ponteiros
    raizAtual->esquerda = novaRaiz->direita;  // Subárvore direita da nova raiz torna-se a subárvore esquerda da raiz atual
    novaRaiz->direita = raizAtual;           // A raiz atual torna-se a subárvore direita da nova raiz

    // Atualização das alturas
    raizAtual->altura = max(altura(raizAtual->esquerda), altura(raizAtual->direita)) + 1;
    novaRaiz->altura = max(altura(novaRaiz->esquerda), altura(novaRaiz->direita)) + 1;

    return novaRaiz; // Retorna a nova raiz
}

/**
 * @brief Realiza uma rotação à esquerda na subárvore com raiz em raizAtual.
 * 
 * @param raizAtual Ponteiro para a raiz da subárvore.
 * @return nodeAVLPoint Nova raiz da subárvore após a rotação.
 */
nodeAVLPoint rotacaoEsquerda(nodeAVLPoint raizAtual) {
    nodeAVLPoint novaRaiz = raizAtual->direita; // Nova raiz será a subárvore direita

    // Ajuste dos ponteiros
    raizAtual->direita = novaRaiz->esquerda;  // Subárvore esquerda da nova raiz torna-se a subárvore direita da raiz atual
    novaRaiz->esquerda = raizAtual;          // A raiz atual torna-se a subárvore esquerda da nova raiz

    // Atualização das alturas
    raizAtual->altura = max(altura(raizAtual->esquerda), altura(raizAtual->direita)) + 1;
    novaRaiz->altura = max(altura(novaRaiz->esquerda), altura(novaRaiz->direita)) + 1;

    return novaRaiz; // Retorna a nova raiz
}

/**
 * @brief Adiciona um nó na árvore AVL, retornando a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param novoNo Ponteiro para o novo nó a ser adicionado.
 * @return nodeAVLPoint Ponteiro para a nova raiz da árvore.
 */
nodeAVLPoint AVLAdicionarNo(nodeAVLPoint raiz, nodeAVLPoint novoNo) {
    if (raiz == nullptr) return novoNo; // Se a raiz estiver vazia, novo nó será a raiz.

    if (novoNo->valor < raiz->valor) {
        raiz->esquerda = AVLAdicionarNo(raiz->esquerda, novoNo); // Adiciona na subárvore esquerda.

        // Checa se a árvore está desbalanceada
        if ((altura(raiz->esquerda) - altura(raiz->direita)) == 2) {
           if (novoNo->valor < raiz->esquerda->valor) {
               raiz = rotacaoDireita(raiz);
           } else {
               raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
               raiz = rotacaoDireita(raiz);
           }
        }

    } else if (novoNo->valor > raiz->valor) {
        raiz->direita = AVLAdicionarNo(raiz->direita, novoNo); // Adiciona na subárvore direita.

        // Checa se a árvore está desbalanceada
        if ((altura(raiz->esquerda) - altura(raiz->direita)) == -2) {
            if (novoNo->valor > raiz->direita->valor) {
                raiz = rotacaoEsquerda(raiz);
            } else {
                raiz->direita = rotacaoDireita(raiz->direita);
                raiz = rotacaoEsquerda(raiz);
            }
        }
    } else {
        cout << "O valor " << novoNo->valor << " já existe na árvore." << endl;
        delete novoNo;
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita)); // Atualiza a altura da raiz.

    return raiz; // Retorna a raiz atualizada.
}

/**
 * @brief Remove um nó com o valor especificado e retorna a nova raiz.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor do nó a ser removido.
 * @return nodeAVLPoint Ponteiro para a nova raiz da árvore.
 */
nodeAVLPoint AVLRemoverNo(nodeAVLPoint raiz, int valor) {
    if (raiz == nullptr) return raiz; // Se a árvore estiver vazia, retorna nullptr.

    if (valor < raiz->valor) {
        raiz->esquerda = AVLRemoverNo(raiz->esquerda, valor); // Remove da subárvore esquerda.
    } else if (valor > raiz->valor) {
        raiz->direita = AVLRemoverNo(raiz->direita, valor); // Remove da subárvore direita.
    } else {
        if (raiz->esquerda == nullptr || raiz->direita == nullptr) {
            nodeAVLPoint temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == nullptr) {
                temp = raiz;
                raiz = nullptr;
            } else {
                *raiz = *temp;
            }

            delete temp;
        } else {
            nodeAVLPoint temp = raiz->direita;
            while (temp->esquerda != nullptr) {
                temp = temp->esquerda;
            }

            raiz->valor = temp->valor;
            raiz->direita = AVLRemoverNo(raiz->direita, temp->valor);
        }
    }

    if (raiz == nullptr) return raiz; // Se a árvore estiver vazia após a remoção, retorna nullptr.

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita)); // Atualiza a altura da raiz.

    int fator = fatorDeBalanceamento(raiz); // Calcula o fator de balanceamento.

    // Realiza rotações se necessário para balancear a árvore.
    if (fator > 1 && fatorDeBalanceamento(raiz->esquerda) >= 0) {
        return rotacaoDireita(raiz);
    }

    if (fator > 1 && fatorDeBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (fator < -1 && fatorDeBalanceamento(raiz->direita) <= 0) {
        return rotacaoEsquerda(raiz);
    }

    if (fator < -1 && fatorDeBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz; // Retorna a raiz atualizada.
}

/**
 * @brief Realiza a travessia pré-ordem na árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 */
void preOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";    // Visita a raiz
        preOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        preOrdem(raiz->direita);       // Percorre a subárvore direita
    }
}

/**
 * @brief Realiza a travessia em ordem na árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 */
void emOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esquerda);       // Percorre a subárvore esquerda
        cout << raiz->valor << " ";    // Visita a raiz
        emOrdem(raiz->direita);        // Percorre a subárvore direita
    }
}

/**
 * @brief Realiza a travessia pós-ordem na árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 */
void posOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        posOrdem(raiz->direita);       // Percorre a subárvore direita
        cout << raiz->valor << " ";    // Visita a raiz
    }
}

/**
 * @brief Imprime todos os nós de um nível específico.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param nivel Nível a ser impresso.
 */
void imprimeNivel(nodeAVLPoint raiz, int nivel) {
    if (raiz == nullptr)
        return;
    if (nivel == 1) { // Imprime o nó se estiver no nível desejado
        cout << raiz->valor << " ";   
    } else if (nivel > 1) {
        imprimeNivel(raiz->esquerda, nivel - 1);
        imprimeNivel(raiz->direita, nivel - 1);
    }
}

/**
 * @brief Imprime os nós por nível (da raiz para baixo).
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 */
void porNivel(nodeAVLPoint raiz) {
    int h = altura(raiz); // Calcula a altura da árvore
    for (int i = 1; i <= h; i++) {
        imprimeNivel(raiz, i); // Imprime os nós do nível `i`
        cout << endl;          // Adiciona uma nova linha após cada nível
    }
}

/**
 * @brief Busca um nó na árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser buscado na árvore.
 * @return nodeAVLPoint Ponteiro para o nó encontrado ou nullptr se não encontrado.
 */
nodeAVLPoint AVLbuscaNo(nodeAVLPoint raiz, int valor) {
    if (raiz == nullptr) return raiz; // Se a árvore estiver vazia, retorna nullptr.
    if (raiz->valor == valor) return raiz; // Se o valor for encontrado na raiz, retorna a raiz.

    if (raiz->valor > valor) return AVLbuscaNo(raiz->esquerda, valor); // Busca na subárvore esquerda.
    return AVLbuscaNo(raiz->direita, valor); // Busca na subárvore direita.
}

#endif