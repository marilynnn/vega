#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Header.h"

using namespace std;

int main() {
	Vector* PhoneBook = CreateList();
	while (true) {
		menu(PhoneBook);
		
	}
	return 0;
}