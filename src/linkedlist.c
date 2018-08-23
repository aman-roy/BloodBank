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

    if(fread(&temp->data,sizeof(temp->data),1,fp))
    {
    	int count = 0;
        struct donorNode *head = NULL;
        rewind(fp);

        while(fread(&temp->data,sizeof(temp->data),1,fp))
        {
            if (head == NULL)
            {
                head = temp;
                temp = getNewDonorNode();
                count++;
                continue;
            }
            temp->next = head;
            head = temp;
            count++;
            temp = getNewDonorNode();
        }
        free(temp);
        fclose(fp);

        struct donorBox *box = (struct donorBox *)malloc(sizeof(struct donorBox));
        box->head = head;
        box->count = count;
        return box;
    }
    else
    {
    	free(temp);
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
        return NULL;
    }
}

struct acceptorBox *acceptorDBtoLL()
{
	FILE *fp = loadFile('a');
    if (!fp)
       return NULL;
    struct acceptorNode *temp = getNewAcceptorNode();

    if(fread(&temp->data,sizeof(temp->data),1,fp))
    {
    	int count = 0;
        struct acceptorNode *head = NULL;
        rewind(fp);

        while(fread(&temp->data,sizeof(temp->data),1,fp))
        {
            if (head == NULL)
            {
                head = temp;
                temp = getNewAcceptorNode();
                count++;
                continue;
            }
            temp->next = head;
            head = temp;
            count++;
            temp = getNewAcceptorNode();
        }
        free(temp);
        fclose(fp);

        struct acceptorBox *box = (struct acceptorBox *)malloc(sizeof(struct acceptorBox));
        box->head = head;
        box->count = count;
        return box;
    }
    else
    {
    	free(temp);
        printf(TD_BOLD TC_RED TD_UNDERLINE"\t\t\t\tNO DATA AVAILABLE!\n");
        return NULL;
    }
}