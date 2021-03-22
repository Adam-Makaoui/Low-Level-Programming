/**
 * This class defines variables and methods for bst.c
 *
 * @author Ahmed Attar, 250726961
 */

#include "data.h"

typedef struct {
    Node *tree_nodes; //Node =  [Key *key =(name, id), int data] THIS IS THE ARRAY containting DATA
    unsigned char *is_free; //ints from 0-255 //this is the ARRAY to hold if it's free or not
    int size;
} BStree_struct; // defining a BStree data type

typedef BStree_struct* BStree; //defining a pointer of type "BStree_struct"


/*------FUNCTIONS TO IMPLEMENT----*/

BStree bstree_ini(int size);

void bstree_insert(BStree bst, Key *key, int data);

void bstree_traversal(BStree bst);

void bstree_free(BStree bst);

//// Helpers - START/////
int rightChild(int loc);

int leftChild(int loc);

int bstRootPos ();

void set_data(BStree bst, Key *key, int data, int index);

void inorder_print_traversal(BStree bst, int pos);

void recursive_insert(BStree bst, Key *key, int data, int index);

void do_nothing();
//// Helpers - END/////