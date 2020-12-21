#pragma once

typedef struct node
{
	int key;
	struct node* next;
}NODE;

//funcs:
NODE* ReorderA(NODE* head);

//questions:
void Q2a();