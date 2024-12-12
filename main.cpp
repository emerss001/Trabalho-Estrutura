#include <iostream>
#include "./menus/menu-binaria.h"
#include "./menus/menu-binaria-busca.h"
#include "./menus/menu-avl.h"
#include "./arvores/binarias/funcoes-compartilhadas.h"
#include "./menus/menu-b.h"
#include "./menus/menu-trie.h"
#include "./menus/menu-heap.h"
using namespace std;

int main() {
    int opcao = 0;
    nodePoint raiz = nullptr;
    nodeBPoint raizB = nullptr;
    nodePoint raizBB = nullptr;
    nodeAVLPoint raizAVL = nullptr;
   
    nodeTriePoint raizTrie = nullptr;
    heap Treeheap;


    while (opcao != 7) {
        cout << "Escolha uma opção:" << endl;
        cout << "( 1 ) - Árvore Binária Genérica" << endl;
        cout << "( 2 ) - Árvore Binária de Busca" << endl;
        cout << "( 3 ) - Árvore AVL" << endl;
        cout << "( 4 ) - Árvore B" << endl;
        cout << "( 5 ) - Árvore Trie" << endl;
        cout << "( 6 ) - Árvore Heap Máxima" << endl;
        cout << "( 7 ) - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                menuBinaria(raiz);
                break;
            }

            case 2: {
                menuBinariaBusca(raizBB);
                break;
            }

            case 3: {
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

            case 6: {
                menuHeap(Treeheap);
                break;
            }

            case 7: {
                cout << "Saindo..." << endl;
                break;
            }

            default: {
                cout << "Opção inválida. Tente novamente." << endl;
                break;
            }

           
        }
    }

    return 0;
}