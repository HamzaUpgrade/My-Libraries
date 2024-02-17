/*
    Author	=> Hamza Abdulrahman
    Date	=> 2024-2-17
*/
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MyString
{
private:
    string _Element;
public:
    MyString()
    {
        _Element = "";
    }
    MyString(string Element)
    {
        Element = _Element;
    }
    void setString(string Element)
    {
        _Element = Element;
    }
    string getString()
    {
        return _Element;
    }
    __declspec(property(get = getString, put = setString)) string Element;

    static short CountWord(string S1)
    {
        short Counter = 0;
        string delim = " ";
        cout << "\nThe Number of word in your string is: ";
        short pos = 0;
        string sWord;
        //use find() function to get the postion of delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //store the word
            if (sWord != "")
            {
                Counter++;
            }
            S1.erase(0, pos + delim.length()); // erase() until postion and move to next word   
        }
        if (S1 != "")
        {
            Counter++; //it count last word of the string
        }
        return Counter;
    }
    short CountWord()
    {
        return CountWord(_Element);
    }

    static vector<string> Split(string S1, string delim)
    {
        short pos = 0;
        string sWord;
        vector<string> vWord;
        //use find() function to get the postion of delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            vWord.push_back(sWord);//store the word

            S1.erase(0, pos + delim.length()); // erase() until postion and move to next word   
        }
        if (S1 != "")
        {
            vWord.push_back(S1);
        }
        return vWord;
    }
    vector<string> Split(string delim)
    {
        return Split(_Element, delim);
    }

    static string Join(vector<string> vString, string delim)
    {
        string S1;
        for (string& s : vString)
        {
            S1 = S1 + s + delim;
        }
        return S1.substr(0, S1.length() - delim.length());//i dont need last seprater
    }
    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }
    static string Replace(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (toLowerAllString(s) == toLowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return Join(vString, " ");
    }
    string Replace(string StringToReplace, string sRepalceTo)
    {
        return Replace(_Element, StringToReplace, sRepalceTo);
    }

    //Convert Part ...
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }
    void UpperFirstLetterOfEachWord()
    {
        _Element = UpperFirstLetterOfEachWord(_Element);
    }

    static string toLowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }
    void toLowerFirstLetterOfEachWord()
    {
        _Element = toLowerFirstLetterOfEachWord(_Element);
    }

    static string toUpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }
    void toUpperAllString()
    {
        _Element = toUpperAllString(_Element);
    }

    static string toLowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }
    void toLowerAllString()
    {
        _Element = toLowerAllString(_Element);
    }

    static char  toInvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }
    static string toInvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toInvertLetterCase(S1[i]);
        }
        return S1;
    }
    void  toInvertAllLettersCase()
    {
        //obj.NameFunction
        // current change on the value 
        _Element = toInvertAllLettersCase(_Element);
    }

    //Count Part ...
    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        //in this function you can count letters via spsefic case in parameters
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }
    static short  CountCapitalLetters(string S1)
    {
        // in this function you can count  just capital case letters
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }
    short  CountCapitalLetters()
    {
        //obj.NameFunction
        return CountCapitalLetters(_Element);
    }
    static short  CountSmallLetters(string S1)
    {
        // in this function you can count  just small case letters
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }
    short CountSmallLetters()
    {
        //obj.NameFunction
        return CountSmallLetters(_Element);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        //in this function you can count spsefic letter via spsefic if you need match cases or not
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }
    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        //obj.NameFunction
        return CountSpecificLetter(_Element, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }
    static short  CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }
    short  CountVowels()
    {
        return CountVowels(_Element);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }
    void RemovePunctuations()
    {
        _Element = RemovePunctuations(_Element);
    }

    //Trim part ...
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }
    void TrimLeft()
    {
        _Element = TrimLeft(_Element);
    }
    static string TrimRight(string S1)
    {


        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }
    void TrimRight()
    {
        _Element = TrimRight(_Element);
    }
    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));

    }
    void Trim()
    {
        _Element = Trim(_Element);
    }

    static string ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }
    void ReverseWordsInString()
    {
        _Element = ReverseWordsInString(_Element);
    }

};

