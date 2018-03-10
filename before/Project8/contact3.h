#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define INIT_CONTACT_SIZE 64
#define INC_SIZE 32
#define FILE_NAME "fileBak.txt"

#pragma warning(disable:4996)

typedef struct person {
	char name[32];
	char sex;
	unsigned char age;
	char phone[16];
	char addr[128];
}person_t, *person_p, **person_pp;

typedef struct contact {
	int cap;
	int size;
	person_p contactList;
}contact_t, *contact_p, **contact_pp;

void initContact(contact_pp c);
void destroyContact(contact_p c);
void addContact(contact_p c, person_p p);
void delContact(contact_p c, const char *nameKey);
//void searchContact();
//void modContact();
void showContact(contact_p c);
void clearContact(contact_p c);
//void sortContact();

void print_menu();

int fileLoad(contact_p c);
int fileStore(contact_p c);




#endif