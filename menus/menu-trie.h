#ifndef MENU_TRIE_H
#define MENU_TRIE_H

#include <iostream>
#include <string>
#include "../types/type.h"
#include "../arvores/trie.h"
using namespace std;

void menuTrie(nodeTriePoint &raiz) {
    if (raiz == nullptr) {
    raiz = new nodeTrie(); // Cria uma nova raiz se ela ainda não existir
    }

    int opcao;

    while(opcao != 4) {
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Adicionar palavra" << endl;
        cout << "( 2 ) - Buscar palavra" << endl;
        cout << "( 3 ) - Buscar por prefixo" << endl;
        cout << "( 4 ) - Voltar" << endl;
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: {
                string novaPalavra;
                cout << "Digite a palavra a ser adicionada: ";
                cin >> novaPalavra;
                inserirPalavra(raiz, novaPalavra);
                cout << endl;
                break;
            }
            
            case 2: {
                string palavra;
                cout << "Digite a palavra a ser buscada: ";
                cin >> palavra;
                buscar(raiz, palavra);
                cout << endl;
                break;
            }

            case 3: {
                string prefixo;
                cout << "Digite o prefixo a ser buscado: ";
                cin >> prefixo;
                buscarPorPrefixo(raiz, prefixo);
                cout << endl;
                break;
            }

            case 4: {
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
