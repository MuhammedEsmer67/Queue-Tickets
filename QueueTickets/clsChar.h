#pragma once
#include <iostream>

using namespace std;

class clsChar
{
private:

	char _Char;

public:

	clsChar() { _Char = ' '; }

	clsChar(char Char) { _Char = Char; }

	static char InvertCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	void InvertCase()
	{
		_Char = InvertCase(_Char);
	}

	static bool isVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'u' || Letter == 'o');
	}

	bool isVowel()
	{
		return isVowel(_Char);
	}

};

