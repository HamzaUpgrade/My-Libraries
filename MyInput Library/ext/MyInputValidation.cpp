/*
	Author	=> Hamza Abdulrahman
	Date	=> 2024-2-17
*/

#include "MyInputValidation.h"
using namespace std;

bool MyInputValidation::IsNumber1BeforNumber2(int Number1, int Number2)
{
	if (Number1 < Number2)
		return true;
	return false;
}
bool MyInputValidation::IsNumber1BeforNumber2(double Number1, double Number2)
{
	if (Number1 < Number2)
		return true;
	return false;
}
bool MyInputValidation::IsNumberBetween(int Number, int FirstNumber, int LastNumber)
{
	if (IsNumber1BeforNumber2(LastNumber, FirstNumber))
	{
		double temp;
		temp = LastNumber;
		LastNumber = FirstNumber;
		FirstNumber = temp;
	}
	return (Number < FirstNumber || Number > LastNumber) ? false : true;
}
bool MyInputValidation::IsNumberBetween(double Number, double FirstNumber, double LastNumber)
{
	if (IsNumber1BeforNumber2(LastNumber, FirstNumber))
	{
		int temp;
		temp = LastNumber;
		LastNumber = FirstNumber;
		FirstNumber = temp;
	}
	return (Number < FirstNumber || Number > LastNumber) ? false : true;
}
bool MyInputValidation::IsDateBetween(MyDate Date, MyDate FirstDate, MyDate LastDate)
{
	if (MyDate::IsDate1BeforeDate2(LastDate, FirstDate))
	{
		MyDate::SwapDates(LastDate, FirstDate);
	}
	return MyDate::IsDate1BeforeDate2(Date, FirstDate) || MyDate::IsDate1AfterDate2(Date, LastDate) ? false : true;
}

int MyInputValidation::ReadIntNumber(string ErrMassage)
{
	int Number;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << ErrMassage;
		cin >> Number;
	}
	return Number;
}
int MyInputValidation::ReadIntNumberBetween(int FirstNumber, int LastNumber, string ErrMass)
{
	int Number;
	Number = MyInputValidation::ReadIntNumber(ErrMass);
	while (!MyInputValidation::IsNumberBetween(Number, FirstNumber, LastNumber))
	{
		cout << ErrMass;
		cin >> Number;
	}
	return Number;
}

double MyInputValidation::ReadDblNumber(string ErrMassage)
{
	double Number;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << ErrMassage;
		cin >> Number;
	}
	return Number;
}
double MyInputValidation::ReadDblNumberBetween(double FirstNumber, double LastNumber, string ErrMass)
{
	double Number;
	Number = MyInputValidation::ReadDblNumber(ErrMass);
	while (!MyInputValidation::IsNumberBetween(Number, FirstNumber, LastNumber))
	{
		cout << ErrMass;
		cin >> Number;
	}
	return Number;
}
bool MyInputValidation::IsValidDate(MyDate Date)
{
	return MyDate::IsValidDate(Date);
}
