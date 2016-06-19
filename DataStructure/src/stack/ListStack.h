/*
 * ListStack.h
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#ifndef SRC_STACK_LISTSTACK_H_
#define SRC_STACK_LISTSTACK_H_

#define STACK_LEN 100
#define TOP_INDEX_EMTPY -1

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _listStackNode {
	Data data;
	struct _listStackNode *next;
} ListStackNode;

typedef struct _listStack {
	ListStackNode *head;
} ListStack;

void initListStack(ListStack *pStack);
int isEmptyListStack(ListStack *pStack);

void pushListStack(ListStack *pStack, Data data);
Data popListStack(ListStack *pStack);
Data peekListStack(ListStack *pStack);

#endif /* SRC_STACK_LISTSTACK_H_ */
