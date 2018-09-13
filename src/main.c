#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../include/color.h"
#include "../include/utilities.h"
#include "../include/containers.h"
#include "../include/linkedlist.h"
#include "../include/tree.h"
#include "../include/validation.h"

// Function Prototype for displaying
void headTemplate();
void mainDisplay();
void guestDisplay();
void donorAndAccepterDisplay();

// Function Prototype for each operations
void addNewRecord();
void displayRecord();
void searchRecord();
void sortRecord();
void modifyRecord();
void deleteId();
void insertAtPos();
void reverseRecords();
void printIdTree();

// Function prototype for sub functions
void addNewDonor();
void addNewAcceptor();
void displayDonor();
void displayAcceptor();
void printDonorData(struct donor *);
void printAcceptorData(struct acceptor *);
void sortDonor();
void sortAcceptor();
void modifyDonor();
void modifyAcceptor();
void deleteIdDonor();
void deleteIdAcceptor();
void deleteDonor();
void deleteAcceptor();
void insertAtPosDonor();
void insertAtPosAcceptor();
void reverseRecordsDonor();
void reverseRecordsAcceptor();

int loginMode = 0;

int main()
{
    dbSetup();
    int error = 0;

    if (!loginMode)
    {
        do {    
            headTemplate();
            if(error)
            {
                printf(TC_RED TD_BOLD"\n\n\t\t\tWrong username or password!\n");
                removeDecoration();
            }
            else 
                printf("\n\n");
            loginMode = getMode();
            error = 1;
        } while(!loginMode);
    }
    

    if(loginMode == 1)
    {
        mainDisplay();
        int ch = takeChoice(1, 10);
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
            case 4:
                sortRecord();
                break;
            case 5:
                modifyRecord();
                break;
            case 6:
                deleteId();
                break;
            case 7:
                insertAtPos();
                break;
            case 8:
                reverseRecords();
                break;
            case 9:
                printIdTree();
                break;
            default:
                printf(TD_BOLD "EXIT!\n");
                exit(0);
        }
        removeDecoration();
    }

    if (loginMode == 2)
    {
        guestDisplay();
        int ch = takeChoice(1, 6);
        switch(ch)
        {
            case 1:
                displayRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                sortRecord();
                break;
            case 4:
                reverseRecords();
                break;
            case 5:
                printIdTree();
                break;
            default:
                printf(TD_BOLD "EXIT!\n");
                exit(0);
        }
        removeDecoration();
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
    printf("\t\t\t4. Sort Record\n");
    printf("\t\t\t5. Modify Record\n");
    printf("\t\t\t6. Delete Record\n");
    printf("\t\t\t7. Insert Record at a position\n");
    printf("\t\t\t8. Reverse records\n");
    printf("\t\t\t9. Print ID tree\n");
    printf("\t\t\t10. Exit\n\n");
    removeDecoration();
}

