#pragma once


typedef struct nodeListCircle
{
	int key;
	struct nodeListCircle* next;
}NODE_Circle;

//funcs:
NODE_Circle* createListCircle();
void insertToListCircle(NODE_Circle** L, int x);
void printListCircle(NODE_Circle* L);
void freeListCircle(NODE_Circle* L);