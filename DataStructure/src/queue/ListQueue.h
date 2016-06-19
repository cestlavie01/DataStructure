/*
 * ListQueue.h
 *
 *  Created on: 2016. 6. 19.
 *      Author: cobus
 */

#ifndef QUEUE_LISTQUEUE_H_
#define QUEUE_LISTQUEUE_H_

#define FALSE 0
#define TRUE 1

typedef int Data;

typedef struct _listQueueNode {
	Data data;
	struct _listQueueNode *next;
} ListQueueNode;

typedef struct _listQueue {
	ListQueueNode *front;
	ListQueueNode *rear;
} ListQueue;

void initListQueue(ListQueue *pQ);
int isEmptyListQueue(ListQueue *pQ);

void enqueueListQueue(ListQueue *pQ, Data data);
Data dequeueListQueue(ListQueue *pQ);
Data peekListQueue(ListQueue *pQ);

#endif /* QUEUE_LISTQUEUE_H_ */
