/*
 * ArrayStack.h
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#ifndef SRC_STACK_ARRAYSTACK_H_
#define SRC_STACK_ARRAYSTACK_H_

#define STACK_LEN 100
#define TOP_INDEX_EMTPY -1

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _arrayStack {
	Data stackArray[STACK_LEN];
	int topIndex;
} ArrayStack;

void initArrayStack(ArrayStack *pStack);
int isEmptyArrayStack(ArrayStack *pStack);

void pushArrayStack(ArrayStack *pStack, Data data);
Data popArrayStack(ArrayStack *pStack);
Data peekArrayStack(ArrayStack *pStack);

#endif /* SRC_STACK_ARRAYSTACK_H_ */
