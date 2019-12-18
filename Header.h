#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct {
	char name[80 + 1];
	char phone[12 + 1];
	int group;
} Contact;

typedef struct {
	Contact* data = new Contact;
	size_t size = 0;
	size_t capacity = 0;
} Vector;

Vector* CreateList();
void menu(Vector* list);
void NameCheckup(Vector* list, Contact* c);
int StrToEnum(char group[20]);
void CreateContact(Vector* list);
void DeleteContact(Vector* list);
void EditName(Vector* list, int index);
void EditPhoneNumber(Vector* list, int index);
void EditGroup(Vector* list, int index);
int FindByName(Vector* list, char* name);
void EditContact(Vector* list);
void erase(Vector* v, size_t index);
void reserve(Vector* v, size_t newCap);
void PrintByName(Vector* list);
void PrintByNumber(Vector* list);
void PrintByGroup(Vector* list);
void ShowContacts(Vector* list);
void PrintContact(Vector* list, int index);
void PrintAllContacts(Vector* list);

void load(Vector* list, fstream& file);
void saveto(Vector* list, fstream& file);