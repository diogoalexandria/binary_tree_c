#ifndef BINARY_TREE
#define BYNARY_TREE

typedef struct NODE *BinaryTree;

BinaryTree* create_tree();
void free_tree(BinaryTree* root);
int is_empty(BinaryTree* root);
int tree_height(BinaryTree* root);
int total_number(BinaryTree* root);
void pre_order(BinaryTree* root);
int insert_node(BinaryTree*, int value);
void pre_order(BinaryTree* root);
void in_order(BinaryTree* root);
void post_order(BinaryTree* root);

#endif
