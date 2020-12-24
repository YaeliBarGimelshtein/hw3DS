#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

//question 1a

QueueNode* createQueue() //create empty queue
{
	return NULL;
}

int isEmptyQueue(QueueNode* Q) //returns 1 if the queue is empty, else 0
{
	if (Q == NULL)
		return 1;
	return 0;
}

void insertToQueue(QueueNode** Q, queueinfo x) //inserts item x at the rear of the queue Q
{
	if (isEmptyQueue(*Q))
	{
		*Q = (QueueNode*)malloc(sizeof(QueueNode));
		if (*Q != NULL)
		{
			(*Q)->value = x;
			(*Q)->next = *Q;
		}
	}
	else
	{
		QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
		if (newNode == NULL)
			return;
		newNode->value = x;
		newNode->next = (*Q)->next;
		(*Q)->next = newNode;
	}
}

void delaafter(QueueNode* p, queueinfo* x) //deletes the node after node p from queue and stores content in x
{
	QueueNode* helper = p->next->next;//P
	*x = p->next->value;
	free(p->next);
	p->next = helper;
}

void printQueue(QueueNode* Q) //prints the content of the queue
{
	QueueNode* helper = Q;
	while (helper->next != Q)
	{
		printf("%d->", helper->next->value);
		helper = helper->next;
	}
	printf("%d\n", Q->value);
}