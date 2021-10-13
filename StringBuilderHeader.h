#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER
#define _CRT_SECURE_NO_WARNINGS

class String {

	const char* string{};

public:
	String(const char* string);
	String(const String& obj);
	String& operator= (const String& other) noexcept;
	String& operator=(String&& other) noexcept;
	String& operator+= (const String& other);
	String& operator+= (const char* string);
	String& operator+ (const String& other);
	String& operator+ (const char* string);

	int getLength(const char* string, bool withNull);
	void getString();
	void concatenate(const char* string);
	void concatenate(const String& object);
	const char* c_str();
	void begin();
	bool end();
	~String() { delete string; }
	
	class Iterator
	{ // nested class
		public:
			int* p;
			int curChar = 0;
	};
	Iterator it;
};

#endif