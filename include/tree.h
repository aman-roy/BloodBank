#ifndef TREE_H_  
#define TREE_H_

struct idTreeNode* getTreeID();
struct idTreeNode* sortedArrToBst(int*, int, int);
struct idTreeNode*  getNewTreeNode (int);
void sortArray(int* , int);
int searchTree(struct idTreeNode*, int);

#endif