#ifndef LINKEDLIST_H_  
#define LINKEDLIST_H_

struct donorNode * getNewDonorNode();
struct acceptorNode * getNewAcceptorNode();

struct donorBox* donorDBtoLL();
struct acceptorBox* acceptorDBtoLL();

void distroyAcceptor(struct acceptorNode *);
void distroyDonor(struct donorNode *);

#endif