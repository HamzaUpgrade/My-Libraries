//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "MyUtil.h"

int main()

{
    srand(time(0));
    cout << MyUtil::RandomNumber(1, 10) << endl;
    cout << MyUtil::GetRandomCharacter(MyUtil::CapitalLetter) << endl;
    cout << MyUtil::GenerateRandomWord(MyUtil::CapitalLetter, 8) << endl;
    cout << MyUtil::GenerateKey(MyUtil::CapitalLetter) << endl;
    MyUtil::GenarateKeys(10, MyUtil::CapitalLetter);

    cout << "\n";

    //Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;
    MyUtil::Swap(x, y);
    cout << x << " " << y << endl << endl;

    //Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;
    MyUtil::Swap(a, b);
    cout << a << " " << b << endl << endl;

    //Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    MyUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl << endl;

    /*//Swap Dates
    MyUtil d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    MyUtil::Swap(d1, d2);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    */
    //Shuffl Array

    //int array
    int Arr1[5] = { 1,2,3,4,5 };
    MyUtil::ShuffleArray(Arr1, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    //string array
    string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
    MyUtil::ShuffleArray(Arr2, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    int Arr3[5];
    MyUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }


    string Arr4[5];
    MyUtil::FillArrayWithRandomWords(Arr4, 5, MyUtil::MixChars, 8);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }


    string Arr5[5];
    MyUtil::FillArrayWithRandomKeys(Arr5, 5, MyUtil::MixChars);
    cout << "\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    //cout << "\nText1 " << MyUtil::Tabs(5) << "Text2\n";

    const short EncryptionKey = 2; //this is the key.

    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Mohammed Abu-Hadhoud";
    TextAfterEncryption = MyUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = MyUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    system("pause>0");

    return 0;
}