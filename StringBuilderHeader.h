#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER
#define _CRT_SECURE_NO_WARNINGS

class String {

	const char* string{};


public:

	String();

	String(const char* string);
	String(const String &obj);

	void getString();

	void concatenate(const char* string);
	void concatenate(const String& object);

	~String() { delete string; }
};

#endif