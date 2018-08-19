#ifndef CONTAINERS_H_  
#define CONTAINERS_H_

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


struct donorNode {
	struct donor data;
	struct donorNode *next;
};


struct acceptorNode {
	struct acceptor data;
	struct acceptorNode *next;
};

#endif