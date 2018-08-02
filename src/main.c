#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include "../include/color.h"
#include "../include/utilities.h"

struct donor {
    int id;
    char name[50];
    int age;
    char nationality[20];
    char address[250];
    char phone_number[15];
    char blood_group[10];
    char sex;
    char date[15];
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
void displayRecord();
void searchRecord();


// Function prototype for sub functions
void addNewDonor();
void addNewAcceptor();
void displayDonor();
void displayAcceptor();
void searchByID();
void searchByName();
void searchByBloodGroup();
void printDonorData(struct donor *);
void printAcceptorData(struct acceptor *);

int main()
{
    mainDisplay();
    int ch = takeChoice(1, 6);
    switch(ch)
    {
        case 1:
            addNewRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            searchRecord();
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
            main();
            break;

        case 2:
            addNewAcceptor();
            printf(TD_BOLD"\t\tDo you want to add more records? (y/n): _\b");
            scanf("%c", &addNext);
            if (tolower(addNext) == 'y')
                addNewRecord();
            main();
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
    
    printf(TD_BOLD"\n\t\tEnter Donor's ID: _\b");
    scanf("%d", &newDonor.id); 

    printf(TD_BOLD"\t\tEnter Donor's name: ");
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
    
    printf(TD_BOLD"\n\t\tEnter Acceptor's ID:  _\b");
    scanf("%d", &newAcceptor.info.id);

    printf(TD_BOLD"\t\tEnter Acceptor's name: ");
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
       dbError();
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

void displayRecord()
{
    int choice;

    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);

    switch(choice)
    {
        case 1:
            displayDonor();
            main();
            break;

        case 2:
            displayAcceptor();
            main();
            break;

        case 3:
            main();

        case 4:
            exit(0);

        default:
            printf(TC_RED"Error!\n");
    }
}

void displayDonor()
{
    FILE *fp = loadFile('d');
    if (!fp)
       return;
    
    struct donor temp;

    clear();
    headTemplate();

    printf(TD_BOLD TD_UNDERLINE TC_YELLOW"\n\t\t\t\tDONOR's LIST\n\n");
    removeDecoration();

    if(fread(&temp,sizeof(temp),1,fp))
    {
        printf(TD_BOLD"     ID            Name                   Age       SEX      BLOOD GROUP \n");
        printf(TD_BOLD"  -----------------------------------------------------------------------\n");

        int space;
        rewind(fp);
        while(fread(&temp,sizeof(temp),1,fp))
        {
            printf("     %d\t", temp.id);
            space = 22 - strlen(temp.name);
            printf("%s", temp.name);
            while(space > 0)
            {
                printf(" ");
                space--;
            }
            printf("    %03d \t     %c \t\t %s\n", temp.age, temp.sex, temp.blood_group);
        }
    }
    else
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
        removeDecoration();
    }
    
    int choice;

    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        displayRecord();
    if (choice == 2)
    {
        main();
    }

    removeDecoration();
}

void displayAcceptor()
{
    FILE *fp = loadFile('a');
    if (!fp)
       return;
    
    struct acceptor temp;

    clear();
    headTemplate();

    printf(TD_BOLD TD_UNDERLINE TC_YELLOW"\n\t\t\t\tACCEPTOR's LIST\n\n");
    removeDecoration();

    if(fread(&temp,sizeof(temp),1,fp))
    {
        printf(TD_BOLD"     ID            Name                   Age       SEX      BLOOD GROUP \n");
        printf(TD_BOLD"  -----------------------------------------------------------------------\n");

        int space;
        rewind(fp);
        while(fread(&temp,sizeof(temp),1,fp))
        {
            printf("     %d\t", temp.info.id);
            space = 22 - strlen(temp.info.name);
            printf("%s", temp.info.name);
            while(space > 0)
            {
                printf(" ");
                space--;
            }
            printf("    %03d \t     %c \t\t %s\n", temp.info.age, temp.info.sex, temp.info.blood_group);
        }
    }
    else
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
        removeDecoration();
    }
    
    int choice;

    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        displayRecord();
    if (choice == 2)
    {
        main();
    }

    removeDecoration();
}


