#pragma once

typedef int itemType;
typedef struct nodeTree
{
	itemType info;
	struct nodeTree* left;
	struct nodeTree* right;
}tree_node, *tree_ptr;

//funcs:
tree_ptr initTree();
void rangeSearch(tree_ptr t, itemType u, itemType v);