#include <stdio.h>
#include "../include/color.h"
#include "../include/utilities.h"

struct donor {
    char first_name[20];
    char middle_name[20];
    char last_name[20];
    int age;
    char nationality[3];
    char address[100];
    char phone_number[10];
    char blood_group[5];
    char sex;
    char date[10];
    char time[10];
};

struct acceptor {
    struct donor info;
    char hospital[50];
    char hospital_address[100];
};


// Function Prototype
void headTemplate();
void mainDisplay();
void donorAndAccepterDisplay();


int main()
{
    mainDisplay();
    int ch = takeChoice(0, 5);
    switch(ch)
    {
        case 1:
            donorAndAccepterDisplay();

            break;
        default:
            printf(TD_BOLD "EXIT!\n");
    }
    return 0;
}


void headTemplate()
{
    clear();
    printf("\n\n");
    printf(TC_RED TD_BOLD"\t**********************************************************\n");
    printf("\t**********************************************************\n");
    printf("\t**\t\t\t\t\t\t\t**\n");
    printf("\t**\t\t");
    removeDecoration();
    printf(TC_BLACK TD_BOLD TD_UNDERLINE BCK_LYELLOW"BLOOD BANK MANAGEMENT SYSTEM");
    removeDecoration();
    printf(TD_BOLD TC_RED"\t\t**\n");
    printf("\t**\t\t\t\t\t\t\t**\n");
    printf("\t**********************************************************\n");
    printf("\t**********************************************************\n");
    removeDecoration();
}

void mainDisplay()
{
    headTemplate();
    printf("\n");
    printf(TD_BOLD"\t\t\t1. Add new Record\n");
    printf("\t\t\t2. Display Record\n");
    printf("\t\t\t3. Search Record\n");
    printf("\t\t\t4. Blood Group Availablity\n");
    printf("\t\t\t5. Get Info\n");
    printf("\t\t\t0. Exit\n\n");
    removeDecoration();
}


void donorAndAccepterDisplay()
{
    headTemplate();
    printf("\n");
    printf(TD_BOLD"\t\t\t\t1. Donor\n");
    printf("\t\t\t\t2. Accepter\n");
    printf("\t\t\t\t0. Go Back\n\n");
    removeDecoration();
}