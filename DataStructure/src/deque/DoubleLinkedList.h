/*
 * DoubleLinkedList.h
 *
 *  Created on: 2016. 6. 26.
 *      Author: cobus
 */

#ifndef DEQUE_DOUBLELINKEDLIST_H_
#define DEQUE_DOUBLELINKEDLIST_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _dllDequeNode {
	Data data;
	struct _dllDequeNode *next;
	struct _dllDequeNode *prev;
} DllDequeNode;

typedef struct _dllDeque {
	DllDequeNode *head;
	DllDequeNode *tail;
} DllDeque;

typedef DllDeque Deque;

void initDllDeque(Deque *deque);
int isEmptyDllDeque(Deque *deque);

void addFirstDllDeque(Deque *deque, Data data);
void addLastDllDeque(Deque *deque, Data data);

Data removeFirstDllDeque(Deque *deque);
Data removeLastDllDeque(Deque *deque);

Data getFirstDllDeque(Deque *deque);
Data getLastDllDeque(Deque *deque);

#endif /* DEQUE_DOUBLELINKEDLIST_H_ */
