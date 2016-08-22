/*
 * ArrayMap.cpp
 *
 *  Created on: 2016. 8. 22.
 *      Author: cobus
 */

#include "BinaryTree.h"

#include <stdlib.h>

BinaryTreeNode *makeBinaryTreeNode() {
	BinaryTreeNode *node = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTData getBTData(BinaryTreeNode *tree) {
	return tree->data;
}

void setBTData(BinaryTreeNode *tree, BTData data) {
	tree->data = data;
}

BinaryTreeNode *getLeftSubTree(BinaryTreeNode *tree) {
	return tree->left;
}

BinaryTreeNode *getRightSubTree(BinaryTreeNode *tree) {
	return tree->right;
}

/**
 * 단순히 왼쪽, 오른쪽 subTree를 free하게 되면,
 * 하위에 있는 subTree 해제가 되지 않아 메모리 누수가 발생하게된다.
 */
void makeLeftSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree) {
	if (mainTree->left != NULL) {
		free(mainTree->left);
	}

	mainTree->left = subTree;
}

void makeRightSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree) {
	if (mainTree->right != NULL) {
		free(mainTree->right);
	}

	mainTree->right = subTree;
}
