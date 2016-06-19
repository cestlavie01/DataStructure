/*
 * ListQueue.c
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */


#include "ListQueue.h"

#include <stdio.h>
#include <limits.h>

/**
 * reset front and rear index.
 */
void initListQueue(ListQueue *pQ) {
	pQ->front = NULL;
	pQ->rear = NULL;
}

/**
 * check whether queue is empty.
 */
int isEmptyListQueue(ListQueue *pQ) {
	if (pQ->front == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * push the data in queue
 */
void enqueueListQueue(ListQueue *pQ, Data data) {
	ListQueueNode *newNode = (ListQueueNode *) malloc (sizeof(ListQueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (pQ->front == NULL) {
		pQ->front = newNode;
	} else {
		pQ->rear->next = newNode;
	}

	pQ->rear = newNode;
}

/**
 * get and remove front data.
 */
Data dequeueListQueue(ListQueue *pQ) {
	Data returnData = 0;
	ListQueueNode *oldFrontNode = NULL;

	if (isEmptyListQueue(pQ)) {
		return INT_MIN;
	}

	oldFrontNode = pQ->front;
	returnData = oldFrontNode->data;
	pQ->front = oldFrontNode->next;

	free(oldFrontNode);

	return returnData;
}

/**
 * only get front data.
 */
Data peekListQueue(ListQueue *pQ) {
	Data returnData;

	if (isEmptyListQueue(pQ)) {
		return INT_MIN;
	}

	return pQ->front->data;
}
