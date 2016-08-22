/*
 * ArrayMap.h
 *
 *  Created on: 2016. 8. 22.
 *      Author: cobus
 */

#ifndef TREE_BINARYTREE_H_
#define TREE_BINARYTREE_H_

typedef int BTData;

typedef struct _BinaryTreeNode {
	BTData data;
	struct _BinaryTreeNode *left;
	struct _BinaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode *makeBinaryTreeNode();
BTData getBTData(BinaryTreeNode *tree);
void setBTData(BinaryTreeNode *tree, BTData data);

BinaryTreeNode *getLeftSubTree(BinaryTreeNode *tree);
BinaryTreeNode *getRightSubTree(BinaryTreeNode *tree);

void makeLeftSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree);
void makeRightSubTree(BinaryTreeNode *mainTree, BinaryTreeNode *subTree);

#endif /* TREE_BINARYTREE_H_ */
