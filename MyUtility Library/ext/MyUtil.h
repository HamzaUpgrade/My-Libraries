#pragma once
using namespace std;
#include <iostream>
#include <cstdlib>
class MyUtil
{
public:
	static void Srand();
	static int RandomNumber(int From, int To);
	
	static void FillArrayWithRandomNumbers(int arr[], int size, int start, int end);
	
	enum enCharType { SmallLetter, CapitalLetter, SpecialCharcter, Digit ,MixChars};
	
	static void FillArrayWithRandomWords(string arr[], int size, enCharType Type, int Length);
	
	static char GetRandomCharacter(enCharType Type);
	
	static string GenerateRandomWord(enCharType Type, int Length);
	
	static string GenerateKey(enCharType Type);
	
	static void GenarateKeys(short manykeys, MyUtil::enCharType Type);
	
	static void FillArrayWithRandomKeys(string arr[], short size, MyUtil::enCharType Type);
	static void Swap(int& Number1, int& Number2);
	
	static void Swap(double& Number1, double& Number2);
	
	static void Swap(string& str1, string& str2);
	
	static void ShuffleArray(int arr[], int size);
	
	static void ShuffleArray(string arr[], int size);
	
	static string EncryptText(string postion, short key);
	
	static string DecryptText(string encText, short key);
	
	static void Tabs(int Length);
	
	static void endlines(int Length);
};

