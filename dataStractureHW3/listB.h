#pragma once

typedef struct node
{
	int key;
	struct node* next;
}NODE;

//funcs:
void Reorder(NODE* head);

//questions:
void Q2b();