void guestDisplay()
{
    headTemplate();
    printf(TD_BOLD"\n");
    printf("\t\t\t1. Display Record\n");
    printf("\t\t\t2. Search Record\n");
    printf("\t\t\t3. Sort Record\n");
    printf("\t\t\t4. Reverse records\n");
    printf("\t\t\t5. Print ID tree\n");
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
    char addNext = 'n';
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

    char temp;
    struct donor newDonor;
    int flag = 0;
    newDonor.id = getIDInput('d');
    printf(TD_BOLD"\t\tEnter Donor's name: ");
    scanf("%c", &temp);
    scanf("%[^\n]", newDonor.name); 
    newDonor.age = getAgeInput('d');
    printf(TD_BOLD"\t\tEnter Donor's nationality: _\b");
    scanf("%s", newDonor.nationality);
    printf(TD_BOLD"\t\tEnter Donor's address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newDonor.address);
    while(1)
    {
        printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
        scanf("%s", newDonor.phone_number);
        if (strlen(newDonor.phone_number) == 10 && isPhoneNumberValid(newDonor.phone_number))
            break;
        printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
        removeDecoration();
    }
    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
        scanf("%s", newDonor.blood_group);
        if(strlen(newDonor.blood_group) >= 2)
        {
            newDonor.blood_group[0] = toupper(newDonor.blood_group[0]);
            newDonor.blood_group[1] = toupper(newDonor.blood_group[1]);
        }
        flag=1;
    } while(!isBGValid(newDonor.blood_group));
    flag = 0;

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
        scanf("%c", &temp);
        scanf("%c", &newDonor.sex);
        newDonor.sex = toupper(newDonor.sex);
        flag = 1;
    } while(!isSexValid(newDonor.sex));
    flag = 0;

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
        scanf("%s", newDonor.date);
        flag = 1;
    } while(strlen(newDonor.date) != 10 || !isDateValid(newDonor.date[0], newDonor.date[1], newDonor.date[3], newDonor.date[4]) || !(newDonor.date[2] == '/' && newDonor.date[5]=='/'));
    flag = 0;

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
        scanf("%s", newDonor.time);
        flag = 1;
    } while(strlen(newDonor.time) != 5 || !isTimeValid(newDonor.time[0], newDonor.time[1], newDonor.time[3], newDonor.time[4]) || newDonor.time[2] != ':');

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

    char temp;
    struct acceptor newAcceptor;
    int flag = 0;
    
    newAcceptor.info.id = getIDInput('a');
    printf(TD_BOLD"\t\tEnter Acceptor's name: ");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.info.name); 
    newAcceptor.info.age = getAgeInput('a');
    printf(TD_BOLD"\t\tEnter Acceptor's nationality: _\b");
    scanf("%s", newAcceptor.info.nationality);
    printf(TD_BOLD"\t\tEnter Acceptor's address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.info.address);

    while(1)
    {
        printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
        scanf("%s", newAcceptor.info.phone_number);
        if (strlen(newAcceptor.info.phone_number) == 10 && isPhoneNumberValid(newAcceptor.info.phone_number))
            break;
        printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
        removeDecoration();
    }
    
    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
        scanf("%s", newAcceptor.info.blood_group);
        if(strlen(newAcceptor.info.blood_group) >= 2)
        {
            newAcceptor.info.blood_group[0] = toupper(newAcceptor.info.blood_group[0]);
            newAcceptor.info.blood_group[1] = toupper(newAcceptor.info.blood_group[1]);
        }
        flag = 1;
    } while(!isBGValid(newAcceptor.info.blood_group));
    flag = 0;

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
        scanf("%c", &temp);
        scanf("%c", &newAcceptor.info.sex);
        flag = 1;
    } while(!isSexValid(newAcceptor.info.sex));
    flag = 0;

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
        scanf("%s", newAcceptor.info.date);
        flag = 1;
    } while(strlen(newAcceptor.info.date) != 10 || !isDateValid(newAcceptor.info.date[0], newAcceptor.info.date[1], newAcceptor.info.date[3], newAcceptor.info.date[4]) || !(newAcceptor.info.date[2] == '/' && newAcceptor.info.date[5]=='/'));
    flag = 0; 

    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
        removeDecoration();
        printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
        scanf("%s", newAcceptor.info.time);
        flag = 1;
    } while(strlen(newAcceptor.info.time) != 5 || !isTimeValid(newAcceptor.info.time[0], newAcceptor.info.time[1], newAcceptor.info.time[3], newAcceptor.info.time[4]) || newAcceptor.info.time[2] != ':');


    printf(TD_BOLD"\t\tEnter Hospital Name: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.hospital);
    printf(TD_BOLD"\t\tEnter Hospital Address: _\b");
    scanf("%c", &temp);
    scanf("%[^\n]", newAcceptor.hospital_address);

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
            printf("     %03d\t", temp.id);
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
        main();
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
            printf("     %03d\t", temp.info.id);
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
        main();
    removeDecoration();
}

void searchRecord()
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
            printf(TC_RED TD_BOLD"\n\t\t\tNOT FOUND!\n");
    }
    else
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 for main menu\n");
    choice = takeChoice(0, 1);
    if (!choice)
        exit(0);
    else
        main();

    removeDecoration();
}

