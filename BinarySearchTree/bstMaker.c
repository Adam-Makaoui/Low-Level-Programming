/**
 * This class creates a bst given any data
 *
 * @author Adam M., 250726961
 */

#include <stdio.h>
#include "bst.h"

    int main(void)
    {
        BStree bst; //pointer to the BST
        int size, id, data;
        char quit, name[256];

        printf("Enter the size of the tree: \n");
        scanf("%d", &size);
        bst = bstree_ini(size); //creating the bst

        //printf("Enter ");

        while (scanf("%s %d %d", name, &id, &data)==3) {
            printf("enter the new key (str) then the data (int) separated by whitespace: \n");
            bstree_insert(bst, key_construct(name,id), data);
            printf("Add was successful!\n");

            printf("Enter Q/q if you wish to stop inserting \n");
            scanf(" %c", &quit);
            if(quit == 'Q' || quit == 'q')
                break;

        }
        bstree_traversal(bst);
        bstree_free(bst);

        return 0;
    }
