#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include "list.h"
#include "tree.h"
#include "circleList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define UNDER_TEN_THOUSAND 100000

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
		result = result * 10 + str[i]-'0';
	}
	return result;
}
//It's fixed to 5 for purpose of this exercise
char* intToString(int num)
{
	size_t length = 0;
	int helper = num;
	while (helper > 0)
	{
		length++;
		helper = helper / 10;
	}
	char* result;
	if (length == N)
	{
		result = (char*)malloc(N + 1);
	}
	else
	{
		result = (char*)malloc(length + 1);
	}
	if (result == NULL)
		return NULL;
	result[length] = '\0';
	for (int i = 0; i < length; i++)
	{
		result[length - 1 - i] = num % 10 + '0';
		num = num / 10;
	}
	return result;
}

NODE_Circle* stringNumToCircle()
{
	NODE_Circle* circle = createListCircle();
	puts("Enter number \n");
	char* number= malloc(UCHAR_MAX);
	if(scanf("%s", number));
	if (number == NULL)
		return NULL;
	size_t len = strlen(number);
	while (len > 0)
	{
		char helper[N + 1];
		helper[N] = '\0';
		if (len > N)
		{
			for (int i = 0; i < N; i++)
			{
				helper[i] = number[len - N + i];
			}
			len = len - N;
		}
		else
		{
			for (int i = N-len; i < N; i++)
			{
				helper[i] = number[i - N + (int)len];
			}
			for (int i = 0; i < N-len; i++)
			{
				helper[i] = '0';
			}
			len = 0;
		}
		int num = stringToInt(helper);
		insertToListCircle(&circle, num);
	}
	return circle;
}

char* circleToStringNum(NODE_Circle* circle)
{
	char* result = intToString(circle->next->key);
	circle = circle->next;
	while (circle->next->key != -1)
	{
		circle = circle->next;
		char* string = intToString(circle->key);
		char* temp = realloc(string, strlen(string) + strlen(result) + 1);
		if (temp == NULL)
			return NULL;
		string = temp;
		strcat(string, result);
		result = string;
	}
	return result;
}

NODE_Circle* addintHelper(NODE_Circle* result, NODE_Circle* p, NODE_Circle* q, int carry)
{
	int num, total;
	if (p->key != -1 && q->key != -1)
	{
		total = p->key + q->key + carry;
		num = total % UNDER_TEN_THOUSAND;
		insertToListCircle(&result, num);
		carry = total / UNDER_TEN_THOUSAND;
		return addintHelper(result, p->next, q->next, carry);
	}
	NODE_Circle* helper = NULL;
	if (p->key != -1)
	{
		helper = p;
	}
	else if (q->key != -1)
	{
		helper = q;
	}
	if (helper != NULL)
	{
		total = helper->key + carry;
		num = total % UNDER_TEN_THOUSAND;
		insertToListCircle(&result, num);
		carry = total / UNDER_TEN_THOUSAND;
		if (helper == p)
		{
			return addintHelper(result, p->next, q, carry);
		}
		else
		{
			return addintHelper(result, p, q->next, carry);
		}
	}
	if (carry > 0)
	{
		insertToListCircle(&result, carry);
	}
	return result;
}

NODE_Circle* addint(NODE_Circle* p, NODE_Circle* q)
{
	NODE_Circle* result;
	result = createListCircle();
	return addintHelper(result, p->next, q->next, 0);
}

void bonusQuestion()
{
	NODE_Circle* a = stringNumToCircle();
	puts(circleToStringNum(a));
	NODE_Circle* b = stringNumToCircle();
	puts(circleToStringNum(b));
	puts("Addition of two numbers result:");
	puts(circleToStringNum(addint(a, b)));
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

	//Bonus Question
	printf("!!!!!!!!!BONUS QUESTION!!!!!!!!!\n");
	bonusQuestion();

	return 1;
}