void printDonorData(struct donor *data)
{
    printf(TD_BOLD TC_CYAN"\n\t\tUSER TYPE: DONOR\n");
    removeDecoration();
    printf(TD_BOLD"\n\t\tDonor's ID: %03d\n", data->id);
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
    printf(TD_BOLD TC_CYAN"\n\t\tUSER TYPE: ACCEPTOR\n");
    removeDecoration();
    printf(TD_BOLD"\n\t\tAcceptor's ID: %03d\n", data->info.id);
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

void sortRecord()
{
    int choice;
    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);
    switch(choice) 
    {
        case 1:
            sortDonor();
            main();
            break;
        case 2:
            sortAcceptor();
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


void sortDonor()
{
    struct donorBox* box = donorDBtoLL();
    struct donorNode *head = box->head;
    int count = box->count;
    if(head)
    {
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\n\t\t\tSorting Donor's Data!\n");
        sleep(2);

        struct donor newTemp;
        struct donorNode *first = head, *second = head->next;
        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < (count-1-i); ++j)
            {
                if (first->data.id > second->data.id)
                {
                    newTemp = first->data;
                    first->data = second->data;
                    second->data = newTemp;
                }
                first = first->next; 
                second = second->next;
            }
            first = head;
            second = head->next;
        }

        FILE *fp = fopen("./database/donor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }

        first = head;
        while(count--)
        {
            fwrite(&head->data,sizeof(head->data),1,fp);
            head = head->next;
        }
        fclose(fp);

        distroyDonor(first);

        clear();
        headTemplate();
        printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tSorting Complete!\n");
        sleep(2);
    }
    else
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    free(box);
    removeDecoration();
}

void sortAcceptor()
{
    struct acceptorBox* box = acceptorDBtoLL();
    struct acceptorNode *head = box->head;
    int count = box->count;

    if(head)
    {
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\n\t\t\tSorting Acceptor's Data!\n");
        sleep(2);

        struct acceptor newTemp;
        struct acceptorNode *first = head, *second = head->next;
        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < (count-1-i); ++j)
            {
                if (first->data.info.id > second->data.info.id)
                {
                    printf("Got here\n");
                    newTemp = first->data;
                    first->data = second->data;
                    second->data = newTemp;
                }
                first = first->next; 
                second = second->next;
            }
            first = head;
            second = head->next;
        }

        FILE *fp = fopen("./database/acceptor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }

        first = head;
        while(count--)
        {
            fwrite(&first->data,sizeof(first->data),1,fp);
            first = first->next;
        }
        fclose(fp);

        distroyAcceptor(head);

        clear();
        headTemplate();
        printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tSorting Complete!\n");
        sleep(2);
    }
    else
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    }
    free(box);
    removeDecoration();
}

