// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StringBuilderHeader.h"
#include <iostream>

	String::String() = default;

	String::String(const char* input)
	{
		//size_t buffer = sizeof(input);
		arr_size = getLength(input, true);

		// allocate mem with \0:
		char* conString = new char[arr_size];			//Memory (in heap) char angelegt

		// copy str onto char*:
		memcpy(conString, input + '\0', arr_size);	//legt an stelle in memory

		// insert input to class string
		string = conString;								// weißt dem Klassenattribut posize_ter zu stelle in memory zu
	}

	String::String(const String& obj)
	{
		arr_size = getLength(obj.string, true);

		// allocate mem with \0:
		char* conString = new char[arr_size];

		// copy str onto char*:
		memcpy(conString, obj.string + '\0', arr_size);

		// insert input to class string
		string = conString;
	}



	String& String::operator= (const String& other) noexcept
	{
		if (this == &other)
			return *this; // delete[][]/size=0 would also be ok

		arr_size = getLength(other.string, true);

		// allocate mem with \0:
		char* conString = new char[arr_size];

		// copy str onto char*:
		memcpy(conString, other.string + '\0', arr_size);

		// insert input to class string
		string = conString;
		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		string = std::move(other.string);
		delete[] other.string;
		other.string = nullptr; // move const deletes value of other obj, nullptr for safety
		return *this;
	}

	String String::operator+= (const String& other) 
	{
		String newString(this->string);
		newString.concatenate(other);	//returns current object with added other object, if new object is needed,
		this->~String();
		*this = newString;
		return *this;
	}  

	String String::operator+= (const char* string)
	{
		String newString(this->string);
		newString.concatenate(string);
		this->~String();
		*this = newString;
		return *this;
	}

	String String::operator+ (const String& other)
	{
		String newString(this->string);
		newString.concatenate(other);	//returns current object with added other object, if new object is needed,
		return newString;				//just create new String, add this first and then other, return new object
	}

	String String::operator+ (const char* string)
	{
		String newString(this->string);
		newString.concatenate(string);	//returns current object with added other object, if new object is needed,
		return newString;
	}


	size_t String::getLength(const char* string, bool withNull = false)
	{
		size_t stringSize = 0;
		while (string[stringSize] != '\0')
			stringSize++;
		if(withNull) stringSize++;
		return stringSize;
	}

	const char* String::getString()
	{
		return string;
	}

	void String::concatenate(const char* input) 
	{
		// calculate the required buffer size (also accounting for the null terminator):
		size_t stringSize = getLength(string);

		size_t buffer = stringSize + sizeof(input) + 2;
		
		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];

		memcpy(conString, string, stringSize);

		memcpy(conString + stringSize, input + '\0', sizeof(input) + 2);

		delete[] string;
		string = new char[buffer];
		
		string = conString;
		arr_size = buffer;
	}

	void String::concatenate(const String& object)
	{
		// calculate the required buffer size (also accounting for the null terminator):
		size_t stringSize = getLength(string);
		size_t objectSize = getLength(object.string);

		size_t buffer = stringSize + objectSize + 1;

		// allocate enough memory for the concatenated string:
		char* conString = new char[buffer];

		memcpy(conString, string, stringSize);

		memcpy(conString + stringSize, object.string + '\0', objectSize + 1);

		delete[] string;
		string = new char[buffer];

		string = conString;
		arr_size = buffer;
	}

	const char* String::c_str() {
		return this->string;
	}


	String::Iterator String::begin() const {
		return Iterator(&string[0]);
	}

	String::Iterator String::end() const {
		return Iterator(&string[arr_size] - 1);
		/*size_t stringSize = 0;
		while (string[stringSize] != '\0')
			stringSize++;
		*this->it.p = &string[stringSize];
		std::cout << it.p << std::endl;
		return it;*/
	}

	bool String::Iterator::operator!= (const String::Iterator& other) const{
		return p != other.p;
	};

	String::Iterator& String::Iterator::operator++() {
		++p;return *this; 
	}

	String::Iterator String::Iterator::operator++(int) {
		Iterator temp(*this); operator++(); return temp; 
	}

	/*String::Iterator String::Iterator::operator=(const Iterator& other) {
		this->p = other.p;
		return *this;
	}*/



	char& String::Iterator::operator*() {
		return *p;
	};

	
	String::operator const char* () {
		return this->string;
	}

	int puts(String obj)
	{
		std::cout << obj.getString() << std::endl;
		return 1;
	}
