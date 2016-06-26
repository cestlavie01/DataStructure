/*
 * DoubleLinkedList.cpp
 *
 *  Created on: 2016. 6. 26.
 *      Author: cobus
 */

#include "DoubleLinkedList.h"

#include <stdio.h>
#include <limits.h>

void initDllDeque(Deque *deque) {
	deque->head = NULL;
	deque->tail = NULL;
}

int isEmptyDllDeque(Deque *deque) {
	if (deque->head == NULL || deque->tail == NULL) {
		return TRUE;
	}
	return FALSE;
}

void addFirstDllDeque(Deque *deque, Data data) {
	DllDequeNode *newNode = (DllDequeNode *) malloc(sizeof(DllDequeNode));
	newNode->data = data;
	newNode->next = deque->head;
	newNode->prev = NULL;

	if (isEmptyDllDeque(deque)) {
		deque->tail = newNode;
	} else {
		deque->head->prev = newNode;
	}

	deque->head = newNode;
}

void addLastDllDeque(Deque *deque, Data data) {
	DllDequeNode *newNode = (DllDequeNode *) malloc(sizeof(DllDequeNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = deque->tail;

	if (isEmptyDllDeque(deque)) {
		deque->head = newNode;
	} else {
		deque->tail->next = newNode;
	}

	deque->tail = newNode;
}

/**
 * remove first Node and return first Node's data.
 */
Data removeFirstDllDeque(Deque *deque) {
	DllDequeNode *tmp = deque->head;
	Data returnData = tmp->data;

	if (isEmptyDllDeque(deque)) {
		return INT_MIN;
	}

	deque->head = deque->head->next;
	free(tmp);

	if (deque->head == NULL) {
		deque->tail = NULL;
	} else {
		deque->head->prev = NULL;
	}

	return returnData;
}

/**
 * remove last Node and return Last Node's data.
 */
Data removeLastDllDeque(Deque *deque) {
	DllDequeNode *tmp = deque->tail;
	Data returnData = tmp->data;

	if (isEmptyDllDeque(deque)) {
		return INT_MIN;
	}

	deque->tail = deque->tail->prev;
	free(tmp);

	if (deque->tail == NULL) {
		deque->head = NULL;
	} else {
		deque->tail->next = NULL;
	}

	return returnData;
}

/**
 * return only first data.
 */
Data getFirstDllDeque(Deque *deque) {
	if (isEmptyDllDeque(deque)) {
		return INT_MIN;
	}

	return deque->head->data;
}

/**
 * return only last data.
 */
Data getLastDllDeque(Deque *deque) {
	if (isEmptyDllDeque(deque)) {
		return INT_MIN;
	}
	return deque->tail->data;
}
