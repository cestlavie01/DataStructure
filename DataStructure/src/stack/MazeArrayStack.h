/*
 * MazeArrayStack.h
 *
 *  Created on: 2016. 6. 26.
 *      Author: cobus
 */

#ifndef STACK_MAZEARRAYSTACK_H_
#define STACK_MAZEARRAYSTACK_H_

#include <stdio.h>

#define MAZE_SIZE 5
#define MAX_STACK_SIZE 100

char maze[MAZE_SIZE][MAZE_SIZE] = {
		{ '1', '1', '1', '1', '1' },
		{ 's', '0', '1', '0', '1' },
		{ '1', '0', '0', '0', '1' },
		{ '1', '0', '1', '0', 'g' },
		{ '1', '1', '1', '1', '1' }
};

typedef struct _sposition {
	int x;
	int y;
} SPosition;

typedef struct _stack {
	SPosition data[MAX_STACK_SIZE];
	int top;
} Stack;

void initMazeStack(Stack *s, SPosition *start) {
	int isBreak = 0;
	int x, y;

	s->top = -1;

	for (y = 0; y < MAZE_SIZE; y++) {
		for (x = 0; x < MAZE_SIZE; x++) {
			if (maze[y][x] == 's') {
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

int isFullMazeStack(Stack *s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

int isEmptyMazeStack(Stack *s) {
	return (s->top == -1);
}

void pushMazeStack(Stack *s, SPosition p) {
	if (isFullMazeStack(s)) {
		printf("maze stack is full!!!\n");
		return ;
	}

	s->top++;
	s->data[s->top].x = p.x;
	s->data[s->top].y = p.y;
}

void moveToStack(Stack *s, int x, int y) {
	if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) {
		return ;
	}

	if (maze[y][x] != '1' && maze[y][x] != '.') {
		SPosition p;
		p.x = x;
		p.y = y;
		pushMazeStack(s, p);
	}
}

SPosition popMazeStack(Stack *s) {
	SPosition errPos;
	errPos.x = -1;
	errPos.y = -1;

	if (isEmptyMazeStack(s)) {
		printf("maze stack is empty!!\n");
		return errPos;
	}

	return s->data[s->top--];
}

void printMaze() {
	int x, y;

	for (y = 0; y < MAZE_SIZE; y++) {
		for (x = 0; x < MAZE_SIZE; x++) {
			printf("%c", maze[y][x]);
		}
		printf("\n");
	}
}

void solveMazeByStack() {
	Stack stack;
	SPosition myPosition;
	initMazeStack(&stack, &myPosition);

	while (maze[myPosition.y][myPosition.x] != 'g') {
		maze[myPosition.y][myPosition.x] = '.';

		moveToStack(&stack, myPosition.x, myPosition.y - 1);
		moveToStack(&stack, myPosition.x, myPosition.y + 1);
		moveToStack(&stack, myPosition.x - 1, myPosition.y);
		moveToStack(&stack, myPosition.x + 1, myPosition.y);

		if (isEmptyMazeStack(&stack)) {
			printf("error: stack is empty.");
			return ;
		}

		myPosition = popMazeStack(&stack);
		printf("[x:%d][y:%d]\n", myPosition.x, myPosition.y);
	}

	printf("myPosition [x:%d][y:%d]\n", myPosition.x, myPosition.y);
	printf("GOAL!\n");

	printMaze();
}

#endif /* STACK_MAZEARRAYSTACK_H_ */
