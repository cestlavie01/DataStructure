/*
 * ExpressionTree.c
 *
 *  Created on: 2016. 8. 22.
 *      Author: cobus
 */

#include "ExpressionTree.h"

#include "../stack/ListStack.h"

#include <stdio.h>
#include <string.h>

BinaryTreeNode *makeExpTree(char *exp) {

	ListStack stack;
	BinaryTreeNode *node = NULL;
	int expLen = 0, i = 0;

	if (exp == NULL) {
		return NULL;
	}

	expLen = strlen(exp);

	initListStack(&stack);

	for (i = 0; i <expLen; i++) {
		node = makeBinaryTreeNode();

		if (isdigit(exp[i])) { // 피연산자.
			setBTData(node, exp[i] - '0');

		} else { //연산자.
			makeRightSubTree(node, popListStack(&stack));
			makeLeftSubTree(node, popListStack(&stack));
			setBTData(node, exp[i]);
		}

		pushListStack(&stack, node);
	}

	return popListStack(&stack);
}

int evaluateExpTree(BinaryTreeNode *tree) {
	int op1 = 0, op2 = 0;

	// 재귀함수의 탈출 조건, 단말 노드의 경우, 노드 값을 바로 반환한다.
	if (getLeftSubTree(tree) == NULL && getRightSubTree(tree) == NULL) {
		return getBTData(tree);
	}

	op1 = evaluateExpTree(getLeftSubTree(tree));
	op2 = evaluateExpTree(getRightSubTree(tree));

	switch(getBTData(tree)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		if (op2 == 0) {
			return 0;
		} else {
			return op1 / op2;
		}
	default:
		// default는 샘플 코드므로 고려하지 않는다.
		break;
	}

	return 0;
}

void printExpNodeData(int data) {
	if (data >= 0 && data <= 9) {
		printf("%d ", data);
	} else {
		printf("%c ", data);
	}
}

/**
 * 전위 표기법 기반 출력.
 */
void showPrefixTypeExp(BinaryTreeNode *tree) {
	preOrderBinaryTreeTraverse(tree, printExpNodeData);
}

/**
 * 중위 표기법 기반 출력.
 */
void showInfixTypeExp(BinaryTreeNode *tree) {
	inOrderBinaryTreeTraverse(tree, printExpNodeData);
}

/**
 * 후위 표기법 기반 출력.
 */
void showPostfixTypeExp(BinaryTreeNode *tree) {
	postOrderBinaryTreeTraverse(tree, printExpNodeData);
}
