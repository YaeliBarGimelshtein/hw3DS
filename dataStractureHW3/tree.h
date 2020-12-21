#pragma once

typedef int itemType;
typedef struct node
{
	itemType info;
	struct node* left;
	struct node* right;
}tree_node, *tree_ptr;

//funcs:
void rangeSearch(tree_ptr t, itemType u, itemType v);