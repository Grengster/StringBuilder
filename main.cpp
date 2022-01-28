// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StringBuilderHeader.h"
#include <assert.h>

int main(){
    //Teil 1
    String myString("Hello");
    const String testString("Hello");
    
    assert(*myString.c_str() == *testString.c_str()); //check for same characters

    myString.concatenate("World");
    myString.concatenate(myString);

    String otherString(myString);
    const String test2String("HelloWorldHelloWorld");

    assert(myString.getLength() == test2String.getLength()); //check for same length

    String yetAnotherString("AnotherWorld");
    otherString = yetAnotherString; 
    std::cout << otherString.c_str() << std::endl; 

    // Teil 2
    String s1("Hello");
    s1.getLength();
    const String s2("World");
    s1 += s2;
    String s3 = s1 + s2;
    s3 += "Hello";
    const String s4 = s3 + "World";
    puts(s4);

    //Teil 3 
    const String test("Hello World"); 
    for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';

    //TESTS

    String test3String("6Chars");
    assert(test3String.getLength() == 6);

    test3String = testString;
    assert(*test3String.c_str() == *testString.c_str());

    test3String += testString;
    const String test4String("HelloHello");
    assert(*test3String.c_str() == *test4String.c_str());

    assert((std::find(test.begin(), test.end(), 'o') != test.end()) == 1);
    assert((std::find(test.begin(), test.end(), 'S') != test.end()) == 0);

    String::Iterator it = test.begin();
    assert(*it == 'H');
    ++it;
    assert(*it != 'H');
    assert(*it == 'e');
}

