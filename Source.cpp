#include <iostream>
#include <cstring>
#include "Strings.h"

using namespace std;

int main() {
	MyString a;
	MyString b = "Hello";
	a += b;
   
	cout << a;

	return 0;
}