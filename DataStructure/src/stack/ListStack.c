/*
 * ListStack.c
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#include "ListStack.h"

#include <stdio.h>
#include <limits.h>

/**
 * reset the head
 */
void initListStack(ListStack *pStack) {
	pStack->head = NULL;
}

/**
 * check stack's empty.
 * @return
 * 		1: is empty. 0: is not.
 */
int isEmptyListStack(ListStack *pStack) {
	if (pStack->head == NULL) {
		return TRUE;
	}
	return FALSE;
}

/**
 * add Data to top on the Stack
 */
void pushListStack(ListStack *pStack, Data data) {
	ListStackNode *newNode = (ListStackNode *) malloc(sizeof(ListStackNode));
	newNode->data = data;
	newNode->next = pStack->head;

	pStack->head = newNode;
}

/**
 * get Data top on the Stack and remove top element.
 */
Data popListStack(ListStack *pStack) {
	Data topData;
	ListStackNode *topNode;

	if (isEmptyListStack(pStack)) {
		return INT_MIN;
	}

	topNode = pStack->head;
	topData = topNode->data;
	pStack->head = topNode->next;
	free(topNode);

	return topData;
}

/**
 *  get Data top on the Stack and don't remove top element.
 */
Data peekListStack(ListStack *pStack) {
	if (isEmptyListStack(pStack)) {
		return INT_MIN;
	}

	return pStack->head->data;
}
