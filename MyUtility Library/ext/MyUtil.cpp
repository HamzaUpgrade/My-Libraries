/*
	Author	=> Hamza Abdulrahman
	Date	=> 2024-2-17
	I collected the most important functions that do not have a category
*/

#include "MyUtil.h"
using namespace std;

//Random Functions:
void MyUtil::Srand()
{
	srand(time(0));
}
int MyUtil::RandomNumber(int From, int To)
{
	//Function to gnerate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
char MyUtil::GetRandomCharacter(MyUtil::enCharType Type)
{
	switch (Type)
	{
	case MyUtil::enCharType::SmallLetter:
		return char(MyUtil::RandomNumber(97, 122));
		break;
	case MyUtil::enCharType::CapitalLetter:
		return char(MyUtil::RandomNumber(65, 90));
		break;
	case MyUtil::enCharType::SpecialCharcter:
		return char(MyUtil::RandomNumber(33, 47));
		break;
	case MyUtil::enCharType::Digit:
		return char(MyUtil::RandomNumber(48, 57));
		break;
	default:
		return char(MyUtil::RandomNumber(65, 90));
		break;
	}

}

string MyUtil::GenerateRandomWord(MyUtil::enCharType Type, int Length)
{
	string word = "";
	for (int i = 1; i <= Length; i++)
	{
		word += MyUtil::GetRandomCharacter(Type);
	}
	return word;
}

string MyUtil::GenerateKey(MyUtil::enCharType Type)
{
	string key = "";
	key = GenerateRandomWord(Type, 4) + "-";
	key += GenerateRandomWord(Type, 4) + "-";
	key += GenerateRandomWord(Type, 4) + "-";
	key += GenerateRandomWord(Type, 4);
	return key;
}

void MyUtil::GenarateKeys(short manykeys, MyUtil::enCharType Type)
{
	for (int i = 1; i <= manykeys; i++)
	{
		cout << "\nKey[" << i << "]: " << MyUtil::GenerateKey(Type);
	}
}

//swap functions :

void MyUtil::Swap(int &Number1, int &Number2)
{
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
}

void MyUtil::Swap(double& Number1, double& Number2)
{
	double temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
}

void MyUtil::Swap(string& str1, string& str2)
{
	string temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}
// i want to add swap dates soon...

// complete Random Functions:

void MyUtil::FillArrayWithRandomNumbers(int arr[], int size, int start, int end)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = MyUtil::RandomNumber(start, end);
	}
}


void MyUtil::FillArrayWithRandomWords(string arr[], int size, MyUtil::enCharType Type, int Length)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = MyUtil::GenerateRandomWord(Type, Length);
	}
}
void MyUtil::FillArrayWithRandomKeys(string arr[], short size, MyUtil::enCharType Type)
{
	for (short i = 0; i < size; i++)
	{
		arr[i] = MyUtil::GenerateKey(Type);
	}
}
//Shuffl Array:

void MyUtil::ShuffleArray(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		Swap(arr[MyUtil::RandomNumber(1, size) - 1], arr[MyUtil::RandomNumber(1, size) - 1]);
	}

}

void MyUtil::ShuffleArray(string arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Swap(arr[RandomNumber(1, size) - 1], arr[RandomNumber(1, size) - 1]);
	}
}

//Encryption and Decryption Functions:

string MyUtil::EncryptText(string postion, short key)
{

	int enc = 0;
	string allenc = "";
	for (int i = 0; i < postion.length(); i++)
	{
		enc = char(int(postion[i]) + key);
		allenc += enc;
	}

	return allenc;
}
string MyUtil::DecryptText(string encText, short key)
{
	int dec = 0;
	string alldec = "";
	for (int i = 0; i < encText.length(); i++)
	{
		dec = char(int(encText[i]) - key);
		alldec += dec;
	}

	return alldec;
}

void MyUtil::Tabs(int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << "\t";
	}
	return;
}

void MyUtil::endlines(int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << "\n";
	}
}

