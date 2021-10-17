// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringBuilderHeader.h"

int main()
{
    //Teil 1
    String myString("Hello");
    myString.concatenate("World");
    myString.concatenate(myString);
    String otherString(myString);
    String yetAnotherString("AnotherWorld");
    otherString = yetAnotherString; // overload = operator to overwrite left class with right class || placement new???
    std::cout << otherString.c_str(); // classObj->~String(); 
                                        // classObj = new (classObj) String("test");

    // Teil 2
    String s1("Hello");
    const String s2("World");
    s1 += s2;
    s1.getString();
    String s3 = s1 + s2;
    s3 += "Hello";
    const String s4 = s3 + "World";
    s3.getString();
    //puts(s4); why not work??
   
    //Teil 3
    const String test("Hello World"); // how to convert test.begin to it
    for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
}


