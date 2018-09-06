#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include "../include/color.h"
#include "../include/utilities.h"
#include "../include/containers.h"
#include "../include/linkedlist.h"


// Function Prototype for displaying
void headTemplate();
void mainDisplay();
void donorAndAccepterDisplay();


// Function Prototype for each operations
void addNewRecord();
void displayRecord();
void searchRecord();
void sortRecord();
void modifyRecord();
void deleteId();
void insertAtPos();


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

int main()
{
    mainDisplay();
    dbSetup();
    int ch = takeChoice(1, 8);
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
        default:
            printf(TD_BOLD "EXIT!\n");
    }

    removeDecoration();
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
    printf("\t\t\t8. Exit\n\n");
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
    {
        main();
    }

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
        {
            printf(TC_RED TD_BOLD"\n\t\t\tNOT FOUND!\n");
        }
    }
    else
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    }

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
    {
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    }
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
        int id;
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
                printf(TD_BOLD"\t\tEnter Donor's age: _\b");
                scanf("%d", &temp->data.age);
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
                printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
                scanf("%s", temp->data.phone_number);
            }

            if(wantsToChange("Blood_Group"))
            {
                printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
                scanf("%s", temp->data.blood_group);
            }

            if(wantsToChange("Sex"))
            {
                printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
                scanf("%c", &t);
                scanf("%c", &temp->data.sex);
            }

            if(wantsToChange("Date"))
            {
                printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
                scanf("%s", temp->data.date);
            }

            if(wantsToChange("Time"))
            {
                printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
                scanf("%s", temp->data.time);
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
        int id;
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
                printf(TD_BOLD"\t\tEnter Acceptor's age: _\b");
                scanf("%d", &temp->data.info.age);
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
                printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
                scanf("%s", temp->data.info.phone_number);
            }

            if(wantsToChange("Blood_Group"))
            {
                printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
                scanf("%s", temp->data.info.blood_group);
            }

            if(wantsToChange("Sex"))
            {
                printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
                scanf("%c", &t);
                scanf("%c", &temp->data.info.sex);
            }

            if(wantsToChange("Date"))
            {
                printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
                scanf("%s", temp->data.info.date);
            }

            if(wantsToChange("Time"))
            {
                printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
                scanf("%s", temp->data.info.time);
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
                scanf("%c", &temp);
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
    return;
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

        // temp variable for clearing buffer
        char temp;

        struct donorNode *newDonor = (struct donorNode*)malloc(sizeof(struct donorNode));
        
        printf(TD_BOLD"\n\t\tEnter Donor's ID: _\b");
        scanf("%d", &newDonor->data.id); 

        printf(TD_BOLD"\t\tEnter Donor's name: ");
        scanf("%c", &temp);
        scanf("%[^\n]", newDonor->data.name); 
        

        printf(TD_BOLD"\t\tEnter Donor's age: _\b");
        scanf("%d", &newDonor->data.age);

        printf(TD_BOLD"\t\tEnter Donor's nationality: _\b");
        scanf("%s", newDonor->data.nationality);

        printf(TD_BOLD"\t\tEnter Donor's address: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newDonor->data.address);

        printf(TD_BOLD"\t\tEnter Donor's phone number: _\b");
        scanf("%s", newDonor->data.phone_number);

        printf(TD_BOLD"\t\tEnter Donor's blood group: _\b");
        scanf("%s", newDonor->data.blood_group);

        printf(TD_BOLD"\t\tEnter Donor's sex: _\b");
        scanf("%c", &temp);
        scanf("%c", &newDonor->data.sex);

        printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
        scanf("%s", newDonor->data.date);

        printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
        scanf("%s", newDonor->data.time);

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
        
        // temp variable for clearing buffer
        char temp;
        
        printf(TD_BOLD"\n\t\tEnter Acceptor's ID:  _\b");
        scanf("%d", &newAcceptor->data.info.id);

        printf(TD_BOLD"\t\tEnter Acceptor's name: ");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.info.name); 
        

        printf(TD_BOLD"\t\tEnter Acceptor's age: _\b");
        scanf("%d", &newAcceptor->data.info.age);

        printf(TD_BOLD"\t\tEnter Acceptor's nationality: _\b");
        scanf("%s", newAcceptor->data.info.nationality);

        printf(TD_BOLD"\t\tEnter Acceptor's address: _\b");
        scanf("%c", &temp);
        scanf("%[^\n]", newAcceptor->data.info.address);

        printf(TD_BOLD"\t\tEnter Acceptor's phone number: _\b");
        scanf("%s", newAcceptor->data.info.phone_number);

        printf(TD_BOLD"\t\tEnter Acceptor's blood group: _\b");
        scanf("%s", newAcceptor->data.info.blood_group);

        printf(TD_BOLD"\t\tEnter Acceptor's sex: _\b");
        scanf("%c", &temp);
        scanf("%c", &newAcceptor->data.info.sex);

        printf(TD_BOLD"\t\tEnter blood donation date[DD/MM/YYYY]: _\b");
        scanf("%s", newAcceptor->data.info.date);

        printf(TD_BOLD"\t\tEnter blood donation time[HH:MM]: _\b");
        scanf("%s", newAcceptor->data.info.time);

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