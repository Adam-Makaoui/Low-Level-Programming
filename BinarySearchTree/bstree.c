#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

BStree bstree_ini(void){
	BStree bst;
	bst = (BStree) malloc(sizeof(BStree_node **));
	*bst = NULL;
	return bst;

/*
	BStree object = (BStree_node *) malloc(sizeof(BStree_node));
	object->Key = NULL;
	object->Data = NULL;
	object->BStree_node->left = NULL;
	object->BStree_node->right = NULL;
	return object;
*/
}


void bstree_insert_helper(BStree_node *currentNode, Key key, Data data) {

	if (key_comp(key, currentNode->key) > 0) {
		if (currentNode->right != NULL) {
			bstree_insert_helper((BStree_node *) currentNode->right, key, data);
		}
		else{
			 currentNode->right=(struct BStree_node *)new_node(key,data);
		}
	}
	else if (key_comp(key, currentNode->key) < 0) {
		if (currentNode->left != NULL) {
			bstree_insert_helper((BStree_node *) currentNode->left, key, data);
		}
		else{
			 currentNode->left = (struct BStree_node *)new_node(key,data);
		}
	}
}

BStree_node *(BStree_node *currentNode, Key key) {
	if (currentNode == NULL){
		return currentNode;
	}
	else{
		if (key_comp(key, currentNode->key) < 0) {
			return bstree_helper((BStree_node *)currentNode->right, key);
		}
		else if (key_comp( key, currentNode->key) > 0) {
			return bstree_helper((BStree_node *)currentNode->left, key);
		}
	}
}

void bstree_insert(BStree bst, Key key, Data data){
	if (*bst == NULL){
		*bst = new_node(key_gen(key->skey1, key->skey2),data_gen(*data));
	}
	else{
		bstree_insert_helper((*bst), key, data);

	}

}

BStree_node * new_node(Key key, Data data) {
	BStree_node *newNode = (BStree_node *) malloc(sizeof(BStree_node));
	newNode->key = key_gen(key->skey1, key->skey2);
	(newNode->data) = data_gen(*data);
	(*newNode).left = NULL;
	(*newNode).right = NULL;
	return newNode;
}

Data bstree_search(BStree bst, Key key){
	if (*bst == NULL){
		//printf("The Binary Search Tree is empty.");
		return NULL;
	}
	if (key_comp((*bst)->key, key) == 0 ){
		return (*bst)->data;
	}

	else if(key_comp((*bst)->key, key) > 0) {
		bstree_helper((BStree_node *)(*bst)->right, key);
	}
	else if (key_comp((*bst)->key, key) < 0) {
		bstree_helper((BStree_node *)(*bst)->left, key);
	}
}

void bstree_traversal_helper(BStree bst, BStree_node *currentNode){
	if ((currentNode->left) != NULL){
		bstree_traversal_helper(bst, (BStree_node *)currentNode->left);
	}
	if ( (currentNode->key) != NULL && (*bst)->data != NULL){
		printf("\n");
		key_print((currentNode->key));
		printf(" ");
		data_print((*currentNode).data);
	}
	if (currentNode->right != NULL){
		bstree_traversal_helper( bst, (BStree_node *)currentNode->right);
	}

}

void bstree_traversal(BStree bst) {
	if ((*bst) != NULL) {
		bstree_traversal_helper(bst, &**bst);
	}
	else {
		//printf("The Binary Search Tree is Empty!\n");
	}
}

void bstree_free_helper(BStree_node *bt) {
	if ((*bt).left != NULL) {
		bstree_free_helper((BStree_node *)(*bt).left);
	}
	if ((*bt).right != NULL) {
		bstree_free_helper((BStree_node *)(*bt).right);
	}
	if ((*bt).key != NULL) {
		key_free((*bt).key);
	}
	if ((*bt).data != NULL) {
		data_free((*bt).data);
	}
	free(bt);

}

void bstree_free(BStree bst){
	if (*bst != NULL) {
		bstree_free_helper(&(**bst));
	}
	free(bst);
}
