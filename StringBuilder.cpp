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
		char* conString = new char[stringSize];

		// copy str onto char*:
		memcpy(conString, input + '\0', stringSize);

		// insert input to class string
		string = conString;
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

	/*
#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x1, int y1) { x = x1; y = y1; }

	// Copy constructor
	Point(const Point &p1) {x = p1.x; y = p1.y; }

	int getX()            {  return x; }
	int getY()            {  return y; }
};

int main()
{
	Point p1(10, 15); // Normal constructor is called here
	Point p2 = p1; // Copy constructor is called here

	// Let us access values assigned by constructors
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
	cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

	return 0;
}*/