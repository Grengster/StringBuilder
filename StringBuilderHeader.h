#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER
#define _CRT_SECURE_NO_WARNINGS

class String {

	const char* string{};

public:
	//String() = default;
	String(const char* string); //copy const
	String(const String& obj); //copy const
	String& operator= (const String& other) noexcept;
	String& operator= (String&& other) noexcept; //move const
	String& operator+= (const String& other);
	String& operator+= (const char* string);
	String& operator+ (const String& other);
	String& operator+ (const char* string);
	

	size_t getLength(const char* string, bool withNull);
	void getString();
	void concatenate(const char* string);
	void concatenate(const String& object);
	const char* c_str();
	const char* puts();
	void begin();
	bool end();
	~String() { delete string; }
	
	class Iterator
	{ // nested class
		public:
			const void* p;
			int curChar = 0;
	};
	Iterator it;
	operator const char* ();

};

#endif