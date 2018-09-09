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
	struct donorNode* acceptorTemp = acceptorHead;
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
