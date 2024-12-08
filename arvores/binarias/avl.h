#include <iostream>
#include "../../types/type.h"
using namespace std;

// Cria um novo nó da arvore AVL com o valor fornecido
nodeAVLPoint criaNovoNoAVL(int valor) {
    nodeAVLPoint novoNo = new nodeAVL;
    novoNo->valor = valor;
    novoNo->altura = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Retorna a altura do maior nó
int max(int alturaEsquerda, int alturaDireita) {
    return (alturaEsquerda > alturaDireita) ? alturaEsquerda : alturaDireita;
}

// Retorna a altura de um nó
int altura(nodeAVLPoint alturaDaSubArvore) {
    return alturaDaSubArvore ? alturaDaSubArvore->altura : 0;
}

// Retorna o fatore de balanceamento de um nó
int fatorDeBalanceamento(nodeAVLPoint noAtual) {
    return noAtual ? altura(noAtual->esquerda) - altura(noAtual->direita) : 0;
}

nodeAVLPoint rotacaoDireita(nodeAVLPoint raizAtual) {
    // Nova raiz será a subárvore esquerda
    nodeAVLPoint novaRaiz = raizAtual->esquerda;

    // Ajuste dos ponteiros
    raizAtual->esquerda = novaRaiz->direita;  // Subárvore direita da nova raiz torna-se a subárvore esquerda da raiz atual
    novaRaiz->direita = raizAtual;           // A raiz atual torna-se a subárvore direita da nova raiz

    // Atualização das alturas
    raizAtual->altura = max(altura(raizAtual->esquerda), altura(raizAtual->direita)) + 1;
    novaRaiz->altura = max(altura(novaRaiz->esquerda), altura(novaRaiz->direita)) + 1;

    // Retorna a nova raiz
    return novaRaiz;
}

nodeAVLPoint rotacaoEsquerda(nodeAVLPoint raizAtual) {
    // Nova raiz será a subárvore direita
    nodeAVLPoint novaRaiz = raizAtual->direita;

    // Ajuste dos ponteiros
    raizAtual->direita = novaRaiz->esquerda;  // Subárvore esquerda da nova raiz torna-se a subárvore direita da raiz atual
    novaRaiz->esquerda = raizAtual;          // A raiz atual torna-se a subárvore esquerda da nova raiz

    // Atualização das alturas
    raizAtual->altura = max(altura(raizAtual->esquerda), altura(raizAtual->direita)) + 1;
    novaRaiz->altura = max(altura(novaRaiz->esquerda), altura(novaRaiz->direita)) + 1;

    // Retorna a nova raiz
    return novaRaiz;
}

nodeAVLPoint AVLAdicionarNo(nodeAVLPoint raiz, nodeAVLPoint novoNo) {
    if (raiz == nullptr) return novoNo;

    if (novoNo->valor < raiz->valor) {
        raiz->esquerda = AVLAdicionarNo(raiz->esquerda, novoNo);

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
        raiz->direita = AVLAdicionarNo(raiz->direita, novoNo);

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

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    return raiz;
}


// sem testar mas tá funcionando kkkk
nodeAVLPoint AVLRemoverNo(nodeAVLPoint raiz, int valor) {
    if (raiz == nullptr) return raiz;

    if (valor < raiz->valor) {
        raiz->esquerda = AVLRemoverNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = AVLRemoverNo(raiz->direita, valor);
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

    if (raiz == nullptr) return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int fator = fatorDeBalanceamento(raiz);

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

    return raiz;
}

// Pré-ordem
void preOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";    // Visita a raiz
        preOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        preOrdem(raiz->direita);       // Percorre a subárvore direita
    }
}

// Em ordem
void emOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esquerda);       // Percorre a subárvore esquerda
        cout << raiz->valor << " ";    // Visita a raiz
        emOrdem(raiz->direita);        // Percorre a subárvore direita
    }
}

// Pós-ordem
void posOrdem(nodeAVLPoint raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);      // Percorre a subárvore esquerda
        posOrdem(raiz->direita);       // Percorre a subárvore direita
        cout << raiz->valor << " ";    // Visita a raiz
    }
}

// Imprime todos os nós de um nível específico
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



// Imprime os nós por nível (da raiz para baixo)
void porNivel(nodeAVLPoint raiz) {
    int h = altura(raiz); // Calcula a altura da árvore
    for (int i = 1; i <= h; i++) {
        imprimeNivel(raiz, i); // Imprime os nós do nível `i`
        cout << endl;          // Adiciona uma nova linha após cada nível
    }
}


// Busca um nó na árvore
nodeAVLPoint AVLbuscaNo(nodeAVLPoint raiz, int valor) {
    if (raiz == nullptr) return raiz;
    if (raiz->valor == valor) return raiz;

    if (raiz->valor > valor) return AVLbuscaNo(raiz->esquerda, valor);
    return AVLbuscaNo(raiz->direita, valor);
}