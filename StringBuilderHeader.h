

#ifndef STRINGLIBRARY_STRING_H
#define STRINGLIBRARY_STRING_H

class StringBuilder {

	const char* string{};


public:

	StringBuilder();

	explicit StringBuilder(const char* string);

	void concatenate(const char* string);

	~StringBuilder() { delete string; }
};

#endif