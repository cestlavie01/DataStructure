/*
 * ArrayStack.h
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#ifndef SRC_STACK_ARRAYSTACK_H_
#define SRC_STACK_ARRAYSTACK_H_

#define STACK_LEN 100;

typedef int Data;

typedef struct _arrayStack {
	Data stackArray[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void stackInit(Stack *pStack);
int isEmptyStack(Stack *pStack);

void pushStack(Stack *pStack, Data data);
Data popStack(Stack *pStack);
Data peekStack(Stack *pStack);

#endif /* SRC_STACK_ARRAYSTACK_H_ */
