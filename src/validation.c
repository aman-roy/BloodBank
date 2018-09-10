#include <stdio.h>

#include "../include/validation.h"
#include "../include/color.h"
#include "../include/utilities.h"

int getIDInput(char mode)
{
    int id, flag = 0;
    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tID is already in use!\n");
        if (!flag)
            printf("\n\n");
        removeDecoration();
        if (mode == 'd')
            printf(TD_BOLD"\t\tEnter Donor's ID: _\b");
        else
            printf(TD_BOLD"\t\tEnter Acceptor's ID: _\b");
        scanf("%d", &id);
        flag = 1;
    } while(!isIdUnique(id));
    return id;
}

int getAgeInput(char mode)
{
    int age, flag = 0;
    while(1)
    {
        if (flag==1)
            printf(TC_RED TD_BOLD"\t\t\tAren't you too old!\n");
        else if(flag == 2)
        	printf(TC_RED TD_BOLD"\t\t\tGrow up!\n");
        removeDecoration();
        if (mode == 'd')
            printf(TD_BOLD"\t\tEnter Donor's Age: _\b");
        else
            printf(TD_BOLD"\t\tEnter Acceptor's Age: _\b");
        scanf("%d", &age);
        if (mode == 'a')
        {
        	if (age < 0)
        		flag = 2;
        	else if(age > 101)
        		flag = 1;
        	else
        		break;
        }
        if (mode == 'd')
        {
        	if (age < 18)
        		flag = 2;
        	else if(age > 55)
        		flag = 1;
        	else
        		break;
        }
    }
    removeDecoration();
    return age;
}