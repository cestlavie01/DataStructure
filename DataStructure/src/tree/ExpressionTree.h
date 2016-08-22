/*
 * ExpressionTree.h
 *
 *  Created on: 2016. 8. 22.
 *      Author: cobus
 */

#ifndef TREE_EXPRESSIONTREE_H_
#define TREE_EXPRESSIONTREE_H_

#include "BinaryTree.h"

typedef void VisitFuncPtr(int data);

BinaryTreeNode *makeExpTree(char *exp);
int evaluateExpTree(BinaryTreeNode *tree);

/**
 * 전위 표기법 기반 출력.
 */
void showPrefixTypeExp(BinaryTreeNode *tree);

/**
 * 중위 표기법 기반 출력.
 */
void showInfixTypeExp(BinaryTreeNode *tree);

/**
 * 후위 표기법 기반 출력.
 */
void showPostfixTypeExp(BinaryTreeNode *tree);

#endif /* TREE_EXPRESSIONTREE_H_ */
