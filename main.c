#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "binary_tree.c"

int main() {
    BinaryTree *tree_root = create_tree(); //O conteúdo do ponteiro tree_root recebe o retorno da função
    printf("Endereço de memória de tree_root: %ld\n", (long int) &tree_root);
    printf("Valor de tree_root: %p\n", tree_root);
    printf("Conteúdo de tree_root: %p\n", *tree_root);
    printf("Endereço de memória do conteúdo de tree_root: %ld\n", (long int) &(*tree_root));
    
    if(is_empty(tree_root)) {
        printf("A árvore está vazia!\n");
    }    

    printf("Altura da ávore: %d\n", tree_height(tree_root)); // Passando o endereço do ponteiro de tipo BinaryTree
    printf("O número de elementos da árvore é: %d\n", total_number(tree_root));    
    
    int number[5] = {7, 3, 14, 2, 8};
    int array_size = sizeof number / sizeof number[0];
    printf("\nTamanho do vetor: %d\n", array_size);
    for (int i = 0; i < array_size; i++) {
        int value = insert_value(tree_root, number[i]);
        if (value != 1) {
            printf("Algo deu errado.\n");
        }
    }    

    printf("Pré-ordem:\n");
    pre_order(tree_root);
    printf("Em-ordem:\n");
    in_order(tree_root);
    printf("Pós-ordem:\n");
    post_order(tree_root);    

    printf("Altura da ávore: %d\n", tree_height(tree_root)); // Passando o endereço do ponteiro de tipo BinaryTree
    printf("O número de elementos da árvore é: %d\n", total_number(tree_root));

    free_tree(tree_root);
    
    return 0;
}