void searchRecord()
{
    headTemplate();
    printf("\n");
    printf(TD_BOLD"\t\t\t\t1. Search by ID\n");
    printf("\t\t\t\t2. Search by Name\n");
    printf("\t\t\t\t3. Search by Blood Group\n");
    printf("\t\t\t\t4. Go back\n");
    printf("\t\t\t\t5. Exit\n\n");
    int choice = takeChoice(1, 5);
    switch(choice)
    {
        case 1:
            searchByID();
            int ch;
            printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to search again or 2 for main menu\n");
            ch = takeChoice(0, 2);
            if (!ch)
                exit(0);
            if (ch == 1)
                searchRecord();
            if (ch == 2)
                main();
            removeDecoration();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            exit(0);
        default:
            printf(TC_RED"Error!\n");
    }
    removeDecoration();

}


void searchByID()
{
    FILE *fpDonor = loadFile('d');
    FILE *fpAcceptor = loadFile('a');

    if (!(fpDonor || fpAcceptor))
        return;

    struct donor tempDonor;
    struct acceptor tempAcceptor;

    if (fread(&tempDonor,sizeof(tempDonor),1,fpDonor) || fread(&tempAcceptor,sizeof(tempAcceptor),1,fpAcceptor))
    {
        clear();
        headTemplate();
        rewind(fpDonor);
        rewind(fpAcceptor);

        int id, entered = 0;
        printf(TD_BOLD"\n\n\t\t\tEnter ID: ");
        scanf("%d", &id);

        while(fread(&tempDonor,sizeof(tempDonor),1,fpDonor))
        {
            if (tempDonor.id == id)
            {
                printf(TD_BOLD"\n\t\t\tMatch Found!\n");
                sleep(1);
                printf(TD_BOLD"\t\t\tLoading Data!\n");
                sleep(1);
                clear();
                headTemplate();
                printDonorData(&tempDonor);
                entered = 1;
            }
        }

        if (!entered)
        {
            while(fread(&tempAcceptor,sizeof(tempAcceptor),1,fpAcceptor))
            {
                if (tempAcceptor.info.id == id)
                {
                    printf(TD_BOLD"\n\t\t\tMatch Found!\n");
                    sleep(1);
                    printf(TD_BOLD"\t\t\tLoading Data!\n");
                    sleep(1);
                    clear();
                    headTemplate();
                    printAcceptorData(&tempAcceptor);
                    entered = 1;
                }
            }
        }
            
        if (!entered)
        {
            printf(TC_RED TD_BOLD"\n\t\t\tNOT FOUND!\n");
        }
    }
    else
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    }
    removeDecoration();
}


void printDonorData(struct donor *data)
{
    printf(TD_BOLD"\n\t\tDonor's ID: %d\n", data->id);
    printf(TD_BOLD"\t\tDonor's name: %s\n", data->name);  
    printf(TD_BOLD"\t\tDonor's age: %d\n", data->age);
    printf(TD_BOLD"\t\tDonor's nationality: %s\n", data->nationality);
    printf(TD_BOLD"\t\tDonor's address: %s\n", data->address);
    printf(TD_BOLD"\t\tDonor's phone number: %s\n", data->phone_number);
    printf(TD_BOLD"\t\tDonor's blood group: %s\n", data->blood_group);
    printf(TD_BOLD"\t\tDonor's sex: %c\n", data->sex);
    printf(TD_BOLD"\t\tBlood donation date[DD/MM/YYYY]: %s\n", data->date);
    printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: %s\n", data->time);
}

void printAcceptorData(struct acceptor *data)
{
    printf(TD_BOLD"\n\t\tAcceptor's ID: %d\n", data->info.id);
    printf(TD_BOLD"\t\tAcceptor's name: %s\n", data->info.name);  
    printf(TD_BOLD"\t\tAcceptor's age: %d\n", data->info.age);
    printf(TD_BOLD"\t\tAcceptor's nationality: %s\n", data->info.nationality);
    printf(TD_BOLD"\t\tAcceptor's address: %s\n", data->info.address);
    printf(TD_BOLD"\t\tAcceptor's phone number: %s\n", data->info.phone_number);
    printf(TD_BOLD"\t\tAcceptor's blood group: %s\n", data->info.blood_group);
    printf(TD_BOLD"\t\tAcceptor's sex: %c\n", data->info.sex);
    printf(TD_BOLD"\t\tTaken Blood on[DD/MM/YYYY]: %s\n", data->info.date);
    printf(TD_BOLD"\t\tTaken blood at[HH:MM]: %s\n", data->info.time);
    printf(TD_BOLD"\t\tHospital Name: %s\n", data->hospital);
    printf(TD_BOLD"\t\tHospital Address: %s\n", data->hospital_address);
}