void modifyRecord()
{
    int choice;
    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);
    switch(choice) 
    {
        case 1:
            modifyDonor();
            sleep(2);
            break;
        case 2:
            modifyAcceptor();
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


void modifyDonor()
{
    struct donorBox* box = donorDBtoLL();
    struct donorNode *head = box->head;
    int count = box->count;

    if (head)
    {
        int id, flag = 0;
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\t\tEnter ID to be modified: ");
        scanf("%d", &id);

        struct donorNode *temp = head;

        while(temp != NULL)
        {
            if (temp->data.id == id)
                break;
            temp = temp->next;
        }

        if(temp)
        {
            char t;
            if(wantsToChange("Name"))
            {
                printf(TD_BOLD"\t\tEnter Donor's name: ");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.name); 
            }
            if(wantsToChange("Age"))
            {
                temp->data.age = getAgeInput('d');;
            }
            if(wantsToChange("Nationality"))
            {
                printf(TD_BOLD"\t\tEnter Donor's nationality: _\b");
                scanf("%s", temp->data.nationality);
            }
            if(wantsToChange("Address"))
            {
                printf(TD_BOLD"\t\tEnter Donor's address: _\b");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.address);
            }
            if(wantsToChange("phone_number"))
            {
                while(1)
                {
                    printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
                    scanf("%s", temp->data.phone_number);
                    if (strlen(temp->data.phone_number) == 10 && isPhoneNumberValid(temp->data.phone_number))
                        break;
                    printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
                    removeDecoration();
                }
            }
            if(wantsToChange("Blood_Group"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
                    scanf("%s", temp->data.blood_group);
                    if(strlen(temp->data.blood_group) >= 2)
                    {
                        temp->data.blood_group[0] = toupper(temp->data.blood_group[0]);
                        temp->data.blood_group[1] = toupper(temp->data.blood_group[1]);
                    }
                    flag=1;
                } while(!isBGValid(temp->data.blood_group));
                flag = 0;
            }
            if(wantsToChange("Sex"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
                    scanf("%c", &t);
                    scanf("%c", &temp->data.sex);
                    temp->data.sex = toupper(temp->data.sex);
                    flag = 1;
                } while(!isSexValid(temp->data.sex));
                flag = 0;
            }
            if(wantsToChange("Date"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
                    scanf("%s", temp->data.date);
                    flag = 1;
                } while(strlen(temp->data.date) != 10 || !isDateValid(temp->data.date[0], temp->data.date[1], temp->data.date[3], temp->data.date[4]) || !(temp->data.date[2] == '/' && temp->data.date[5]=='/'));
                flag = 0;
            }
            if(wantsToChange("Time"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
                    scanf("%s", temp->data.time);
                    flag = 1;
                } while(strlen(temp->data.time) != 5 || !isTimeValid(temp->data.time[0], temp->data.time[1], temp->data.time[3], temp->data.time[4]) || temp->data.time[2] != ':');
            }
            FILE *fp = fopen("./database/donor.dat", "wb");
            if (!fp)
            {
               dbError();
               return;
            }
            temp = head;
            while(temp!=NULL)
            {
                fwrite(&temp->data,sizeof(temp->data),1,fp);
                temp = temp->next;
            }
            fclose(fp);
            distroyDonor(head);

            clear();
            headTemplate();
            printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tModification Complete!\n");
            sleep(2);

        }
        else
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_RED TD_UNDERLINE"\n\n\t\t\t\tCan't find that ID!");
            removeDecoration();
        }
        
    }
    else
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    
    free(box);

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        modifyRecord();
    if (choice == 2)
        main();
    removeDecoration();
}

void modifyAcceptor()
{
    struct acceptorBox* box = acceptorDBtoLL();
    struct acceptorNode *head = box->head;
    int count = box->count;

    if (head)
    {
        int id, flag = 0;
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\t\tEnter ID to be modified: ");
        scanf("%d", &id);
        struct acceptorNode *temp = head;
        while(temp != NULL)
        {
            if (temp->data.info.id == id)
                break;
            temp = temp->next;
        }
        if(temp)
        {
            char t;
            if(wantsToChange("Name"))
            {
                printf(TD_BOLD"\t\tEnter Acceptor's name: ");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.info.name); 
            }
            if(wantsToChange("Age"))
            {
                temp->data.info.age = getAgeInput('a');;
            }
            if(wantsToChange("Nationality"))
            {
                printf(TD_BOLD"\t\tEnter Acceptor's nationality: _\b");
                scanf("%s", temp->data.info.nationality);
            }
            if(wantsToChange("Address"))
            {
                printf(TD_BOLD"\t\tEnter Acceptor's address: _\b");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.info.address);
            }
            if(wantsToChange("phone_number"))
            {
                while(1)
                {
                    printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
                    scanf("%s", temp->data.info.phone_number);
                    if (strlen(temp->data.info.phone_number) == 10 && isPhoneNumberValid(temp->data.info.phone_number))
                        break;
                    printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
                    removeDecoration();
                }
            }
            if(wantsToChange("Blood_Group"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
                    scanf("%s", temp->data.info.blood_group);
                    if(strlen(temp->data.info.blood_group) >= 2)
                    {
                        temp->data.info.blood_group[0] = toupper(temp->data.info.blood_group[0]);
                        temp->data.info.blood_group[1] = toupper(temp->data.info.blood_group[1]);
                    }
                    flag = 1;
                } while(!isBGValid(temp->data.info.blood_group));
                flag = 0;
            }
            if(wantsToChange("Sex"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
                    scanf("%c", &t);
                    scanf("%c", &temp->data.info.sex);
                    flag = 1;
                } while(!isSexValid(temp->data.info.sex));
                flag = 0;
            }
            if(wantsToChange("Date"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
                    scanf("%s", temp->data.info.date);
                    flag = 1;
                } while(strlen(temp->data.info.date) != 10 || !isDateValid(temp->data.info.date[0], temp->data.info.date[1], temp->data.info.date[3], temp->data.info.date[4]) || !(temp->data.info.date[2] == '/' && temp->data.info.date[5]=='/'));
                flag = 0;
            }
            if(wantsToChange("Time"))
            {
                do {
                    if (flag)
                        printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
                    removeDecoration();
                    printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
                    scanf("%s", temp->data.info.time);
                    flag = 1;
                } while(strlen(temp->data.info.time) != 5 || !isTimeValid(temp->data.info.time[0], temp->data.info.time[1], temp->data.info.time[3], temp->data.info.time[4]) || temp->data.info.time[2] != ':');
            }
            if(wantsToChange("Hospital_name"))
            {
                printf(TD_BOLD"\t\tEnter Hospital Name: _\b");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.hospital);
            }
            if(wantsToChange("Hospital_address"))
            {
                printf(TD_BOLD"\t\tEnter Hospital Address: _\b");
                scanf("%c", &t);
                scanf("%[^\n]", temp->data.hospital_address);
            }

            FILE *fp = fopen("./database/acceptor.dat", "wb");
            if (!fp)
            {
               dbError();
               return;
            }

            temp = head;
            while(temp!=NULL)
            {
                fwrite(&temp->data,sizeof(temp->data),1,fp);
                temp = temp->next;
            }
            fclose(fp);
            distroyAcceptor(head);

            clear();
            headTemplate();
            printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tModification Complete!\n");
            sleep(2);

        }
        else
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_RED TD_UNDERLINE"\n\n\t\t\t\tCan't find that ID!");
            removeDecoration();
        }    
    }
    else
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");    
    free(box);

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        modifyRecord();
    if (choice == 2)
        main();

    removeDecoration();
}

