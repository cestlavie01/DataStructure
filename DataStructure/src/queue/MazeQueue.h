/*
 * MazeQueue.h
 *
 *  Created on: 2016. 6. 26.
 *      Author: cobus
 */

#ifndef QUEUE_MAZEQUEUE_H_
#define QUEUE_MAZEQUEUE_H_

#include <limits.h>

#define TRUE 1
#define FALSE 0

#define ROAD_NOT_TAKEN 0
#define WALL 1

#define MAZE_SIZE 5

#define START INT_MAX
#define GOAL INT_MIN

int maze_q[MAZE_SIZE][MAZE_SIZE] = {
		{ 1, 1, 1, 1, 1 },
		{ START, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, GOAL },
		{ 1, 1, 1, 1, 1 }
};

typedef struct _qposition {
	int x;
	int y;
} QPosition;

typedef struct _mazeQueueNode {
	QPosition data;
	struct _mazeQueueNode *next;
} MazeQueueNode;

typedef struct _mazeListQueue {
	MazeQueueNode *front;
	MazeQueueNode *rear;
} MazeListQueue;

enum DIRECTION {
	East, West, South, North
};

/**
 * reset front and rear index.
 */
void initMazeListQueue(MazeListQueue *pQ, QPosition *start) {
	int x, y, isBreak = 0;

	pQ->front = NULL;
	pQ->rear = NULL;

	for (y = 0; y < MAZE_SIZE; y++) {
		for (x = 0; x < MAZE_SIZE; x++) {
			if (maze_q[y][x] == START) {
				start->x = x;
				start->y = y;
				isBreak = 1;
				break;
			}
		}

		if (isBreak) {
			break;
		}
	}
}

/**
 * check whether queue is empty.
 */
int isEmptyMazeListQueue(MazeListQueue *pQ) {
	if (pQ->front == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * push the data in queue
 */
void enqueueMazeListQueue(MazeListQueue *pQ, QPosition data) {
	MazeQueueNode *newNode = (MazeQueueNode *) malloc(sizeof(MazeQueueNode));
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
QPosition dequeueMazeListQueue(MazeListQueue *pQ) {
	QPosition returnData;
	MazeQueueNode *oldFrontNode = NULL;

	if (isEmptyMazeListQueue(pQ)) {
		QPosition errData;
		errData.x = INT_MIN;
		errData.y = INT_MIN;
		return errData;
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
QPosition peekMazeListQueue(MazeListQueue *pQ) {
	if (isEmptyMazeListQueue(pQ)) {
		QPosition errData;
		errData.x = INT_MIN;
		errData.y = INT_MIN;
		return errData;
	}

	return pQ->front->data;
}

QPosition moveToQueue(QPosition myPosition, int direction) {
	switch (direction) {
	case East:
		myPosition.x++;
		break;
	case West:
		myPosition.x--;
		break;
	case South:
		myPosition.y++;
		break;
	case North:
		myPosition.y--;
		break;
	}

	return myPosition;
}

int isMovable(QPosition myPosition, int direction) {
	QPosition p = moveToQueue(myPosition, direction);

	if (p.x < 0 || p.y < 0 || p.x > MAZE_SIZE || p.y > MAZE_SIZE) {
		return FALSE;
	}

	// 가지 않은 길이나 목적지가 아닌경
	if (maze_q[p.y][p.x] != ROAD_NOT_TAKEN && maze_q[p.y][p.x] != GOAL) {
		return FALSE;
	}

	return TRUE;
}

void printMazeInQueue() {
	int x, y;

	for (y = 0; y < MAZE_SIZE; y++) {
		for (x = 0; x < MAZE_SIZE; x++) {
			printf("% 2d", maze_q[y][x]);
		}
		printf("\n");
	}
}

void printPositionAndDirInQueue(QPosition p, int direction) {
	switch (direction) {
	case East:
		printf("[East]");
		break;
	case West:
		printf("[West]");
		break;
	case South:
		printf("[South]");
		break;
	case North:
		printf("[North]");
		break;
	}
	printf("[x:%d][y:%d]\n", p.x, p.y);
}

void solveMazeByQueue() {
	MazeListQueue q;
	QPosition myPosition;
	int direction;
	int isFoundGoal = FALSE;

	initMazeListQueue(&q, &myPosition);

	// 시작점(-1)부터 거리가 멀어질 수 록 1씩 감
	maze_q[myPosition.y][myPosition.x] = -1;
	enqueueMazeListQueue(&q, myPosition);

	while (!isEmptyMazeListQueue(&q)) {

		myPosition = dequeueMazeListQueue(&q);

		for (direction = 0; direction < 4; direction++) {
			if(!isMovable(myPosition, direction)) {
				continue;
			}

			QPosition p = moveToQueue(myPosition, direction);
			printPositionAndDirInQueue(p, direction);

			if (maze_q[p.y][p.x] == GOAL) {
				printf("found the goal.");
				isFoundGoal = TRUE;
				break;
			}

			// 한 칸 이동한 지역 표
			maze_q[p.y][p.x] = maze_q[myPosition.y][myPosition.x] - 1;

			enqueueMazeListQueue(&q, p);
		}
	}

	printf("isExist Goal: %s\n", isFoundGoal==TRUE?"yes":"no");
	printMazeInQueue();
}

#endif /* QUEUE_MAZEQUEUE_H_ */
