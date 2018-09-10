#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"
#include "../include/containers.h"
#include "../include/linkedlist.h"

struct idTreeNode* getTreeID()
{
	struct donorBox* db = donorDBtoLL();
	struct donorNode* donorHead = db->head;
	struct donorNode* donorTemp = donorHead;
	int donorCount = db->count;

	struct acceptorBox* ab = acceptorDBtoLL();
	struct acceptorNode* acceptorHead = ab->head;
	struct acceptorNode* acceptorTemp = acceptorHead;
	int acceptorCount = ab->count;

	int idArray[donorCount+acceptorCount];

	for (int i = 0; i < donorCount+acceptorCount; ++i)
	{
		if (!donorHead)
		{
			idArray[i] = acceptorHead->data.info.id;
			acceptorHead = acceptorHead->next;
			continue;
		}

		if (!acceptorHead)
		{
			idArray[i] = donorHead->data.id;
			donorHead = donorHead->next;
			continue;
		}

		if (donorHead->data.id < acceptorHead->data.info.id)
		{
			idArray[i] = donorHead->data.id;
			donorHead = donorHead->next;
		}
		else
		{
			idArray[i] = acceptorHead->data.info.id;
			acceptorHead = acceptorHead->next;
		}
	}

	free(db);
	free(ab);
	free(donorTemp);
	free(acceptorTemp);

	sortArray(idArray, donorCount+acceptorCount);

	return sortedArrToBst(idArray, 0, donorCount+acceptorCount-1);
}

struct idTreeNode* sortedArrToBst(int A[], int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	struct idTreeNode* root = getNewTreeNode(A[mid]);
	root->left = sortedArrToBst(A, start, mid-1);
	root->right = sortedArrToBst(A, mid+1, end);
	return root;
}


struct idTreeNode*  getNewTreeNode (int x)
{
	struct idTreeNode*  temp = (struct idTreeNode*)malloc(sizeof(struct idTreeNode));
	temp->id = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void sortArray(int A[], int n)
{
	int flag = 0;
	int temp;

	for (int i = 0; i < n; ++i)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (A[j] > A[j+1])
			{
				flag = 1;
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
		if (!flag)
			break;
	}
}

int searchTree(struct idTreeNode* root, int id)
{
	if (root == NULL)
		return 0;
	if (root->id == id)
		return 1;
	if (root->id > id)
		return searchTree(root->left, id);
	if (root->id < id)
		return searchTree(root->right, id);
}

void draw_tree_hor2(struct idTreeNode *tree, int depth, char *path, int right)
{
    if (tree== NULL)
        return;
    depth++;

    draw_tree_hor2(tree->right, depth, path, 1);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(tree->left)
        path[depth-1] = 1;

    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<SPACE; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", tree->id);
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<SPACE; j++)
          printf(" ");
    }
    draw_tree_hor2(tree->left, depth, path, 0);
}

void draw_tree(struct idTreeNode *tree)
{
    char path[255] = {};
    draw_tree_hor2(tree, 0, path, 0);
}