void deleteId()
{
    int choice;
    donorAndAccepterDisplay();
    printf(TD_BOLD TC_RED"\t\t\t\t5. Delete Everything [DONOR]\n");
    printf(TD_BOLD TC_RED"\t\t\t\t6. Delete Everything [ACCEPTOR]\n\n");
    printf(TC_WHITE);
    choice = takeChoice(1, 6);
    switch(choice) 
    {
        case 1:
            deleteIdDonor();
            break;
        case 2:
            deleteIdAcceptor();
            break;
        case 3:
            main();
        case 4:
            exit(0);
        case 5:
            deleteDonor();
            break;
        case 6:
            deleteAcceptor();
            break;
        default:
            printf(TC_RED"Error!\n");
    }
}

void deleteIdDonor()
{
    struct donorBox* box = donorDBtoLL();
    struct donorNode *head = box->head;
    int entered = 0;

    if (head)
    {
        int id;
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\t\tEnter ID to be Deleted: ");
        scanf("%d", &id);

        FILE *fp = fopen("./database/donor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }

        struct donorNode *temp =  head;
        
        while(head != NULL)
        {
            if (head->data.id == id)
            {
                entered = 1;
                head = head->next;
                continue;
            }

            fwrite(&head->data,sizeof(head->data),1,fp);
            head = head->next;
        }
        fclose(fp);
        distroyDonor(temp);

        if (entered)
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tDeletion Complete!\n");
            sleep(2);
        }
        else
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_RED"\n\n\n\t\t\tID not Found!\n");
        }
    }
    free(box);

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        deleteId();
    if (choice == 2)
        main();
    removeDecoration();
}

void deleteIdAcceptor()
{
    struct acceptorBox* box = acceptorDBtoLL();
    struct acceptorNode *head = box->head;
    int entered = 0;

    if (head)
    {
        int id;
        clear();
        headTemplate();
        printf(TD_BOLD"\n\n\t\tEnter ID to be Deleted: ");
        scanf("%d", &id);

        FILE *fp = fopen("./database/acceptor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }

        struct acceptorNode *temp =  head;
        while(head != NULL)
        {
            if (head->data.info.id == id)
            {
                entered = 1;
                head = head->next;
                continue;
            }
            fwrite(&head->data,sizeof(head->data),1,fp);
            head = head->next;
        }
        fclose(fp);
        distroyAcceptor(temp);

        if (entered)
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tDeletion Complete!\n");
            sleep(2);
        }
        else
        {
            clear();
            headTemplate();
            printf(TD_BOLD TC_RED"\n\n\n\t\t\tID not Found!\n");
        }
    }
    free(box);

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        deleteId();
    if (choice == 2)
        main();
    removeDecoration();
}

