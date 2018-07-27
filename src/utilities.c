#include "../include/utilities.h"
#include "../include/color.h"

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