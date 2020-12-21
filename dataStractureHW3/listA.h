#pragma once

typedef struct node
{
	int key;
	struct node* next;
}NODE;

//funcs:
NODE* Reorder(NODE* head);

//questions:
void Q2a();