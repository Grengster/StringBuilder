#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class String {

	const char* string;
	size_t arr_size;

public:
	String();
	String(const char* string); //copy const
	String(const String& obj); //copy const
	String& operator= (const String& other) noexcept;
	String& operator= (String&& other) noexcept; //move const
	String operator+= (const String& other);
	String operator+= (const char* string);
	String operator+ (const String& other);
	String operator+ (const char* string);
	
	//class Iterator;
	size_t getLength(const char* string, bool withNull);
	const char* getString();
	void concatenate(const char* string);
	void concatenate(const String& object);
	const char* c_str();
	~String() { delete string; }	
	
	class Iterator : public std::iterator<std::input_iterator_tag, int>
	{ // nested class
		public:
			char* p;
			Iterator(char* x = nullptr) : p(x) {};
			Iterator(const Iterator& mit) : p(mit.p) {};
			Iterator& operator++();
			Iterator operator++(int);
			//Iterator operator=(const Iterator& other);
			bool operator!=(const Iterator& rhs) const;
			char& operator*();
	};
	Iterator it;

	String::Iterator begin() const;
	String::Iterator end() const;
	

	operator const char* ();

};

int puts(String obj);

#endif