void deleteDonor()
{
    clear();
    headTemplate();
    printf(TD_BOLD TC_RED "\n\n\t\t\tDONOR DELETED COMPLETELY!\n");
    FILE *fp = fopen("./database/donor.dat", "wb");
    fclose(fp);

    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    int choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        deleteId();
    if (choice == 2)
        main();
    removeDecoration();
}

void deleteAcceptor()
{
    clear();
    headTemplate();
    printf(TD_BOLD TC_RED "\n\n\t\t\tACCEPTOR DELETED COMPLETELY!\n");
    FILE *fp = fopen("./database/acceptor.dat", "wb");
    fclose(fp);

    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    int choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        deleteId();
    if (choice == 2)
        main();
    removeDecoration();
}

void insertAtPos()
{
    int choice;
    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);
    switch(choice) 
    {
        case 1:
            insertAtPosDonor();
            break;
        case 2:
            insertAtPosAcceptor();
            break;
        case 3:
            main();
        case 4:
            exit(0);
        default:
            printf(TC_RED"Error!\n");
    }
}

void insertAtPosDonor()
{
    clear();
    headTemplate();
    struct donorBox* box = donorDBtoLL();
    struct donorNode *head = box->head;
    int count = box->count;

    int pos;
    int flag = 0;
    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tCan't insert at that location!\n");
        if (!flag)
            printf("\n\n");
        printf(TD_BOLD TC_WHITE"\t\tEnter position (else 0): _\b");
        scanf("%d", &pos);
        if (pos == 0)
            main();
        flag = 1;
    } while(pos < 0 || pos > count+1);
    flag = 0;

    if (pos == count+1)
        addNewDonor();
    else
    {
        struct donorNode *t = head;
        if(pos != 1)
        {
            for (int i = 0; i < pos-2; ++i)
                t = t->next;
        }

        char temp;
        struct donorNode *newDonor = (struct donorNode*)malloc(sizeof(struct donorNode));
        newDonor->data.id = getIDInput('d'); 
        printf(TD_BOLD"\t\tEnter Donor's name: ");
        scanf("%c", &temp);
        scanf("%[^\n]", newDonor->data.name); 
        newDonor->data.age = getAgeInput('d');;
        printf(TD_BOLD"\t\tEnter Donor's nationality: _\b");
        scanf("%s", newDonor->data.nationality);
        printf(TD_BOLD"\t\tEnter Donor's address: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newDonor->data.address);

        while(1)
        {
            printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
            scanf("%s",  newDonor->data.phone_number);
            if (strlen(newDonor->data.phone_number) == 10 && isPhoneNumberValid(newDonor->data.phone_number))
                break;
            printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
            removeDecoration();
        }

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
            scanf("%s", newDonor->data.blood_group);
            if(strlen(newDonor->data.blood_group) >= 2)
            {
                newDonor->data.blood_group[0] = toupper(newDonor->data.blood_group[0]);
                newDonor->data.blood_group[1] = toupper(newDonor->data.blood_group[1]);
            }
            flag=1;
        } while(!isBGValid(newDonor->data.blood_group));
        flag = 0;
        
        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
            scanf("%c", &temp);
            scanf("%c", &newDonor->data.sex);
            newDonor->data.sex = toupper(newDonor->data.sex);
            flag = 1;
        } while(!isSexValid(newDonor->data.sex));
        flag = 0;

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
            scanf("%s", newDonor->data.date);
            flag = 1;
        } while(strlen(newDonor->data.date) != 10 || !isDateValid(newDonor->data.date[0], newDonor->data.date[1], newDonor->data.date[3], newDonor->data.date[4]) || !(newDonor->data.date[2] == '/' && newDonor->data.date[5]=='/'));
        flag = 0;

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
            scanf("%s", newDonor->data.time);
            flag = 1;
        } while(strlen(newDonor->data.time) != 5 || !isTimeValid(newDonor->data.time[0], newDonor->data.time[1], newDonor->data.time[3], newDonor->data.time[4]) || newDonor->data.time[2] != ':');

        if (pos == 1)
        {
            newDonor->next = head;
            head = newDonor;
        }
        else
        {
            newDonor->next = t->next;
            t->next = newDonor;
        }

        FILE *fp = fopen("./database/donor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }

        t = head;
        while(t!=NULL)
        {
            fwrite(&t->data,sizeof(t->data),1,fp);
            t = t->next;
        }
        fclose(fp);
    }
    distroyDonor(head);
    free(box);

    sleep(2);

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        insertAtPos();
    if (choice == 2)
        main();
    removeDecoration();
}

