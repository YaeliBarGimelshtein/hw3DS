#pragma once

typedef struct node
{
	int key;
	struct node* next;
}NODE;

//funcs:
void ReorderB(NODE* head);

//questions:
void Q2b();