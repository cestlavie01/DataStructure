/*
 * ArrayQueue.h
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 *
 * NOTICE: queue front is always empty and circular Queue.
 */

#ifndef QUEUE_ARRAYQUEUE_H_
#define QUEUE_ARRAYQUEUE_H_

#define ARRAY_LEN 4

#define FALSE 0
#define TRUE 1

typedef int Data;

typedef struct _arrayQueue {
	int front;
	int rear;
	Data queueArrary[ARRAY_LEN];
} ArrayQueue;

void initArrayQueue(ArrayQueue *pQ);
int isEmptyArrayQueue(ArrayQueue *pQ);

void enqueueArrayQueue(ArrayQueue *pQ, Data data);
Data dequeueArrayQueue(ArrayQueue *pQ);
Data peekArrayQueue(ArrayQueue *pQ);

#endif /* QUEUE_ARRAYQUEUE_H_ */
