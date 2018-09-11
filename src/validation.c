#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/validation.h"
#include "../include/color.h"
#include "../include/utilities.h"

int numLength(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n/=10;
	}
	return count;
}

int getIDInput(char mode)
{
    int id, flag = 0;
    do {
    	if (flag == 2)
            printf(TC_RED TD_BOLD"\t\t\tID must be of 3 digits!\n");
        else if (flag == 1)
            printf(TC_RED TD_BOLD"\t\t\tID is already in use!\n");
        if (!flag)
            printf("\n\n");
        removeDecoration();
        if (mode == 'd')
            printf(TD_BOLD"\t\tEnter Donor's ID: _\b");
        else
            printf(TD_BOLD"\t\tEnter Acceptor's ID: _\b");
        scanf("%d", &id);
        if (numLength(id) > 3)
        	flag = 2;
        else
        	flag = 1;
    } while(!isIdUnique(id) || flag == 2);
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

int isSexValid(char sex)
{
	sex = toupper(sex);
	if (sex == 'M' || sex == 'F' || sex == 'O')
		return 1;
	return 0;
}


int isBGValid(char* str)
{
	if (toupper(str[0]) == 'A' || toupper(str[0]) == 'O' || toupper(str[0]) == 'B')
	{
		if (str[1] == '+' || str[1] == '-' || toupper(str[1]) == 'B')
			return 1;
	}
	return 0;
}

int isDateValid(char d1, char d2, char m1, char m2)
{
	char d[3] = { d1, d2, '\0' };
	char m[3] = { m1, m2, '\0' };
	if(!(isdigit(d1) && isdigit(d2) && isdigit(m1) && isdigit(m2)))
		return 0;
	int day = atoi(d);
	int month = atoi(m);
	if (day > 0 && day < 32 && month > 0 && month < 13)
		return 1;
	return 0;
}

int isTimeValid(char h1, char h2, char m1, char m2)
{
	char h[3] = { h1, h2, '\0' };
	char m[3] = { m1, m2, '\0' };
	if(!(isdigit(h1) && isdigit(h2) && isdigit(m1) && isdigit(m2)))
		return 0;
	int hour = atoi(h);
	int minutes = atoi(m);
	if (hour < 24 && hour > -1 && minutes < 60 && minutes > -1)
		return 1;
	return 0;
}