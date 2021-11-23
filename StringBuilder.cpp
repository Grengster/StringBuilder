// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StringBuilderHeader.h"
#include <iostream>
#include <cstring>

String::String() = default;

String::String(const char* input)
{
	arr_size = getLength(input, true); //set size of string for iterator
	const auto conString = new char[arr_size]; // allocate mem with \0 in heap
	memcpy(conString, &input['\0'], arr_size); // copy str onto char*:
	string = conString; // insert input to class string
}

String::String(const String& obj)
{
	arr_size = getLength(obj.string, true);
	const auto conString = new char[arr_size];
	memcpy(conString, &obj.string['\0'], arr_size);
	string = conString;
}

String::String(const String&& obj) noexcept
{
	arr_size = getLength(obj.string, true);
	const auto conString = new char[arr_size];
	memcpy(conString, &obj.string['\0'], arr_size);
	string = conString;
}

String& String::operator=(const String& other) noexcept
{
	if (this == &other)
		return *this; // delete[][]/size=0 would also be ok

	arr_size = getLength(other.string, true);

	// allocate mem with \0:
	const auto conString = new char[arr_size];

	// copy str onto char*:
	memcpy(conString, &other.string['\0'], arr_size);

	// insert input to class string
	string = conString;
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	string = other.string;
	delete[] other.string;
	other.string = nullptr; // move const deletes value of other obj, nullptr for safety
	return *this;
}

String String::operator+=(const String& other)
{
	String newString(this->string);
	newString.concatenate(other); //returns current object with added other object, if new object is needed,
	this->~String();
	*this = newString;
	return *this;
}

String String::operator+=(const char* string)
{
	String newString(this->string);
	newString.concatenate(string);
	this->~String();
	*this = newString;
	return *this;
}

String String::operator+(const String& other) const
{
	String newString(this->string);
	newString.concatenate(other); //returns current object with added other object, if new object is needed,
	return newString; //just create new String, add this first and then other, return new object
}

String String::operator+(const char* string) const
{
	String newString(this->string);
	newString.concatenate(string); //returns current object with added other object, if new object is needed,
	return newString;
}


size_t String::getLength(const char* string, bool withNull = false)
{
	size_t stringSize = 0;
	while (string[stringSize] != '\0')
		stringSize++;
	if (withNull) stringSize++;
	return stringSize;
}

const char* String::getString() const
{
	return string;
}

void String::concatenate(const char* input)
{
	// calculate the required buffer size (also accounting for the null terminator):
	const size_t stringSize = getLength(string);

	const size_t buffer = stringSize + sizeof(input) + 2;

	// allocate enough memory for the concatenated string:
	const auto conString = new char[buffer];

	memcpy(conString, string, stringSize);

	memcpy(conString + stringSize, &input['\0'], sizeof(input) + 2);

	delete[] string;
	string = new char[buffer];

	string = conString;
	arr_size = buffer;
}

void String::concatenate(const String& object)
{
	// calculate the required buffer size (also accounting for the null terminator):
	const size_t stringSize = getLength(string);
	const size_t objectSize = getLength(object.string);

	const size_t buffer = stringSize + objectSize + 1;

	// allocate enough memory for the concatenated string:
	const auto conString = new char[buffer];

	memcpy(conString, string, stringSize);

	memcpy(conString + stringSize, &object.string['\0'], objectSize + 1);

	delete[] string;
	string = new char[buffer];

	string = conString;
	arr_size = buffer; //set size of string for iterator
}

const char* String::c_str() const
{
	return this->string;
}


String::rIterator String::rBegin() const
{
	return rIterator(&string[arr_size] - 2); //begins with last char
}

String::rIterator String::rEnd() const
{
	return rIterator(&string[-1]);
}

String::Iterator String::begin() const
{
	//begins with 1st char
	return Iterator(&string[0]);
}

String::Iterator String::end() const
{
	return Iterator(&string[arr_size] - 1);
}

bool String::Iterator::operator!=(const Iterator& other) const
{
	return p != other.p; //returns true if p != other.p
};

String::Iterator& String::Iterator::operator++()
{
	++p; //increase pointer
	return *this;
}

String::Iterator String::Iterator::operator++(int)
{
	p += sizeof(char); //increase by 4 bytes
	return *this;
}

char String::Iterator::operator*() const
{
	return *p;
}

String::Iterator::Iterator(char* string) : p(string)
{
}

String::Iterator::Iterator(const Iterator& other) : p(other.p)
{
};

String::operator const char*() const
{
	return string;
}


String::rIterator::rIterator(char* string) : p(string)
{
}

String::rIterator::rIterator(const rIterator& other) : p(other.p)
{
};

String::rIterator& String::rIterator::operator++()
{
	p -= sizeof(char);
	return *this;
}

String::rIterator String::rIterator::operator++(int)
{
	p -= sizeof(char);
	return *this;
}

bool String::rIterator::operator!=(const rIterator& other) const
{
	return p != other.p;
};


char String::rIterator::operator*() const
{
	return *p;
}
