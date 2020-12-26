#include "list.h"
#include <stdlib.h>
#include <stdio.h>


NODE* createList() //create empty list
{
	return NULL;
}

int isEmptyList(NODE* L) //returns 1 if the list is empty, else 0
{
	if (L == NULL)
		return 1;
	return 0;
}

void insertToList(NODE** L, int x) //inserts item x at the end of the list
{
	NODE* helper = *L;
	if (*L == NULL)
	{
		*L = (NODE*)malloc(sizeof(NODE));
		if(*L != NULL)
		{
			(*L)->next = NULL;
			(*L)->key = x;
		}
	}
	else
	{
		while (helper->next != NULL)
		{
			helper = helper->next;
		}
		helper->next = (NODE*)malloc(sizeof(NODE));
		if (helper->next != NULL)
		{
			helper->next->key = x;
			helper->next->next = NULL;
		}
	}
}

void printList(NODE* L) //prints the content of the queue
{
	while (L->next!= NULL)
	{
		printf("%d->", L->key);
		L = L->next;
	}
	printf("%d\n", L->key);
}

void freeList(NODE* L)
{
	while (L != NULL)
	{
		NODE* helper = L->next;
		free(L);
		L = helper;
	}
}


//2.a
NODE* ReorderA(NODE* head)
{
	NODE* evenList = createList();
	NODE* oddList = createList();
	NODE* endOfOddList = NULL;
	while (head != NULL)
	{
		if (head->key % 2 == 0)
		{
			insertToList(&evenList, head->key);
		}
		else
		{
			insertToList(&oddList, head->key);
			if (endOfOddList != NULL)
			{
				endOfOddList = endOfOddList->next;
			}
			else
			{
				endOfOddList = oddList;
			}
		}
		head = head->next;
	}
	if(endOfOddList!=NULL)
	{
		endOfOddList->next = evenList;
		return oddList;
	}
	else
	{
		return evenList;
	}
}
//2.b
void ReorderB(NODE** head)
{
	NODE* helper = *head;
	NODE* previous;
	int recieved;
	NODE* startOfOdd = NULL;
	NODE* endOfOdd = NULL;
	NODE* endOfEven = NULL;
	NODE* startOfEven = NULL;
	if (helper == NULL)
		return;
	while (helper != NULL)
	{
		recieved = helper->key;
		previous = helper;
		helper = helper->next;
		if(recieved%2==0)
		{
			if (endOfEven == NULL)
			{
				endOfEven = previous;
				startOfEven = endOfEven;
			}
			else
			{
				endOfEven->next = previous;
				endOfEven = endOfEven->next;
			}
		}
		else
		{
			if (endOfOdd == NULL)
			{
				endOfOdd = previous;
				startOfOdd = endOfOdd;
			}
			else
			{
				endOfOdd->next = previous;
				endOfOdd = endOfOdd->next;
			}
		}
	}
	if (endOfOdd != NULL)
	{
		endOfOdd->next = startOfEven;
		*head = startOfOdd;
		if (endOfEven != NULL)
		{
			endOfEven->next = NULL;
		}
	}
	else
	{
		*head = startOfEven;
	}
}
