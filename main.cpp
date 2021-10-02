// StringBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringBuilderHeader.h"

int main()
{
    //Teil 1
    String myString("Hello");
    myString.getString();
    myString.concatenate("World");
    myString.getString();
    /*myString.concatenate(myString);
    String otherString(myString);
    String yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    std::cout << otherString.c_str();

    // Teil 2
    String s1("Hello");
    const String s2("World");
    s1 += s2;
    String s3 = s1 + s2;
    s3 += "Hello";
    const String s4 = s3 + "World";
    puts(s4);

    //Teil 3
    const String test("Hello World");
    for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
