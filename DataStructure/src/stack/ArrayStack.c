/*
 * ArrayStack.c
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#include "ArrayStack.h"

#include <stdio.h>
#include <limits.h>

/**
 * reset the top index.
 */
void initArrayStack(ArrayStack *pStack) {
	pStack->topIndex = -1;
}

/**
 * check stack's empty.
 * @return
 * 		1: is empty. 0: is not.
 */
int isEmptyArrayStack(ArrayStack *pStack) {
	if (pStack->topIndex == TOP_INDEX_EMTPY) {
		return TRUE;
	}
	return FALSE;
}

/**
 * add Data to top on the Stack
 */
void pushArrayStack(ArrayStack *pStack, Data data) {
	if (pStack->topIndex >= STACK_LEN - 1) {
		printf("Stack is full. can not added.\n");
		return ;
	}

	pStack->topIndex++;
	pStack->stackArray[pStack->topIndex] = data;
}

/**
 * get Data top on the Stack and remove top element.
 */
Data popArrayStack(ArrayStack *pStack) {
	if (isEmptyArrayStack(pStack)) {
		return INT_MIN;
	}

	pStack->topIndex--;
	return pStack->stackArray[pStack->topIndex + 1];
}

/**
 *  get Data top on the Stack and don't remove top element.
 */
Data peekArrayStack(ArrayStack *pStack) {
	if (isEmptyArrayStack(pStack)) {
		return INT_MIN;
	}

	return pStack->stackArray[pStack->topIndex];
}
