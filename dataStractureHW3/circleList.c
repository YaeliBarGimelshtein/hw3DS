#include "circleList.h"
#include <stdlib.h>
#include <stdio.h>

NODE_Circle* createListCircle() //create empty list
{
	NODE_Circle* result =  malloc(sizeof(NODE_Circle));
	if (result != NULL)
	{
		result->key = -1;
		result->next = result;
	}
	return result;
}

void insertToListCircle(NODE_Circle** L, int x) //inserts item x at the end of the list
{
	NODE_Circle* helper = *L;
	while(helper->next!=*L)
	{
		helper = helper->next;
	}
	helper->next = (NODE_Circle*)malloc(sizeof(NODE_Circle));
	if (helper->next != NULL)
	{
		helper->next->next = *L;
		helper->next->key = x;
	}
	
}

void printListCircle(NODE_Circle* L) //prints the content of the list
{
	while (L->next->key != -1)
	{
		printf("%d->", L->key);
		L = L->next;
	}
	printf("%d\n", L->key);
}

void freeListCircle(NODE_Circle* L)
{
	if (L == NULL)
		return;
	L = L->next;
	while (L->key != -1)
	{
		NODE_Circle* helper = L->next;
		free(L);
		L = helper;
	}
	free(L->next);
}
