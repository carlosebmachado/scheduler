//
// Created by carlos on 16/05/2021.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"


typedef struct element {
    TASK *value;
    struct element *next;
} ELEMENT;

typedef struct queue {
    ELEMENT *first;
} QUEUE;

ELEMENT *new_element(TASK *value);

QUEUE *new_queue();

// inserts in the end
void enqueue(QUEUE *queue, TASK *value);

// removes from the begin
int dequeue(QUEUE *queue);

// return from begin
TASK *front(QUEUE *queue);

// return from the end
TASK *back(QUEUE *queue);

// verify if exists
int exists(QUEUE *queue, TASK *value);

// return queue size
size_t size(QUEUE *queue);

// traverse the queue
void traverse(QUEUE *queue);

#endif //QUEUE_H
