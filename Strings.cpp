#include "Strings.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

MyString::MyString()
{
	_data = new char[1];
	_data[0] = '\0';
	_size = 0;
}

MyString::MyString(const MyString& copy)  {
	this->_size = copy._size;
	_data = new char[this->_size + 1];
	strcpy(this->_data, copy._data);
}

MyString::MyString(const char* str)  {
	this->_size = strlen(str);
	this->_data = new char[_size + 1];
	strcpy(this->_data, str);
}

// MyString a("Hello");
MyString MyString::cat(const MyString& first) const {
	MyString result;
	result._size = this->_size + first._size;
	if (result._data) {
		delete[] result._data;
	}
	result._data = new char[result._size + 1];
	strcat(result._data, this->_data);
	strcat(result._data, first._data);

	return result;
}

MyString& MyString::mutableCat(const MyString& first) {
	char* buf = new char[this->_size + first._size + 1];
	if (this->_data) {
		strcpy(buf, this->_data);
		delete[] this->_data;
	}
	strcat(buf, first._data);
	this->_data = buf;
	this->_size = this->_size + first._size;

	return *this;
}

MyString MyString::operator+(const MyString& first)  {
	return this->cat(first);
}

MyString MyString::operator+ (const char* string) {
	MyString buf(string);
	return this->cat(buf);
};

MyString& MyString::operator= (const MyString& string) {
	std::cout << "Copy = operator" << std::endl;
	MyString buf(string);/*cоздаем буфер для использования swap (меняет местами указатели)*/
	this->_size = buf._size;
	swap(this->_data, buf._data);

	/* Не реюзая код конструктора копирования */
	/*
	delete[] _data;
	this->_size = string._size;
	thid->_data = new char[_size + 1];
	strcpy(_data, string._data);
	*/

	return *this;
}

MyString& MyString::operator= (const char* string) {
	/* Добавить вариант с использованием конструктора с параметром*/
	/*MyString buf(string);
	  this->_size = buf._size;
	  swap (this->data, buf._data);
	  return *this;
	*/
	
	std::cout << "Copy = operator for cstring" << std::endl;
	delete[] this->_data;
	this->_size = strlen(string);
	this->_data = new char[_size + 1];
	strcpy(this->_data, string);
	return *this;
}

MyString& MyString::operator+=(MyString& string) {
	return this->mutableCat(string);//????
}

MyString& MyString::operator+=(const char* string) {
	MyString buf(string);
	return this->mutableCat(buf);//????
}

bool MyString::operator== (MyString& string) {
	return (strcmp(this->_data, string._data) == 0) ?  true : false;
}

bool MyString::operator== (const char* string) {
	return (strcmp(this->_data, string) == 0) ? true : false;
}
MyString	MyString::reverse() {
	if (this->_size) {
		MyString buf;
		buf._size = this->_size + 1;
		buf._data = new char[buf._size];
		for (size_t i = 0; i < strlen(this->_data); ++i)
			buf._data[i] = this->_data[strlen(this->_data -1 - i)]; //проверь
		delete[] this->_data;
		this->_data = buf._data;
	}
	return *this;//зачем возвращаем?
}

size_t MyString::size() const {
	return this->_size;
}

bool	MyString::isEmpty() {
	return (strlen(this->_data)==0)? true : false; 
	/*return (this->_size == 0) ? true : false;*/
}


MyString::~MyString()
{
	if (_data) {
		delete[] _data;
	}
	_size = 0;
}


//void MyString::print() const {
//	std::cout << this->_data << std::endl;
//}