void insertAtPosAcceptor()
{
    clear();
    headTemplate();
    struct acceptorBox* box = acceptorDBtoLL();
    struct acceptorNode *head = box->head;
    int count = box->count;

    int pos;
    int flag = 0;
    do {
        if (flag)
            printf(TC_RED TD_BOLD"\t\t\tCan't insert at that location!\n");
        if (!flag)
            printf("\n\n");
        printf(TD_BOLD TC_WHITE"\t\tEnter position (else 0): _\b");
        scanf("%d", &pos);
        if (pos == 0)
            main();
        flag = 1;
    } while(pos < 0 || pos > count+1);
    flag = 0;

    if (pos == count+1)
        addNewAcceptor();
    else
    {
        struct acceptorNode *t = head;
        if(pos != 1)
        {
            for (int i = 0; i < pos-2; ++i)
                t = t->next;
        }
        
        struct acceptorNode *newAcceptor = (struct acceptorNode*)malloc(sizeof(struct acceptorNode));
        char temp;

        newAcceptor->data.info.id = getIDInput('a');
        printf(TD_BOLD"\t\tEnter Acceptor's name: ");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.info.name); 
        newAcceptor->data.info.age = getAgeInput('a');;
        printf(TD_BOLD"\t\tEnter Acceptor's nationality: _\b");
        scanf("%s", newAcceptor->data.info.nationality);
        printf(TD_BOLD"\t\tEnter Acceptor's address: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.info.address);

        while(1)
        {
            printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
            scanf("%s", newAcceptor->data.info.phone_number);
            if (strlen(newAcceptor->data.info.phone_number) == 10 && isPhoneNumberValid(newAcceptor->data.info.phone_number))
                break;
            printf(TC_RED TD_BOLD"\t\t\tInvalid Phone number!\n");
            removeDecoration();
        }

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid Blood Group!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
            scanf("%s", newAcceptor->data.info.blood_group);
            if(strlen(newAcceptor->data.info.blood_group) >= 2)
            {
                newAcceptor->data.info.blood_group[0] = toupper(newAcceptor->data.info.blood_group[0]);
                newAcceptor->data.info.blood_group[1] = toupper(newAcceptor->data.info.blood_group[1]);
            }
            flag = 1;
        } while(!isBGValid(newAcceptor->data.info.blood_group));
        flag = 0;

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid sex!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
            scanf("%c", &temp);
            scanf("%c", &newAcceptor->data.info.sex);
            flag = 1;
        } while(!isSexValid(newAcceptor->data.info.sex));
        flag = 0;

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid date!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
            scanf("%s", newAcceptor->data.info.date);
            flag = 1;
        } while(strlen(newAcceptor->data.info.date) != 10 || !isDateValid(newAcceptor->data.info.date[0], newAcceptor->data.info.date[1], newAcceptor->data.info.date[3], newAcceptor->data.info.date[4]) || !(newAcceptor->data.info.date[2] == '/' && newAcceptor->data.info.date[5]=='/'));
        flag = 0; 

        do {
            if (flag)
                printf(TC_RED TD_BOLD"\t\t\tInvalid time!\n");
            removeDecoration();
            printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
            scanf("%s", newAcceptor->data.info.time);
            flag = 1;
        } while(strlen(newAcceptor->data.info.time) != 5 || !isTimeValid(newAcceptor->data.info.time[0], newAcceptor->data.info.time[1], newAcceptor->data.info.time[3], newAcceptor->data.info.time[4]) || newAcceptor->data.info.time[2] != ':');

        printf(TD_BOLD"\t\tEnter Hospital Name: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.hospital);
        printf(TD_BOLD"\t\tEnter Hospital Address: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.hospital_address);
        if (pos == 1)
        {
            newAcceptor->next = head;
            head = newAcceptor;
        }
        else
        {
            newAcceptor->next = t->next;
            t->next = newAcceptor;
        }
        FILE *fp = fopen("./database/acceptor.dat", "wb");
        if (!fp)
        {
           dbError();
           return;
        }
        t = head;
        while(t!=NULL)
        {
            fwrite(&t->data,sizeof(t->data),1,fp);
            t = t->next;
        }
        fclose(fp);
    }
    distroyAcceptor(head);
    free(box);

    int choice;    
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        insertAtPos();
    if (choice == 2)
        main();
    removeDecoration();
}

