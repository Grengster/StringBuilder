// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StringBuilderHeader.h"
#include <iostream>

//String::String() = default;

	String::String(const char* input)
	{
		//int buffer = sizeof(input);
		int stringSize = getLength(input, true);

		// allocate mem with \0:
		char* conString = new char[stringSize];			//Memory (in heap) char angelegt

		// copy str onto char*:
		memcpy(conString, input + '\0', stringSize);	//legt an stelle in memory

		// insert input to class string
		string = conString;								// weißt dem Klassenattribut pointer zu stelle in memory zu
	}

	String::String(const String& obj)
	{
		int stringSize = getLength(obj.string, true);

		// allocate mem with \0:
		char* conString = new char[stringSize];

		// copy str onto char*:
		memcpy(conString, obj.string + '\0', stringSize);

		// insert input to class string
		string = conString;
	}



	String& String::operator= (const String& other) noexcept
	{
		if (this == &other)
			return *this; // delete[]/size=0 would also be ok

		int stringSize = getLength(other.string, true);

		// allocate mem with \0:
		char* conString = new char[stringSize];

		// copy str onto char*:
		memcpy(conString, other.string + '\0', stringSize);

		// insert input to class string
		string = conString;
		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		string = std::move(other.string);
		return *this;
	}

	String& String::operator+= (const String& other) 
	{
		if (this == &other)
			return *this;
		this->concatenate(other);
		return *this;
	}  

	String& String::operator+= (const char* string)
	{
		this->concatenate(string);
		return *this;
	}

	String& String::operator+ (const String& other)
	{
		if (this == &other)
			return *this;
		this->concatenate(other);
		return *this;
	}

	String& String::operator+ (const char* string)
	{
		this->concatenate(string);
		return *this;
	}


	int String::getLength(const char* string, bool withNull = false)
	{
		int stringSize = 0;
		while (string[stringSize] != '\0')
			stringSize++;
		if(withNull) stringSize++;
		return stringSize;
	}

	void String::getString()
	{
		std::cout << this->string << std::endl;
	}

	void String::concatenate(const char* input) 
	{
		// calculate the required buffer size (also accounting for the null terminator):
		int stringSize = getLength(string);

		int buffer = stringSize + sizeof(input) + 2;
		
		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];

		memcpy(conString, string, stringSize);

		memcpy(conString + stringSize, input + '\0', sizeof(input) + 2);

		delete string;
		string = new char[buffer];
		
		string = conString;
	}

	void String::concatenate(const String& object)
	{
		// calculate the required buffer size (also accounting for the null terminator):
		int stringSize = getLength(string);
		int objectSize = getLength(object.string);

		int buffer = stringSize + objectSize + 1;

		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];

		memcpy(conString, string, stringSize);

		memcpy(conString + stringSize, object.string + '\0', objectSize + 1);

		delete string;
		string = new char[buffer];

		string = conString;
	}

	const char* String::c_str()
	{
		return this->string;
	}

	void String::Iterator::begin(const String& other) {
		std::cout << "Test" << std::endl;
	}

	void String::Iterator::end(const String& other) {

	}