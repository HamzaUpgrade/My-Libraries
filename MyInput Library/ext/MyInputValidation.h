#pragma once
#pragma warning(default : 4996)
#include<iostream>
#include"MyDate.h"
#include "MyString.h"
class MyInputValidation
{

public:
	static bool IsNumber1BeforNumber2(int Number1, int Number2);

	static bool IsNumber1BeforNumber2(double Number1, double Number2);

	static bool IsNumberBetween(int Number, int FirstNumber, int LastNumber);
	
	static bool IsNumberBetween(double Number, double FirstNumber, double LastNumber);

	static bool IsDateBetween(MyDate Date, MyDate FirstDate, MyDate LastDate); 

	static int ReadIntNumber(string ErrMassage);

	static int ReadIntNumberBetween(int FirstNumber, int LastNumber, string ErrMass);

	static double ReadDblNumber(string ErrMassage);

	static double ReadDblNumberBetween(double FirstNumber, double LastNumber, string ErrMass);

	static bool IsValidDate(MyDate Date);

};

