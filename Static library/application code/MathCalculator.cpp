// MathClient.cpp
// compile with: cl /EHsc MathClient.cpp /link MathLibrary.lib
//Simple calculator app using Static Library
#include <iostream>

using namespace std;
#include "MathLibrary.h"

int main()
{
    double firstnumber, secondnumber, result;
    char operation;
    cout << "SIMPLE CALCULATOR APP" << endl;
    cout << "1.ADDITION" << endl << "2.SUBTRACTION" << endl << "3.MULTIPLICATION" << endl << "4.DIVISION" << endl;
    cout << "Enter the firstnumber:";
    cin >> firstnumber;
    cout << endl << "Enter the secondnumber:";
    cin >> secondnumber;
    cout << endl << "Enter the operator:";
    cin >> operation;
    switch (operation)
    {
    case '+':
        cout << firstnumber <<"+" << secondnumber<<"="<< MathLibrary::Calculator::Add(firstnumber,secondnumber) <<endl;
        break;
    case '-':
        cout << firstnumber << "-" << secondnumber << "=" << MathLibrary::Calculator::Sub(firstnumber, secondnumber) << endl;
        break;
    case '*':
        cout << firstnumber << "*" << secondnumber << "=" << MathLibrary::Calculator::Multiply(firstnumber, secondnumber) << endl;
        break;
    case '/':
        if(secondnumber==0)
            cout << firstnumber << "/" << secondnumber << "= Infinity";
        else
            cout << firstnumber << "/" << secondnumber << "=" << MathLibrary::Calculator::Division(firstnumber, secondnumber) << endl;
        break;
    }

    return 0;
}