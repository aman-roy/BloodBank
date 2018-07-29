#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include "../include/color.h"
#include "../include/utilities.h"

struct donor {
    char name[50];
    int age;
    char nationality[20];
    char address[250];
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


// Function Prototype for displaying
void headTemplate();
void mainDisplay();
void donorAndAccepterDisplay();


// Function Prototype for each operations
void addNewRecord();
void addNewDonor();
void addNewAcceptor();

int main()
{
    mainDisplay();
    int ch = takeChoice(1, 6);
    switch(ch)
    {
        case 1:
            addNewRecord();
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
    printf("\t\t\t6. Exit\n\n");
    removeDecoration();
}


void donorAndAccepterDisplay()
{
    headTemplate();
    printf("\n");
    printf(TD_BOLD"\t\t\t\t1. Donor\n");
    printf("\t\t\t\t2. Accepter\n");
    printf("\t\t\t\t3. Go Back\n");
    printf("\t\t\t\t4. Exit\n\n");
    removeDecoration();
}


void addNewRecord()
{
    int choice;
    char addNext = "n";

    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);

    switch(choice)
    {
        case 1:
            addNewDonor();
            printf(TD_BOLD"\t\tDo you want to add more records? (y/n): _\b");
            scanf("%c", &addNext);
            if (tolower(addNext) == 'y')
                addNewRecord();
            break;

        case 2:
            addNewAcceptor();
            printf(TD_BOLD"\t\tDo you want to add more records? (y/n): _\b");
            scanf("%c", &addNext);
            if (tolower(addNext) == 'y')
                addNewRecord();
            break;

        case 3:
            main();

        case 4:
            exit(0);

        default:
            printf(TC_RED"Error!\n");
    }
}



void addNewDonor()
{
    clear();
    headTemplate();

    // temp variable for clearing buffer
    char temp;

    struct donor newDonor;
    
    printf(TD_BOLD"\n\t\tEnter Donor's name: ");
    scanf("%c", &temp);
    scanf("%[^\n]", newDonor.name); 
    

    printf(TD_BOLD"\t\tEnter Donor's age: _\b");
    scanf("%d", &newDonor.age);

    printf(TD_BOLD"\t\tEnter Donor's nationality: _\b");
    scanf("%s", newDonor.nationality);

    printf(TD_BOLD"\t\tEnter Donor's address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newDonor.address);

    printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
    scanf("%s", newDonor.phone_number);

    printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
    scanf("%s", newDonor.blood_group);

    printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
    scanf("%c", &temp);
    scanf("%c", &newDonor.sex);

    printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
    scanf("%s", newDonor.date);

    printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
    scanf("%s", newDonor.time);

    // Write all the data to the file
    FILE *fp = fopen("./database/donor.dat", "ab+");
    if (!fp)
    {
       printf("Database malfuntion!\n");
       return;
    }
    fseek(fp,0,SEEK_END);
    fwrite(&newDonor,sizeof(newDonor),1,fp);
    fclose(fp);

    printf(TC_GREEN"\n\t\tRecord Added Successfully!\n");
    scanf("%c", &temp);
    sleep(2);
    removeDecoration();
}


void addNewAcceptor()
{
    clear();
    headTemplate();

    // temp variable for clearing buffer
    char temp;

    struct acceptor newAcceptor;
    
    printf(TD_BOLD"\n\t\tEnter Acceptor's name: ");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.info.name); 
    

    printf(TD_BOLD"\t\tEnter Acceptor's age: _\b");
    scanf("%d", &newAcceptor.info.age);

    printf(TD_BOLD"\t\tEnter Acceptor's nationality: _\b");
    scanf("%s", newAcceptor.info.nationality);

    printf(TD_BOLD"\t\tEnter Acceptor's address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.info.address);

    printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
    scanf("%s", newAcceptor.info.phone_number);

    printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
    scanf("%s", newAcceptor.info.blood_group);

    printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
    scanf("%c", &temp);
    scanf("%c", &newAcceptor.info.sex);

    printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
    scanf("%s", newAcceptor.info.date);

    printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
    scanf("%s", newAcceptor.info.time);

    printf(TD_BOLD"\t\tEnter Hospital Name: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.hospital);

    printf(TD_BOLD"\t\tEnter Hospital Address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.hospital_address);

    // Write all the data to the file
    FILE *fp = fopen("./database/acceptor.dat", "ab+");
    if (!fp)
    {
       printf("Database malfuntion!\n");
       return;
    }
    fseek(fp,0,SEEK_END);
    fwrite(&newAcceptor,sizeof(newAcceptor),1,fp);
    fclose(fp);

    printf(TC_GREEN"\n\t\tRecord Added Successfully!\n");
    scanf("%c", &temp);
    sleep(2);
    removeDecoration();
}