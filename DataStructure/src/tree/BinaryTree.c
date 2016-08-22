/*
 * ArrayMap.cpp
 *
 *  Created on: 2016. 8. 22.
 *      Author: cobus
 */

#include "BinaryTree.h"

#include <stdio.h>
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

void deleteBinaryTree(BinaryTreeNode *tree) {
	if (tree == NULL) {
		return;
	}

	deleteBinaryTree(tree->left);
	deleteBinaryTree(tree->right);

	printf("delete tree data: %d\n", tree->data);
	free(tree);
}

/**
 * 단순히 왼쪽, 오른쪽 subTree를 free하게 되면,
 * 하위에 있는 subTree 해제가 되지 않아 메모리 누수가 발생하게된다.
 */
void makeLeftSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree) {
	if (mainTree->left != NULL) {
//		free(mainTree->left); // 이 경우, leftSubTree에 하위 tree가 존재할 경우 memory leak 발생.
		deleteBinaryTree(mainTree->left);
	}

	mainTree->left = subTree;
}

void makeRightSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree) {
	if (mainTree->right != NULL) {
//		free(mainTree->right);
		deleteBinaryTree(mainTree->right);
	}

	mainTree->right = subTree;
}

/*
 * 중위 순회.
 *
 * leftSubTree -> node -> rightSubTree
 */
void inOrderBinaryTreeTraverse(BinaryTreeNode *tree, visitActionFuncPtr action) {
	if (tree == NULL) {
		return;
	}

	inOrderBinaryTreeTraverse(tree->left, action);
	action(tree->data);
	inOrderBinaryTreeTraverse(tree->right, action);
}

/**
 * 전위 순회.
 *
 * node -> leftSubTree -> rightSubTree
 */
void preOrderBinaryTreeTraverse(BinaryTreeNode *tree, visitActionFuncPtr action) {
	if (tree == NULL) {
		return;
	}

	action(tree->data);
	preOrderBinaryTreeTraverse(tree->left, action);
	preOrderBinaryTreeTraverse(tree->right, action);
}

/**
 * 후위 순회.
 *
 * leftSubTree -> rightSubTree -> node
 */
void postOrderBinaryTreeTraverse(BinaryTreeNode *tree,
		visitActionFuncPtr action) {
	if (tree == NULL) {
		return;
	}

	postOrderBinaryTreeTraverse(tree->left, action);
	postOrderBinaryTreeTraverse(tree->right, action);
	action(tree->data);
}
