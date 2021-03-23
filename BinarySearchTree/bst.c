/**
 * This class contains methods for constructing a bst
 *
 * @author Adam M., 250726961
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/**
 * The method that creates a data structure BStree by allocating space
 *
 * @param size - the size of the array
 * @return the pointer of type BStree which points to a "tree"
 */
BStree bstree_ini(int size){

BStree tree;
int i;

tree = (BStree) malloc(sizeof(BStree_struct)); //providing memory for the bst
tree->tree_nodes = (Node *) malloc( (size+1)* sizeof(Node)); // always cast return value since mealloc return type is void
tree->is_free = (unsigned char *) malloc((size+1) * sizeof(unsigned char));

tree->size = size;
for (i = 0; i<=size; i++)
    tree->is_free[i]='1';

return tree; // pointer of type BStree (which is a pointer)
}
/**
 * This method so called "traverses" the bst using all the helpers that actually do all the work
 *
 * @param bst -
 * @param key
 * @param data
 */
void bstree_insert(BStree bst, Key *key, int data){
    recursive_insert(bst, key, data, bstRootPos());
}

void bstree_traversal(BStree bst){ //left, myself, right PRINTS ITEMS
    inorder_print_traversal(bst, bstRootPos()); //starts at root
}

/**
 * Removes the memory allocated towards the bst, and thr two arrays
 *
 * @param bst - the binary search tree
 */
void bstree_free(BStree bst){
    free(bst->is_free); //freeing the array of 1's
    free(bst->tree_nodes); //freeing the array of key and data
    free(bst); //freeing root (Must be done last as it points to the structure that contains is_free & tree_nodes)
}

int rightChild(int loc) {
    return ((loc*2)+1);
}

int leftChild(int loc) {
    return ((loc*2));
}
/**
 * A method that does nothing
 */
void do_nothing(){
    ; }

/**
 * @return 1 - An integer which repr the root in our array
 */
int bstRootPos () {
    return 1; }

/**
 *
 * @param bst
 * @param key
 * @param data
 * @param index
 */
void set_data(BStree bst, Key *key, int data, int index) {
        bst->tree_nodes[index].key = key;
        bst->tree_nodes[index].data = data;
        bst->is_free[index] = '0'; //setting flag to empty
    }
/**
 *
 * @param bst
 * @param key
 * @param data
 * @param index
 */
void recursive_insert(BStree bst, Key *key, int data, int index) {
    if (index > bst->size || index < 0) {  // Array out of bounds
        printf("Error, array out of bounds");
        exit(0);
    }
    else if (bst->is_free[index] == '1') {
        set_data(bst, key, data, index); }
    else {
        /// if DUPLICATE DATA, don't do anything if so
        int cmp = key_comp(*(key), *(bst->tree_nodes[index].key));
        if (cmp == 0) {
            do_nothing(); } // do nothing

            ///RE-DO INSERTION TO left child
        else if (cmp < 0)
            recursive_insert(bst, key, data, leftChild(index));

            ///RE-DO INSERTION TO right child
        else
            recursive_insert(bst, key, data, rightChild(index));
    }
}

/* ------HELPER METHOD------ */
    void inorder_print_traversal(BStree bst, int pos) {
        if (bst->is_free[pos] != '1') { ///checking an item exists (hence so we can traverse on it)

            inorder_print_traversal(bst, leftChild(pos));
            print_node(bst->tree_nodes[pos]); ///printing out current (pos 'i')
            inorder_print_traversal(bst, rightChild(pos));

        }
    }
