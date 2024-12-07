#ifndef B_H
#define B_H

#include <iostream>
#include "../types/type.h"
#include <queue>
using namespace std;


int *ordenarValores(nodeBPoint raiz, int valor) {
    int *temp = new int[5];
     int i = 0, j = 0;

     while (i < 4) {
            if (valor < raiz->valores[i] && j == i) {
                temp[j] = valor;
                j++;
            } 
            
            else {
                temp[j] = raiz->valores[i];
                j++;
                i++;
            }

            if (i == 4) {
                temp[j] = valor;
            }
    }

    return temp;
}


nodeBPoint inserirValorB(nodeBPoint raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new nodeB();
        raiz->valores[0] = valor;
        raiz->quantidadeValores = 1;
        raiz->folha = true;
        raiz->raiz = true;
        return raiz;
    }

    if (raiz->folha) {
        if (raiz->quantidadeValores < 4) {
            // Inserir diretamente em um nó folha
            int i = raiz->quantidadeValores - 1;
            while (i >= 0 && raiz->valores[i] > valor) {
                raiz->valores[i + 1] = raiz->valores[i];
                i--;
            }
            raiz->valores[i + 1] = valor;
            raiz->quantidadeValores++;
            return raiz;
        } else {
            int *temp = ordenarValores(raiz, valor);
           
            // Agora dividimos o nó
            nodeBPoint novoNo = new nodeB();
            novoNo->valores[0] = temp[3];
            novoNo->valores[1] = temp[4];
            novoNo->valores[2] = temp[2];
            novoNo->quantidadeValores = 2;

            raiz->valores[0] = temp[0];
            raiz->valores[1] = temp[1];
            raiz->quantidadeValores = 2;

            if (raiz->raiz) {
                nodeBPoint novoRaiz = new nodeB();
                novoRaiz->valores[0] = temp[2];
                novoRaiz->quantidadeValores = 1;
                novoRaiz->folha = false;
                novoRaiz->raiz = true;
                novoRaiz->filhos[0] = raiz;
                novoRaiz->filhos[1] = novoNo;

                raiz->raiz = false;
                return novoRaiz;
            } 

            // Quando o nó está cheio não for a raiz, dividimos e promovemos um valor

            return novoNo;

           
        }
    }

    // Inserir recursivamente no filho apropriado
    int i = raiz->quantidadeValores - 1;
    while (i >= 0 && raiz->valores[i] > valor) {
        i--;
    }
    i++;

    nodeBPoint filho = raiz->filhos[i];
    nodeBPoint novaSubArvore = inserirValorB(filho, valor);

    if (novaSubArvore != filho) {
        // Tratar promoção do filho
        int promovido = novaSubArvore->valores[2];
        
        // se a raiz tiver espaço, insira o promovido
        if (raiz->quantidadeValores < 4) {
            // Inserir promovido no nó pai organizando os valores e filhos
            i = raiz->quantidadeValores - 1;
            while (i >= 0 && raiz->valores[i] > promovido) {
                raiz->valores[i + 1] = raiz->valores[i];
                raiz->filhos[i + 2] = raiz->filhos[i + 1];
                i--;
            }
            raiz->valores[i + 1] = promovido;
            raiz->filhos[i + 2] = novaSubArvore;
            raiz->quantidadeValores++;
            return raiz;
            
        }
        // se a raiz não tiver espaço, dividir e promover
        int *temp = ordenarValores(raiz, promovido);
        i = raiz->quantidadeValores - 1;
        nodeBPoint novaRaizDeTudo = new nodeB();
        nodeBPoint novoNoIrmaoDaAntigaRaiz = new nodeB();

        // arrumando nova raiz de tudo
        novaRaizDeTudo->valores[0] = temp[2];
        novaRaizDeTudo->quantidadeValores = 1;
        novaRaizDeTudo->folha = false;
        novaRaizDeTudo->raiz = true;
        novaRaizDeTudo->filhos[0] = raiz;
        novaRaizDeTudo->filhos[1] = novoNoIrmaoDaAntigaRaiz;

        
        // arrumando nó irmão da antiga raiz
        novoNoIrmaoDaAntigaRaiz->valores[0] = temp[3];
        novoNoIrmaoDaAntigaRaiz->valores[1] = temp[4];
    
        novoNoIrmaoDaAntigaRaiz->filhos[0] = raiz->filhos[3];
        novoNoIrmaoDaAntigaRaiz->filhos[1] = novaSubArvore;
        novoNoIrmaoDaAntigaRaiz->filhos[2] = raiz->filhos[4];


        novoNoIrmaoDaAntigaRaiz->quantidadeValores = 2;
        novoNoIrmaoDaAntigaRaiz->folha = false;

        // arrumando antiga raiz
        raiz->quantidadeValores = 2;

        if (novoNoIrmaoDaAntigaRaiz->filhos[1]->valores[0] > novoNoIrmaoDaAntigaRaiz->valores[1]) {
            novoNoIrmaoDaAntigaRaiz->filhos[1] = raiz->filhos[4];
            novoNoIrmaoDaAntigaRaiz->filhos[2] = novaSubArvore;
        }


        return novaRaizDeTudo;

    }

    return raiz;
}


void imprimeNivel(nodeBPoint raiz, int nivel) {
    if (raiz == nullptr) return;
    if (nivel == 0) {
        for (int i = 0; i < raiz->quantidadeValores; i++) {
            cout << raiz->valores[i] << " ";
        }
    } else {
        for (int i = 0; i < raiz->quantidadeValores + 1; i++) { // Filhos válidos
            imprimeNivel(raiz->filhos[i], nivel - 1);
        }
    }
}

void exibirPorNivel(nodeBPoint raiz) {
    if (raiz == nullptr) {
        cout << "A árvore está vazia." << endl;
        return;
    }

    queue<nodeBPoint> fila;
    fila.push(raiz);

    while (!fila.empty()) {
        int tamanhoNivel = fila.size();

        for (int i = 0; i < tamanhoNivel; i++) {
            nodeBPoint atual = fila.front();
            fila.pop();

            // Exibe os valores do nó atual
            if (atual->quantidadeValores > 0) {
                cout << "[";
                for (int j = 0; j < atual->quantidadeValores; j++) {
                    cout << atual->valores[j];
                    if (j < atual->quantidadeValores - 1) cout << ", ";
                }
                cout << "] ";
            }

            // Adiciona os filhos na fila
            for (int j = 0; j < atual->quantidadeValores + 1; j++) {
                if (atual->filhos[j] != nullptr) {
                    fila.push(atual->filhos[j]);
                }
            }
        }

        cout << endl; // Próximo nível
    }
}

void exibirValoresNo(nodeBPoint no) {
    if (no == nullptr) {
        cout << "Nó vazio." << endl;
        return;
    }

    cout << "Valores do nó: ";
    for (int i = 0; i < no->quantidadeValores; i++) {
        cout << no->valores[i];
        if (i < no->quantidadeValores - 1) cout << ", ";
    }
    cout << endl;

    exibirPorNivel(no->filhos[0]);
}

#endif
