#include <stdlib.h>
#include <stdio.h>

#include "../include/linkedlist.h"
#include "../include/containers.h"
#include "../include/utilities.h"
#include "../include/color.h"

struct donorNode * getNewDonorNode()
{
    struct donorNode *temp = (struct donorNode *)malloc(sizeof(struct donorNode));
    temp->next = NULL;
    return temp;
}

struct acceptorNode * getNewAcceptorNode()
{
    struct acceptorNode *temp = (struct acceptorNode *)malloc(sizeof(struct acceptorNode));
    temp->next = NULL;
    return temp;
}


struct donorBox* donorDBtoLL()
{
	FILE *fp = loadFile('d');
    if (!fp)
       return NULL;
    struct donorNode *temp = getNewDonorNode();
    struct donorBox *box = (struct donorBox *)malloc(sizeof(struct donorBox));
    if(fread(&temp->data,sizeof(temp->data),1,fp))
    {
    	int count = 0;
        struct donorNode *head = NULL;
        struct donorNode *front = NULL;
        rewind(fp);

        while(fread(&temp->data,sizeof(temp->data),1,fp))
        {
            if (head == NULL)
            {
                head = temp;
                front = head;
                temp = getNewDonorNode();
                count++;
                continue;
            }
            head->next = temp;
            head = temp;
            count++;
            temp = getNewDonorNode();
        }
        free(temp);
        fclose(fp);

        box->head = front;
        box->count = count;
    }
    else
    {
        box->head = NULL;
        box->count = 0;
    	free(temp);
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
    }
    return box;
}



struct acceptorBox *acceptorDBtoLL()
{
	FILE *fp = loadFile('a');
    if (!fp)
       return NULL;
    struct acceptorNode *temp = getNewAcceptorNode();
    struct acceptorBox *box = (struct acceptorBox *)malloc(sizeof(struct acceptorBox));
    if(fread(&temp->data,sizeof(temp->data),1,fp))
    {
    	int count = 0;
        struct acceptorNode *head = NULL;
        struct acceptorNode *front = NULL;
        rewind(fp);

        while(fread(&temp->data,sizeof(temp->data),1,fp))
        {
            if (head == NULL)
            {
                head = temp;
                front = head;
                temp = getNewAcceptorNode();
                count++;
                continue;
            }
            head->next = temp;
            head = temp;
            count++;
            temp = getNewAcceptorNode();
        }
        free(temp);
        fclose(fp);
        
        box->head = front;
        box->count = count;
    }
    else
    {
        box->head = NULL;
        box->count = 0;
    	free(temp);
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
        sleep(2);
    }
    return box;
}

void distroyAcceptor(struct acceptorNode *head)
{
	if (head == NULL)
	{
		return;
	}
	distroyAcceptor(head->next);
	free(head);
}

void distroyDonor(struct donorNode *head)
{
	if (head == NULL)
	{
		return;
	}
	distroyDonor(head->next);
	free(head);
}

struct donorNode * insertAtTopDonor(struct donorNode * current, struct donorNode * head)
{
    struct donorNode *temp = (struct donorNode *)malloc(sizeof(struct donorNode));
    temp->data = head->data;

    if (current == NULL)
    {
        current = temp;
        current->next = NULL;
    }
    else
    {
        temp->next = current;
        current = temp;
    }
    return current;
}

struct acceptorNode * insertAtTopAcceptor(struct acceptorNode * current, struct acceptorNode * head)
{
    struct acceptorNode *temp = (struct acceptorNode *)malloc(sizeof(struct acceptorNode));
    temp->data = head->data;

    if (current == NULL)
    {
        current = temp;
        current->next = NULL;
    }
    else
    {
        temp->next = current;
        current = temp;
    }
    return current;
}

