#pragma once

#ifndef STRING_HEADER
#define STRING_HEADER

#include <iostream>

class String {

    char* string{};
    size_t arr_size{};

public:
    String();

    explicit String(const char* string); 
    String(const String& obj); //copy constructor
    String(const String&& obj) noexcept; //move constructor
    String& operator=(const String& other) noexcept; //Copy assignment operator
    String& operator=(String&& other) noexcept;  //Move assignment operator
    String operator+=(const String& other);
    String operator+=(const char* string);
    String operator+(const String& other) const;
    String operator+(const char* string) const;

    static size_t getLength(const char* string, bool withNull);
    const char* getString() const;
    void concatenate(const char* input);
    void concatenate(const String& object);
    const char* c_str() const;
    ~String() { delete string; }

    class Iterator : public std::iterator<std::input_iterator_tag, char> // nested class
    { 
    public:
        char* p;
        explicit Iterator(pointer x = nullptr);
        Iterator(const Iterator& other);
        Iterator& operator++();
        String::Iterator operator++(int);
        bool operator!=(const Iterator& other) const;
        char operator*() const;
    };

    class rIterator : public Iterator
    {
    public:
        char* p;
        explicit rIterator(pointer x = nullptr);
        rIterator(const rIterator& other);
        rIterator& operator++();
        String::rIterator operator++(int);
        bool operator!=(const rIterator& other) const;
        char operator*() const;
    };

    String::rIterator rBegin() const;
    String::rIterator rEnd() const;
    String::Iterator begin() const;
    String::Iterator end() const;

    operator const char* () const;

};

#endif