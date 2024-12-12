#ifndef MENU_B_H
#define MENU_B_H

#include <iostream>
#include "../types/type.h"
#include "../arvores/b.h"

void menuB(nodeBPoint &raiz) {
    int opcao = 0;

    while (opcao != 7) {
         cout << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Adicionar um valor" << endl;
        cout << "( 2 ) - Buscar nó" << endl;
        cout << "( 3 ) - Exibir em Pré-ordem" << endl;
        cout << "( 4 ) - Exibir em Em ordem" << endl;
        cout << "( 5 ) - Exibir em Pós-ordem" << endl;
        cout << "( 6 ) - Exibir Por Nível" << endl;
        cout << "( 7 ) - Voltar" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: {
                int novoNo;
                cout << "Digite o valor a ser adicionado: ";
                cin >> novoNo;
                raiz = inserirValorB(raiz, novoNo);
                if (raiz != NULL) {
                    cout << "Valor adicionado com sucesso." << endl;
                } else {
                    cout << "Erro ao adicionar valor." << endl;
                }
                cout << endl;
                break;
            }

            case 2: {
                int valor;
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                buscarValorB(raiz, valor);
                cout << endl;
                break;
            }

            case 3: {
                cout << "Exibindo em Pré-ordem:" << endl;
                preOrdemB(raiz);
                cout << endl;
                break;
            }

            case 4: {
                cout << "Exibindo em Em ordem:" << endl;
                emOrdemB(raiz);
                cout << endl;
                break;
            }

            case 5: {
                cout << "Exibindo em Pós-ordem:" << endl;
                posOrdemB(raiz);
                cout << endl;
                break;
            }

            case 6: {
                cout << "Exibindo Por Nível:" << endl;
                exibirPorNivel(raiz);
                cout << endl;
                break;
            }

            case 7: {
                cout << "Voltando..." << endl;
                cout << endl;
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