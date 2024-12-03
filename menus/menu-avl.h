#ifndef MENU_AVL_H
#define MENU_AVL_H

#include <iostream>
#include "../types/type.h"
#include "../arvores/binarias/avl.h"
#include "../arvores/binarias/funcoes-compartilhadas.h"
using namespace std;


void menuAvl(nodeAVLPoint &raiz) {
    int opcao;

    while(opcao != 8) {
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Adicionar nó" << endl;
        cout << "( 2 ) - Remover nó" << endl;
        cout << "( 3 ) - Buscar nó" << endl;
        cout << "( 4 ) - Exibir em Pré-ordem" << endl;
        cout << "( 5 ) - Exibir em Em ordem" << endl;
        cout << "( 6 ) - Exibir em Pós-ordem" << endl;
        cout << "( 7 ) - Exibir Por Nível" << endl;
        cout << "( 8 ) - Voltar" << endl;
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: {
                int novoNo;
                cout << "Digite o valor do nó: ";
                cin >> novoNo;
                raiz = AVLAdicionarNo(raiz, criaNovoNoAVL(novoNo));
                cout << endl;
                break;
            }
            
            case 2: {
                int remover;
                cout << "Digite o valor do nó a ser removido: ";
                cin >> remover;
                raiz = AVLRemoverNo(raiz, remover);
                if (raiz != NULL) {
                    cout << "Nó removido com sucesso." << endl;
                } else {
                    cout << "Nó não encontrado." << endl;
                }
                break;
            }

            case 3: {
                int valor;
                cout << "Digite o valor do nó a ser buscado: ";
                cin >> valor;
                nodeAVLPoint noBuscado = AVLbuscaNo(raiz, valor);
                if (noBuscado != NULL) {
                    cout << "Nó encontrado: " << noBuscado->valor << " no endereço " << noBuscado << endl;
                } else {
                    cout << "Nó não encontrado." << endl;
                }
                break;
            }

            case 4: {
                cout << "Exibindo em Pré-ordem:" << endl;
                preOrdem(raiz);
                cout << endl;
                break;
            }

            case 5: {
                cout << "Exibindo em Em ordem:" << endl;
                emOrdem(raiz);
                cout << endl;
                break;
            }

            case 6: {
                cout << "Exibindo em Pós-ordem:" << endl;
                posOrdem(raiz);
                cout << endl;
                break;
            }

            case 7: {
                cout << "Exibindo Por Nível:" << endl;
                porNivel(raiz);
                cout << endl;
                break;
            }

            case 8: {
                cout << "Voltando..." << endl;
                break;
            }

            default: {
                cout << "Opção inválida. Tente novamente." << endl;
                break;
            }
           
        }

    }
    
}

#endif
