// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StringBuilderHeader.h"
#include <iostream>

//String::String() = default;

	String::String(const char* input)
	{
		int buffer = sizeof(input)+2;

		// allocate mem with \0:
		char* conString = new char[buffer];

		// copy str onto char*:
		memcpy(conString, input + '\0', buffer);

		// insert input to class string
		string = conString;

	}


	void String::getString()
	{
		std::cout << this->string << std::endl;
	}

	void String::concatenate(const char* input)
	{
		// calculate the required buffer size (also accounting for the null terminator):
		int stringSize = 0;
		while (string[stringSize] != '\0')
			stringSize++;

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
		int stringSize = 0;
		while (string[stringSize] != '\0')
			stringSize++;
		int objectSize = 0;
		while (object.string[objectSize] != '\0')
			objectSize++;

		int buffer = stringSize + objectSize + 1;

		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];

		memcpy(conString, string, stringSize);

		memcpy(conString + stringSize, object.string + '\0', objectSize + 1);

		delete string;
		string = new char[buffer];

		string = conString;
	}