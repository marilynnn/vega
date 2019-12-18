#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Header.h"
#include <fstream>


enum Groups {
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

Vector* CreateList() {
	Vector* list = new Vector;
	list->data = 0;
	list->size = 0;
	list->capacity = 0;
	return list;
}

void menu(Vector* list) {
	int command;
	while (true) {
		std::cout << "List of available commands :" << std::endl
			<< "1. Create contact" << std::endl
			<< "2. Delete contact" << std::endl
			<< "3. Edit contact" << std::endl
			<< "4. Show contact(s)" << std::endl
			<< "5. Exit" << std::endl;
		std::cout << "Command: ";
		std::cin>> command;
		std::cout << std::endl;
		if (std::cin.fail()) {
			command = 0;
		}
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		switch (command) {
			case 1: {
				CreateContact(list);
				break;
			}
			case 2: {
				DeleteContact(list);
				break;
			}
			case 3: {
				EditContact(list);
				break;
			}
			case 4: {
				ShowContacts(list);
				break;
			}
			case 5: {
				return;
			}
			default: {
				std::cout << " This command does not exist.";
			}
	    }
	}
}
void NameCheckup(Vector* list, Contact* c) {
	bool flag = false;
	char* buf= new char [80];
	while (true) {
		std::cout << "Enter name: ";
		std::cin.getline(buf, 80);
		for (int i = 0; i < list->size; ++i) {
			if (strcmp(buf, list->data[i].name) == 0)
			{ 
				std::cout << "Error! This name cannot be used. Choose another name." << std::endl;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			strcpy_s(c->name, buf);
			return;
		}
		else {
			flag = false;
			continue;
		}
	}

}
int StrToEnum() {
	while (true) {
		char* group = new char[20];
		std::cin.getline(group, 12);

		if (strcmp(group, "friends") == 0 || strcmp(group, "Friends") == 0 || strcmp(group, "FRIENDS") == 0) {
			return FRIENDS;
		}
		else if (strcmp(group, "family") == 0 || strcmp(group, "Family") == 0 || strcmp(group, "FAMILY") == 0) {
			return FAMILY;
		}
		else if (strcmp(group, "colleagues") == 0 || strcmp(group, "Colleagues") == 0 || strcmp(group, "COLLEAGUES") == 0) {
			return COLLEAGUES;
		}
		else if (strcmp(group, "no group") == 0 || strcmp(group, "No group") == 0 || strcmp(group, "NO GROUP") == 0) {
			return NO_GROUP;
		}
		else {
			std::cout << "Error! This group does not exist. Enter correct group" << std::endl;
		}

	}
}
void CreateContact(Vector* list) {
	reserve(list, list->size + 1);
	std::cout << "Contact creation:" << std::endl << std::endl;
	
	Contact* c = new Contact;
	NameCheckup(list, c);

	cout << "Enter phone number: ";
	std::cin.getline(c->phone, 12);

	std::cout << "Enter group: " << std::endl
		<< "1. NO_GROUP" << std::endl
		<< "2. FAMILY" << std::endl
		<< "3. FRIENDS" << std::endl
		<< "4. COLLEAGUES" << std::endl;

	c->group = StrToEnum();
	list->data[list->size] = *c;
	list->size++;
	std::cout << std::endl;

}
void DeleteContact(Vector* list) {

	std::cout << "Enter name: ";
	char* del = new char[80];
	std::cin.getline(del, 80);
	for (int i = 0; i < list->size; i++) {
		if (strcmp(del, list->data[i].name) == 0) {
			erase(list, i);
			return;
		}
	}
	std::cout << "This contact does not exist" << std::endl;
}
void EditName(Vector* list, int index) {
	std::cout << "Enter new name: ";
	char* newName = new char[81];
	std::cin.getline(newName, 81);
	strcpy_s(list->data[index].name, newName);
}
void EditPhoneNumber(Vector* list, int index) {
	cout << "Enter new phone number: ";
	char* newNumber = new char[13];
	std::cin.getline(newNumber, 13);
	strcpy_s(list->data[index].phone, newNumber);
}
void EditGroup(Vector* list, int index) {
	std::cout << "Enter new group: ";
	list->data[index].group = StrToEnum();
}
int  FindByName(Vector* list, char* name) {
	for (int i = 0; i < list->size; i++) {
		if (strcmp(name, list->data[i].name) == 0) {
			return i;
		}
	}
	std::cout << "This contact does not exist" << std::endl;
	return -1;
}
void EditContact(Vector* list) {
	int index;
	while (true) {
		std::cout << "Enter contact name: ";
		char* buf = new char[80];
		std::cin.getline(buf, 80);
		int ind = FindByName(list, buf);
		if (ind == -1) {
			continue;
		}
		else {
			index = ind;
			break;
		}
	}
	std::cout << "1. Edit name " << std::endl
		<< "2. Edit phone number" << std::endl
		<< "3. Edit group" << std::endl
		<< "4. Back " << std::endl;

	int editby;
	while (true) {
		std::cin >> editby;
		if (std::cin.fail()) {
			editby = 0;
		}
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		switch (editby) {
		case 1: 
			EditName(list, index);
			return;
		


		case 2: 
			EditPhoneNumber(list, index);
			return;
		
		case 3: 
			EditGroup(list, index);
			return;
		
		case 4: 
			//возврат к меню
			return;
		

		default: 
			std::cout << "Error";
			break;
		
		}
	}
}
void erase(Vector* v, size_t index) {

	for (size_t i = index; i < v->size; i++) {
		v->data[i] = v->data[i + 1];
	}
	v->size--;
	reserve(v, v->size);
}
void reserve(Vector* v, size_t newCap) {

	if (newCap > v->capacity) {
		Contact* new_data = new Contact[newCap];
		memcpy(new_data, v->data, v->capacity * sizeof(Contact));
		delete[] v->data;
		v->data = new_data;
	}
	v->capacity = newCap;
}
void PrintByName(Vector* list) {

	std::cout << "Enter name: ";
	char* name = new char[81];
	std::cin.getline(name, 81);
	int i = FindByName(list, name);
	PrintContact(list, i);
}
void PrintByNumber(Vector* list) {
	std::cout << "Enter phone number: ";
	char* number = new char[13];
	std::cin.getline(number, 13);

	for (int i = 0; i < list->size; ++i) {
		if (strcmp(number, list->data[i].phone) == 0) {
			PrintContact(list, i);
		}
	}
}
void PrintByGroup(Vector* list) {
	std::cout << "Enter group: ";
	int gr = StrToEnum();
	for (int i = 0; i < list->size; ++i) {
		if (gr == list->data[i].group) {
			PrintContact(list, i);
		}
	}
}
void ShowContacts(Vector* list) {
	std::cout << "Print contact(s) :" << std::endl
		<< "1. By name" << std::endl
		<< "2. By phone number" << std::endl
		<< "3. By group" << std::endl
		<< "4. All contacts" << std::endl
		<< "5. Back" << std::endl<<std::endl;

	int command;
	while (true) {
		std::cout << "Command: ";
		std::cin >> command;
		if (std::cin.fail())
			command = 0;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		switch (command) {
		case 1:
			PrintByName(list);
			return;
		case 2:
			PrintByNumber(list);
			return;
		case 3:
			PrintByGroup(list);
			return;
		case 4:
			PrintAllContacts(list);
			return;
		case 5:
			//возврат к менюшке;
			return;
		default:
			std::cout << "Error!";
			break;
		}
	}
}
void PrintContact(Vector* list, int index) {
	std::cout << "Name: " << list->data[index].name << std::endl;
	std::cout << "Number: " << list->data[index].phone << std::endl;
	std::cout << "Group: ";
	switch (list->data[index].group) {

	case NO_GROUP: {
		std::cout << "No group";
		break;
	}

	case FAMILY: {
		std::cout << "Family";
		break;
	}

	case FRIENDS: {
		std::cout << "Friends";
		break;
	}

	case COLLEAGUES: {
		std::cout << "Colleagues";
		break;
	}
	}
	std::cout << std::endl<<std::endl;
}
void PrintAllContacts(Vector* list) {
	for (int i = 0; i < list->size; ++i) {
		PrintContact(list, i);
	}
}



void load(Vector* list, fstream& file) {
	if (!file.is_open())
	{
		cout << "Error!";
		return;
	}

	file.seekg(0, ios::beg);

	char buf[1024];
	int line = 0;
	while (!file.eof()) {
		file.getline(buf, 1024);
		if (strlen(buf) == NULL)
			continue;
		strtok
	}
}