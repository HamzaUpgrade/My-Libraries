#include <iostream>
#include "MyInputValidation.h"
using namespace std;

int main()

{
    cout << MyInputValidation::IsNumberBetween(5, 1, 10) << endl;
    cout << MyInputValidation::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << MyInputValidation::IsDateBetween(MyDate(),
        MyDate(8, 12, 2022),
        MyDate(31, 12, 2022)) << endl;

    cout << MyInputValidation::IsDateBetween(MyDate(),
        MyDate(31, 12, 2022),
        MyDate(8, 12, 2022)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int x = MyInputValidation::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x=" << x;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int y = MyInputValidation::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "y=" << y;

    cout << "\nPlease Enter a Double Number:\n";
    double a = MyInputValidation::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "a=" << a;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b = MyInputValidation::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << b;

    cout << endl << MyInputValidation::IsValidDate(MyDate(35, 12, 2022)) << endl;

    system("pause>0");

    return 0;
}