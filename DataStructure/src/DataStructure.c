/*
 ============================================================================
 Name        : DataStructure.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack/ArrayStack.h"
#include "stack/ListStack.h"
#include "queue/ArrayQueue.h"
#include "queue/ListQueue.h"
#include "deque/DoubleLinkedList.h"

#include "stack/MazeArrayStack.h"
#include "queue/MazeQueue.h"

#include "tree/BinaryTree.h"
#include "tree/ExpressionTree.h"

void ArrayStackTest() {
	printf("----- array stack\n");

	ArrayStack as;
	initArrayStack(&as);

	pushArrayStack(&as, 1);
	pushArrayStack(&as, 4);
	pushArrayStack(&as, 2);
	pushArrayStack(&as, 7);

	while (isEmptyArrayStack(&as) == FALSE) {
		printf("%d ", popArrayStack(&as));
	}
	printf("\n");
}

void ListStackTest() {
	printf("----- list stack\n");

	ListStack ls;
	initListStack(&ls);

	pushListStack(&ls, 1);
	pushListStack(&ls, 4);
	pushListStack(&ls, 2);
	pushListStack(&ls, 7);

	while (isEmptyListStack(&ls) == FALSE) {
		printf("%d ", popListStack(&ls));
	}
	printf("\n");
}

void ArrayQueueTest() {
	printf("----- array queue\n");

	ArrayQueue aq;
	initArrayQueue(&aq);

	enqueueArrayQueue(&aq, 1);
	enqueueArrayQueue(&aq, 4);
	enqueueArrayQueue(&aq, 2);
	enqueueArrayQueue(&aq, 7);

	while (isEmptyArrayQueue(&aq) == FALSE) {
		printf("%d ", dequeueArrayQueue(&aq));
	}
	printf("\n");

	isEmptyArrayQueue(&aq);

	enqueueArrayQueue(&aq, 1);
	enqueueArrayQueue(&aq, 4);
	enqueueArrayQueue(&aq, 2);
	enqueueArrayQueue(&aq, 7);

	while (isEmptyArrayQueue(&aq) == FALSE) {
		printf("%d ", dequeueArrayQueue(&aq));
	}
	printf("\n");
}

void ListQueueTest() {
	ListQueue lq;
	initListQueue(&lq);

	printf("----- list queue\n");

	enqueueListQueue(&lq, 1);
	enqueueListQueue(&lq, 4);
	enqueueListQueue(&lq, 2);
	enqueueListQueue(&lq, 7);

	while (isEmptyListQueue(&lq) == FALSE) {
		printf("%d ", dequeueListQueue(&lq));
	}
	printf("\n");
}

void dllDequeTest() {
	DllDeque deque;
	DllDequeNode *node = NULL;
	initDllDeque(&deque);

	printf("----- deque\n");

	addFirstDllDeque(&deque, 1);
	addFirstDllDeque(&deque, 4);
	addFirstDllDeque(&deque, 2);
	addFirstDllDeque(&deque, 7);

	addLastDllDeque(&deque, 9);
	addLastDllDeque(&deque, 8);
	addLastDllDeque(&deque, 7);
	addLastDllDeque(&deque, 6);

	if (isEmptyDllDeque(&deque)) {
		return;
	}

	printf("tail -> head: ");
	node = deque.tail;
	printf("%d ", node->data);
	do {
		node = node->prev;
		printf("%d ", node->data);
	} while (node->prev != NULL);
	printf("\n");

	printf("head -> tail: ");
	node = deque.head;
	printf("%d ", node->data);
	do {
		node = node->next;
		printf("%d ", node->data);
	} while (node->next != NULL);
	printf("\n");


}

void printBTData(BTData data) {
	printf("%d ", data);
}

void basicTreeTest() {
	BinaryTreeNode *bt1 = makeBinaryTreeNode();
	BinaryTreeNode *bt2 = makeBinaryTreeNode();
	BinaryTreeNode *bt3 = makeBinaryTreeNode();
	BinaryTreeNode *bt4 = makeBinaryTreeNode();
	BinaryTreeNode *bt5 = makeBinaryTreeNode();
	BinaryTreeNode *bt6 = makeBinaryTreeNode();

	setBTData(bt1, 1);
	setBTData(bt2, 2);
	setBTData(bt3, 3);
	setBTData(bt4, 4);
	setBTData(bt5, 5);
	setBTData(bt6, 6);

	makeLeftSubTree(bt1, bt2);
	makeRightSubTree(bt1, bt3);
	makeLeftSubTree(bt2, bt4);
	makeRightSubTree(bt2, bt5);
	makeLeftSubTree(bt3, bt6);

	/**
	 * 현재 구조.
	 *         1
	 *      2      3
	 *    4   5  6
	 */
	printf("\n---------------- Binary Tree\n");
	printf("%d\n", getBTData(getLeftSubTree(bt1)));
	printf("%d\n", getBTData(getLeftSubTree(getLeftSubTree(bt1))));

	printf("\n---------------- inOrder Binary Tree\n");
	inOrderBinaryTreeTraverse(bt1, printBTData); // 4 2 5 1 6 3

	printf("\n---------------- preOrder Binary Tree\n");
	preOrderBinaryTreeTraverse(bt1, printBTData); // 1 2 4 5 3 6


	printf("\n---------------- postOrder Binary Tree\n");
	postOrderBinaryTreeTraverse(bt1, printBTData); // 4 5 2 6 3 1
}

void expressionTreeTest() {
	char *exp = "12+7*";
	BinaryTreeNode *tree = makeExpTree(exp);

	printf("\n");

	printf("preOrder: ");
	showPrefixTypeExp(tree);
	printf("\n"); // preOrder: * + 1 2 7

	printf("inOrder: ");
	showInfixTypeExp(tree);
	printf("\n"); // inOrder: 1 + 2 * 7

	printf("postOrder: ");
	showPostfixTypeExp(tree);
	printf("\n"); // postOrder: 1 2 + 7 *

	printf("%s = %d\n", exp, evaluateExpTree(tree)); // 12+7* = 21
}

int main(void) {

	ArrayStackTest();
	ListStackTest();

	ArrayQueueTest();
	ListQueueTest();

	dllDequeTest();

	solveMazeByStack();
	solveMazeByQueue();

	basicTreeTest();
	expressionTreeTest();


	return EXIT_SUCCESS;
}
