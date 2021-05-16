//
// Created by carlos on 16/05/2021.
//

#include "queue.h"


ELEMENT *new_element(TASK *value) {
    ELEMENT *e = malloc(sizeof(ELEMENT));
    e->value = value;
    e->next = NULL;
    return e;
}

QUEUE *new_queue() {
    QUEUE *q = malloc(sizeof(QUEUE));
    q->first = NULL;
    return q;
}

// inserts in the end
void enqueue(QUEUE *queue, TASK *value) {
    ELEMENT *toInsert = new_element(value);
    if (!queue->first) {
        queue->first = toInsert;
    } else {
        ELEMENT *current = queue->first;
        while (current->next) {
            current = current->next;
        }
        current->next = toInsert;
    }
}

// removes from the begin
int dequeue(QUEUE *queue) {
    if (queue->first) {
        ELEMENT *toDelete = queue->first;
        queue->first = toDelete->next;
        free(toDelete);
        return 1;
    }
    return 0;
}

// return from begin
TASK *front(QUEUE *queue) {
    return queue->first ? queue->first->value : NULL;
}

// return from the end
TASK *back(QUEUE *queue) {
    if (!queue->first) return NULL;
    ELEMENT *temp = queue->first;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->value;
}

// verify if exists
int exists(QUEUE *queue, TASK *value) {
    ELEMENT *current = queue->first;
    while (current) {
        if (!strcmp(current->value->name, value->name)) return 1;
        current = current->next;
    }
    return 0;
}

// return queue size
size_t size(QUEUE *queue) {
    size_t count = 0;
    ELEMENT *current = queue->first;
    while (1) {
        if (!current) return count;
        current = current->next;
        count++;
    }
}

// traverse the queue
void traverse(QUEUE *queue) {
    ELEMENT *current = queue->first;
    while (current) {
        printf("[%s] [%d] [%d] [%d]\n", current->value->name, current->value->tid, current->value->priority, current->value->burst);
        current = current->next;
    }
}
