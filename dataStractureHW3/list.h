#pragma once
typedef struct nodeList
{
	int key;
	struct nodeList* next;
}NODE;

NODE* createList();
int isEmptyList(NODE* L);
void insertToList(NODE** L, int x);
void printList(NODE* L);
void freeList(NODE* L);

//funcs:
NODE* ReorderA(NODE* head);

//funcs:
void ReorderB(NODE** head);