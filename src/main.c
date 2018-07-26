#include <stdio.h>
#include "../include/color.h"

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


int main()
{
    printf(TGRN "Hello world!\n");
    printf(TMAG "%d\n", add(3,5));
    return 0;
}
