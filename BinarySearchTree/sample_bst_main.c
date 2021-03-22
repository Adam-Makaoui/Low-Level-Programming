/**
 * This class creates a sample bst from a given set of data
 *
 * @author Ahmed Attar, 250726961
 */

#include <stdio.h>
#include "bst.h"

int main(void) {
    BStree bst; //pointer to the BST

    bst = bstree_ini(1000); //creating a try of 1000 memory slots

    bstree_insert(bst, key_construct("Once", 1),      11);
    bstree_insert(bst, key_construct("Upon", 22),      2);
    bstree_insert(bst, key_construct("a", 3),         33);
    bstree_insert(bst, key_construct("Time", 4),      44);
    bstree_insert(bst, key_construct("is", 5),        55);
    bstree_insert(bst, key_construct("filmed", 6),    66);
    bstree_insert(bst, key_construct("in", 7),        77);
    bstree_insert(bst, key_construct("Vancouver", 8), 88);
    bstree_insert(bst, key_construct("!", 99),         9);
    bstree_insert(bst, key_construct("Once", 5),      50);
    bstree_insert(bst, key_construct("Once", 1),      10);

    bstree_traversal(bst);

    bstree_free(bst);

    return 0;
}