#pragma once

typedef int queueinfo;
typedef struct node
{
	queueinfo value;
	struct node* next;
} QueueNode;

//funcs:
QueueNode* createQueue();
int isEmptyQueue(QueueNode* Q);
void insert(QueueNode** Q, queueinfo x);
void delaafter(QueueNode* p, queueinfo* x);
void printQueue(QueueNode* Q);

//questions
void Q1b();