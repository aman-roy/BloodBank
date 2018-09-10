#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "../include/utilities.h"
#include "../include/color.h"
#include "../include/tree.h"

int takeChoice(int start, int end)
{
    int num;
    do {
        printf(TD_BOLD "\t\t\tEnter Choice: _\b");
        scanf("%d", &num);
    } while(num < start || num > end);
    removeDecoration();
    return num;
}

void dbError()
{
	printf(TC_RED TD_BOLD"\t\t\tDatabase malfuntion! Create DB first.\n");
    sleep(2);
    removeDecoration();
}

FILE* loadFile(char fName)
{
    FILE *fptr = NULL;
    if (fName == 'a')
    {
        fptr = fopen("./database/acceptor.dat", "rb");
        if (!fptr)
           dbError();
    }
    else if (fName == 'd')
    {
        fptr = fopen("./database/donor.dat", "rb");
        if (!fptr)
           dbError();
    }

    return fptr;
}


void dbSetup()
{
    FILE *fp = fopen("./database/acceptor.dat", "ab+");
    fclose(fp);
    fp = fopen("./database/donor.dat", "ab+");
    fclose(fp);
}

int wantsToChange(char* question)
{
    int ch;
    printf("\t\tYou want to modify %s.[1(yes)/0(no)]: ", question);
    scanf("%d", &ch);
    return ch;
}

int isIdUnique(int newID)
{
    struct idTreeNode* root = getTreeID();
    if (searchTree(root, newID))
        return 0;
    else
        return 1;
}