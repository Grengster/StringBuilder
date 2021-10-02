// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StringBuilderHeader.h"
#include <iostream>

//String::String() = default;

String::String(const char* input)
	{
		int buffer = strlen(input) + 1;

		// allocate mem with \0:
		char* conString = new char[buffer];

		// copy str onto char*:
		strcpy(conString, input);

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
		int buffer = strlen(string) + strlen(input) + 2;

		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];
		strcpy(conString, string);
		strcat(conString, " ");
		delete string;
		string = new char[buffer];
		// copy strings one and two over to the new buffer:
		strcat(conString, input);

		string = conString;
		//array mit new cahrs, sizeofstring usw
	}