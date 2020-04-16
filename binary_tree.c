#include <stdio.h>
#include <stdlib.h> 
#include "binary_tree.h"

typedef struct NODE {
    int info;
    struct NODE *left;
    struct NODE *right;    
} Node;

BinaryTree* create_tree() {
    BinaryTree *root = (BinaryTree*) malloc(sizeof(BinaryTree));
    if (root != NULL)  
        *root = NULL;
    
    return root;
}

int tree_exist(BinaryTree* root) {
    if(root == NULL)
        return 0;
    
    return 1;
}

int is_empty(BinaryTree* root) {
    if (!tree_exist(root)) {
        printf("A árvore pode não ter sido inicializada.\n");
        return 1;
    }    
    if (*root == NULL) // Se o conteúdo do ponteiro root que é NULL
        return 1;

    return 0;
}

void free_node(Node* node) { // Espera um ponteiro para Node, inicialmente o valor do BinaryTree que é um ponteiro para Node
    if (node == NULL)
        return;
    
    free_node(node->left);
    free_node(node->right);
    free(node);
    node = NULL;
}

void free_tree(BinaryTree* root) {
    if (root == NULL)
        return;
    
    free_node(*root); // Valor do ponteiro root, que é um ponteiro para um Node, é passado como parâmetro
}

int tree_height(BinaryTree* root) { //Recebe o conteúdo do ponteiro, no caso o endereço de BinaryTree
    if (is_empty(root))
        return 0;

    int left_height = tree_height(&((*root)->left)); // Endereço do nó da esquerda do nó root
    int right_height = tree_height(&((*root)->right)); // tree_height(&((*root)->right));
    if (left_height > right_height)
        return (left_height + 1);
    else
        return(right_height + 1);
}

int total_number(BinaryTree* root) { // Retorna o total de elementos na árvore;
    if (is_empty(root))
        return 0;
    
    int number_left = total_number(&((*root)->left));
    int number_right = total_number(&(*root)->right);
    int total = number_left + number_right + 1;
    return total;
}

void pre_order(BinaryTree* root) {
    if (is_empty(root)) {        
        return;
    }    
    printf("%d\n",(*root)->info);
    pre_order(&((*root)->left));    
    pre_order(&((*root)->right));
}

void in_order(BinaryTree* root) {
    if (is_empty(root)){        
        return;
    }
    in_order(&((*root)->left));
    printf("%d\n",(*root)->info);
    in_order(&((*root)->right));
}

void post_order(BinaryTree* root) {
    if (is_empty(root)) {        
        return;
    }
    post_order(&((*root)->left));
    post_order(&((*root)->right));
    printf("%d\n",(*root)->info);
}

Node* create_node(int value) {
    Node *new = (Node*) malloc (sizeof(Node));
    if (new != NULL){
        new->info = value;
        new->right = NULL;
        new-> left = NULL;                
    } else {
        printf("Houve um erro na criação do nó.\n");        
    }
    return new;
}

int insert_node(BinaryTree* root, int value) {
    if(!tree_exist(root)) {
        printf("A árvore pode não ter sido inicializada.\n");
        return 0;
    }    
    if (*root == NULL) {
        *root = create_node(value);
        printf("Novo nó inserido: %d\n", value);
        return 1;        
    }
    if ((*root)->info > value) {                
        insert_node(&((*root)->left), value);
    } else {              
        insert_node(&((*root)->right), value);
    }
    return 1;    
}
