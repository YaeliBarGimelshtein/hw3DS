#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void rangeSearch(tree_ptr t, itemType u, itemType v)
{
	if (t == NULL)
		return;
	rangeSearch(t->left, u, v);
	if (t->info >= u && t->info <= v)
	{
		printf("%d", t->info);
	}
	rangeSearch(t->right, u, v);
}