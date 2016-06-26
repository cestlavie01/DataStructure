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

int main(void) {

	ArrayStackTest();
	ListStackTest();

	ArrayQueueTest();
	ListQueueTest();

	dllDequeTest();

	solveMazeByStack();
	solveMazeByQueue();


	return EXIT_SUCCESS;
}
