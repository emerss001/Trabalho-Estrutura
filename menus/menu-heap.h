#ifndef MENU_HEAP_H
#define MENU_HEAP_H

#include <iostream>
#include "../types/type.h"
#include "../arvores/heap.h"
using namespace std;

void menuHeap(heap &heap) {
    int opcao = 0;

    while(opcao != 8) {
        cout << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Inserir valor" << endl;
        cout << "( 2 ) - Remover valor" << endl;
        cout << "( 3 ) - Buscar valor" << endl;
        cout << "( 4 ) - Exibir em Pré-ordem" << endl;
        cout << "( 5 ) - Exibir em Em ordem" << endl;
        cout << "( 6 ) - Exibir em Pós-ordem" << endl;
        cout << "( 7 ) - Exibir Por Nível" << endl;
        cout << "( 8 ) - Voltar" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: {
                int novoValor;
                cout << "Digite o valor a ser inserido: ";
                cin >> novoValor;
                inserir(heap, novoValor);
                cout << endl;
                break;
            }
            
            case 2: {
                removerValor(heap);
                cout << endl;
                break;
            }

            case 3: {
                int valor;
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                buscarValor(heap, valor);
                cout << endl;
                break;
            }

            case 4: {
                cout << "Exibindo em Pré-ordem:" << endl;
                exibirPreOrdem(heap);
                cout << endl;
                break;
            }

            case 5: {
                cout << "Exibindo em Em ordem:" << endl;
                exibirEmOrdem(heap);
                cout << endl;
                break;
            }

            case 6: {
                cout << "Exibindo em Pós-ordem:" << endl;
                exibirPosOrdem(heap);
                cout << endl;
                break;
            }

            case 7: {
                cout << "Exibindo Por Nível:" << endl;
                exibirPorNivel(heap);
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
