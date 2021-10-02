#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER
#define _CRT_SECURE_NO_WARNINGS

class String {

	const char* string{};


public:

	String();

	explicit String(const char* string);

	void getString();

	void concatenate(const char* string);

	~String() { delete string; }
};

#endif