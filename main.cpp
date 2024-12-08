#include <iostream>
#include "./menus/menu-binaria.h"
#include "./menus/menu-binaria-busca.h"
#include "./menus/menu-avl.h"
#include "./arvores/binarias/funcoes-compartilhadas.h"
#include "./menus/menu-b.h"
#include "./menus/menu-trie.h"
using namespace std;

int main() {
    int opcao = 0;
    nodePoint raiz = nullptr;
    nodeBPoint raizB = nullptr;
    nodeTriePoint raizTrie = nullptr;


    while (opcao != 6) {
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Árvore Binária Genérica" << endl;
        cout << "( 2 ) - Árvore Binária de Busca" << endl;
        cout << "( 3 ) - Árvore AVL" << endl;
        cout << "( 4 ) - Árvore B" << endl;
        cout << "( 5 ) - ÁRvore Trie" << endl;
        cout << "( 6 ) - Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                menuBinaria(raiz);
                break;
            }

            case 2: {
                nodePoint raizBB = nullptr;
                menuBinariaBusca(raizBB);
                break;
            }

            case 3: {
                nodeAVLPoint raizAVL = nullptr;
                menuAvl(raizAVL);
                break;
            }

            case 4: {
                menuB(raizB);
                break;
            }

            case 5: {
                menuTrie(raizTrie);
                break;
            }

           
        }
    }

    return 0;
}