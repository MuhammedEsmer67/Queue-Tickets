#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtility
{
public:

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, NumberDigit = 3, Special = 4, Mix = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static short GetRandomNumber(short From, short To)
	{
		short RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	static char GetRandomChar(enCharType CharType)
	{
		if (CharType == enCharType::Mix)
			CharType = enCharType(GetRandomNumber(1, 4));

		switch (CharType)
		{
		case enCharType::SmallLetter:
			return GetRandomNumber(97, 122);
		case enCharType::CapitalLetter:
			return GetRandomNumber(65, 90);
		case enCharType::NumberDigit:
			return GetRandomNumber(48, 57);
		case enCharType::Special:
			return GetRandomNumber(35, 47);
		default:
			return GetRandomNumber(65, 90);
		}
	}

	static string GetRandomWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (short x = 1; x <= Length; x++)
		{
			Word += GetRandomChar(CharType);
		}

		return Word;
	}

	static string GetRandomKey(enCharType CharType, short Length = 4)
	{
		string Key = "";

		for (short x = 1; x <= Length; x++)
		{
			Key += GetRandomWord(CharType, 4);
			Key += "-";
		}
		Key.pop_back();

		return Key;
	}

	static void GetRandomKeys(enCharType CharType, short KeysNumber)
	{
		for (short x = 1; x <= KeysNumber; x++)
		{
			cout << "Key [" << x << "]: " << GetRandomKey(CharType, 4) << endl;
		}
	}

	template <typename T> static void Swap(T& a, T& b)
	{
		T Temp = a;
		a = b;
		b = Temp;
	}

	static void GetRandomArray(int RandomArray[100], short ArrayLength, short From, short To)
	{
		for (short x = 1; x <= ArrayLength; x++)
			RandomArray[x - 1] = GetRandomNumber(From, To);
	}

	static void GetRandomArray(enCharType CharType, string RandomArray[100], short ArrayLength, short WordLength)
	{
		for (short x = 1; x <= ArrayLength; x++)
			RandomArray[x - 1] = GetRandomWord(CharType, WordLength);
	}

	static void GetRandomArray(enCharType CharType, string RandomArray[100], short ArrayLength)
	{
		for (short x = 1; x <= ArrayLength; x++)
			RandomArray[x - 1] = GetRandomKey(CharType);
	}

	template <typename T> static void ShuffleArray(T Array[100], short ArrayLength)
	{
		for (short x = 1; x <= ArrayLength; x++)
		{
			Swap<T>(Array[GetRandomNumber(0, ArrayLength - 1)], Array[GetRandomNumber(0, ArrayLength - 1)]);
		}
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (short i = 1; i <= Text.length(); i++)
			Text[i - 1] = char(int(Text[i - 1]) + EncryptionKey);

		return Text;
	}

	static string DecryptText(string EncryptedText, short EncryptionKey)
	{
		for (short i = 1; i <= EncryptedText.length(); i++)
			EncryptedText[i - 1] = char(int(EncryptedText[i - 1]) - EncryptionKey);

		return EncryptedText;

	}

	static string Tabs(short TabsNumber)
	{
		string T = "";

		for (short i = 1; i <= TabsNumber; i++)
			T += "\t";

		return T;
	}

	static string NumberToText(int Number)
	{
		if (Number < 20)
		{
			string Array[]{ "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
							"Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

			return Array[Number];
		}
		if (Number > 19 && Number < 100)
		{
			string Array[]{ "","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return Array[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number > 99 && Number < 200)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number > 199 && Number < 1000)
		{
			return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
		}
		if (Number > 999 && Number < 2000)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number > 1999 && Number < 1000000)
		{
			return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
		}
		if (Number > 999999 && Number < 2000000)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number > 1999999 && Number < 1000000000)
		{
			return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
		}
		if (Number > 999999999 && Number < 2000000000)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}
};
