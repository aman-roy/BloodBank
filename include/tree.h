#ifndef TREE_H_  
#define TREE_H_
#define SPACE 5

struct idTreeNode* getTreeID();
struct idTreeNode* sortedArrToBst(int*, int, int);
struct idTreeNode*  getNewTreeNode (int);
void sortArray(int* , int);
int searchTree(struct idTreeNode*, int);
void draw_tree_hor2(struct idTreeNode *tree, int depth, char *path, int right);
void draw_tree(struct idTreeNode *tree);

#endif