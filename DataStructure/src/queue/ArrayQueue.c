/*
 * ArrayQueue.c
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#include "ArrayQueue.h"

#include <stdio.h>
#include <limits.h>

/**
 * reset front and rear index.
 */
void initArrayQueue(ArrayQueue *pQ) {
	pQ->front = 0;
	pQ->rear = 0;
}

/**
 * check whether queue is empty.
 */
int isEmptyArrayQueue(ArrayQueue *pQ) {
	if (pQ->front == pQ->rear) {
		return TRUE;
	}

	return FALSE;
}

/**
 * calculate the argument index's next position.
 */
int getNextIndex(int index) {
	if (index >= ARRAY_LEN -1) {
		return 0;
	} else {
		return index + 1;
	}
}

/**
 * push the data in queue
 */
void enqueueArrayQueue(ArrayQueue *pQ, Data data) {
	if (pQ->front == getNextIndex(pQ->rear)) {
		printf("Queue is full.\n");
		return;
	}

	pQ->rear++;
	if (pQ->rear >= ARRAY_LEN) {
		pQ->rear = 0;
	}

	pQ->queueArrary[pQ->rear] = data;
}

/**
 * get and remove front data.
 */
Data dequeueArrayQueue(ArrayQueue *pQ) {
	if (isEmptyArrayQueue(pQ)) {
		return INT_MIN;
	}

	pQ->front = getNextIndex(pQ->front);

	return pQ->queueArrary[pQ->front];
}

/**
 * only get front data.
 */
Data peekArrayQueue(ArrayQueue *pQ) {
	int frontIndex = 0;

	if (isEmptyArrayQueue(pQ)) {
		return INT_MIN;
	}

	return pQ->queueArrary[getNextIndex(pQ->front)];
}
