#pragma once

#include <iostream>

using std::swap;

class MyString
{
public:
	MyString();										//конструктор по умолчанию
	MyString(const MyString& string);			//конструктор копирования [MyString copyString(string);]
	MyString(const char* string);					//конструктор c параметром [MyString copyString(string);]

	MyString& operator= (const MyString& string);	//оператор присваивания копированием
	MyString& operator= (const char* string);		//оператор присваивания копированием

	MyString operator+ (const MyString& string); //const;	//сложение
	MyString operator+ (const char* string);		//сложение

	MyString& operator+= (MyString& string);		//сложение и присваивание
	MyString& operator+= (const char* string);		//сложение и присваивание

	bool	operator== (MyString& string);			//равенство строк
	bool	operator== (const char* string);		//равенство строк

	MyString	reverse();							//разворот строки
	size_t	size() const;								//размер
	bool	isEmpty ();							//проверка, пустая ли строка


	friend std::ostream& operator<< (std::ostream& stream, const MyString& string) {
		stream << string._data;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, const MyString& string) {
		stream >> string._data;
		return stream;
	}

	~MyString();									//деструктор

private:
	MyString cat(const MyString& first) const;
	MyString& mutableCat(const MyString& first);

	char* _data;
	unsigned int	_size;
};