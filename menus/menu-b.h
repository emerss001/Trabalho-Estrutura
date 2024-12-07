#ifndef MENU_B_H
#define MENU_B_H

#include <iostream>
#include "../types/type.h"
#include "../arvores/b.h"

void menuB(nodeBPoint &raiz) {
    int opcao = 0;

    while (opcao != 8) {
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
                raiz = inserirValorB(raiz, novoNo);
                cout << endl;
                break;
            }

            case 7: {
                cout << "Exibindo Por Nível:" << endl;
                exibirPorNivel(raiz);
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