void reverseRecords()
{
    int choice;
    donorAndAccepterDisplay();
    choice = takeChoice(1, 4);
    switch(choice) 
    {
        case 1:
            reverseRecordsDonor();
            break;
        case 2:
            reverseRecordsAcceptor();
            break;
        case 3:
            main();
        case 4:
            exit(0);
        default:
            printf(TC_RED"Error!\n");
    }
}

void reverseRecordsDonor()
{
    struct donorBox* box = donorDBtoLL();
    struct donorNode *head = box->head;
    struct donorNode *reverse = NULL;

    clear();
    headTemplate();
    printf(TD_BOLD"\n\n\n\t\t\tReversing Donor's Data!\n");
    sleep(2);

    struct donorNode *temp = head;
    while(head != NULL)
    {
        reverse = insertAtTopDonor(reverse, head);
        head = head->next;
    }
    distroyDonor(temp);

    FILE *fp = fopen("./database/donor.dat", "wb");
    if (!fp)
    {
       dbError();
       return;
    }

    head = reverse;
    while(reverse!=NULL)
    {
        fwrite(&reverse->data,sizeof(reverse->data),1,fp);
        reverse = reverse->next;
    }
    fclose(fp);

    distroyDonor(head);
    free(box);

    clear();
    headTemplate();
    printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tReversed!\n");

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        reverseRecords();
    if (choice == 2)
        main();

    removeDecoration();
}

void reverseRecordsAcceptor()
{
    struct acceptorBox* box = acceptorDBtoLL();
    struct acceptorNode *head = box->head;
    struct acceptorNode *reverse = NULL;

    clear();
    headTemplate();
    printf(TD_BOLD"\n\n\n\t\t\tReversing Acceptor's Data!\n");
    sleep(2);

    struct acceptorNode *temp = head;
    while(head != NULL)
    {
        reverse = insertAtTopAcceptor(reverse, head);
        head = head->next;
    }
    distroyAcceptor(temp);

    FILE *fp = fopen("./database/acceptor.dat", "wb");
    if (!fp)
    {
       dbError();
       return;
    }

    head = reverse;
    while(reverse!=NULL)
    {
        fwrite(&reverse->data,sizeof(reverse->data),1,fp);
        reverse = reverse->next;
    }
    fclose(fp);

    distroyAcceptor(head);
    free(box);

    headTemplate();
    printf(TD_BOLD TC_GREEN"\n\n\n\t\t\tReversed!\n");

    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit, 1 to go back or 2 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice == 1)
        reverseRecords();
    if (choice == 2)
        main();
    removeDecoration();
}

void printIdTree()
{
    headTemplate();
    printf("\n\n");
    printf(TD_BOLD);
    struct idTreeNode *root = getTreeID();

    if (root)
        draw_tree(root);
    else
    {
        printf(TC_RED TD_UNDERLINE TD_BOLD"\t\t\t NO DATA AVAILABLE\n");
        removeDecoration();
    }


    int choice;
    printf(TC_GREEN TD_BOLD"\n\n\t\tPress 0 to exit or 1 for main menu\n");
    choice = takeChoice(0, 2);
    if (!choice)
        exit(0);
    if (choice)
        main();
    removeDecoration();
}