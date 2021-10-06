// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Calculator app using Dynamic library

#include <iostream>
#include "Calculation.h"

using namespace std;

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
        cout << firstnumber << "+" << secondnumber << "=" << Add(firstnumber, secondnumber) << endl;
        break;
    case '-':
        cout << firstnumber << "-" << secondnumber << "=" << Sub(firstnumber, secondnumber) << endl;
        break;
    case '*':
        cout << firstnumber << "*" << secondnumber << "=" << Multiply(firstnumber, secondnumber) << endl;
        break;
    case '/':
        if (secondnumber == 0)
            cout << firstnumber << "/" << secondnumber << "= Infinity";
        else
            cout << firstnumber << "/" << secondnumber << "=" << Division(firstnumber, secondnumber) << endl;
        break;
    }

}

