#include "queue.h"
#include "list.h"
#include "tree.h"
#include "circleList.h"
#include <stdio.h>
#include <string.h>

#define N 5

void Q1b(int n, int k)
{
	QueueNode* queue = createQueue();
	for (int i = 1; i <= n; i++)
	{
		insertToQueue(&queue, n-i+1);
	}
	printf("Order of elimination: ");
	queueinfo x = 0;
	while (queue->next != queue)
	{
		for (int i = 0; i < k-1; i++)
		{
			queue = queue->next;
		}
		delaafter(queue, &x);
		printf("%d ", x);
	}
	delaafter(queue, &x);
	printf("\nLeader: %d", x);
}

void Q2()
{
	int size = 0;
	int toAdd;

	printf("creating a list\nenter a number of size of list\n");
	scanf_s("%d", &size);
	NODE* list = createList();
	for (int i = 1; i <= size; i++)
	{
		printf("enter a number to add to list");
		scanf_s("%d", &toAdd);
		insertToList(&list, toAdd);
	}

	printList(list);

	printf("----------Q2A-----------\n");
	NODE* newList=ReorderA(list);
	printf("after reorder\n");
	printList(newList);

	printf("----------Q2B-----------\n");
	ReorderB(&list);
	printf("after reorder\n");
	printList(list);
	freeList(list);
}
//It's fixed to 5 for the purpose of this exercise.
int stringToInt(char* str)
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result = result * 10 + str[i];
	}
	return result;
}

void bonusQuestion()
{
	NODE_Circle* circle = createListCircle();
	puts("Enter number \n");
	char* number = "\0";
	if(scanf("%s\n", number));
	int len = strlen(number);
	while (len != 0)
	{
		char helper[N];
		for (int i = 0; i < N && i<len; i++)
		{
			helper[i] = number[len - 5 + i];
		}
		int num = stringToInt(helper);
	}
}

int main()
{
	//question 1b
	printf("----------Q1-----------\n");
	printf("enter a number of soldiers");
	int numOfSoldiers = 0;
	scanf_s("%d", &numOfSoldiers);

	printf("enter a number of jumps");
	int jumps = 0;
	scanf_s("%d", &jumps);

	Q1b(numOfSoldiers,jumps); 

	//question 2
	printf("----------Q2-----------\n");
	Q2(); 

	return 1;
}