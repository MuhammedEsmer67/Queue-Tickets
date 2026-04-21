#pragma once
#include <vector>
#include "clsChar.h"

class clsString
{
private:

	string _String;
	vector <string> _vSplited;
	enum enLetterCountType { Upper = 1, Lower = 2, All = 3 };

public:

	clsString()
	{
		_String = "";
	}

	clsString(string String)
	{
		_String = String;
		_vSplited = Split(_String, " ");
	}

	void setString(string String) { _String = String; }

	string getString() { return _String; }

	void setStringVector(vector <string> vString) { _vSplited = vString; }

	vector <string> getStringVector() { return _vSplited; }

	static short CountLetters(string Text, enLetterCountType WhatToCount = enLetterCountType::All)
	{
		if (WhatToCount == enLetterCountType::All)
			return Text.length();

		short Counter = 0;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (WhatToCount == enLetterCountType::Upper && isupper(Text[i - 1]))
				Counter++;
			else if (WhatToCount == enLetterCountType::Lower && islower(Text[i - 1]))
				Counter++;
		}

		return Counter;
	}

	short CountLetters(enLetterCountType WhatToCount = enLetterCountType::All)
	{
		return CountLetters(_String, WhatToCount);
	}

	static string RemovePunctuation(string Text)
	{
		string PunctuationReomvedText = "";

		for (short i = 1; i <= Text.length(); i++)
		{
			if (!ispunct(Text[i - 1]))
				PunctuationReomvedText += Text[i - 1];
		}

		return PunctuationReomvedText;
	}

	void RemovePunctuation()
	{
		_String = RemovePunctuation(_String);
		_vSplited = Split(_String, " ");
	}

	static string TrimLeft(string Text)
	{
		for (short i = 1; i <= Text.length(); i++)
		{
			if (Text[i - 1] != ' ')
				return Text.substr(i - 1, Text.length() - i + 1);
		}

		return "";
	}

	void TrimLeft()
	{
		_String = TrimLeft(_String);
	}

	static string TrimRight(string Text)
	{
		for (short i = Text.length(); i >= 1; i--)
		{
			if (Text[i - 1] != ' ')
				return Text.substr(0, i);
		}

		return "";
	}

	void TrimRight()
	{
		_String = TrimRight(_String);
	}

	static string Trim(string Text)
	{
		return TrimLeft(TrimRight(Text));
	}

	void Trim()
	{
		_String = Trim(_String);
	}

	static string Join(vector <string>& vTextWords, string Delim = " ")
	{
		string Text = "";

		for (string& i : vTextWords)
			Text = Text + i + Delim;

		return Text.substr(0, Text.length() - Delim.length());
	}

	static string Join(string arrTextWords[], short Length, string Delim = " ")
	{
		string Text = "";

		for (short i = 1; i <= Length; i++)
			Text = Text + arrTextWords[i - 1] + Delim;

		return Text.substr(0, Text.length() - Delim.length());
	}

	static vector <string> Split(string Text, string Delim)
	{
		vector <string> vSplitedWords;
		short Pos = 0;
		string Word = "";

		while ((Pos = Text.find(Delim)) != std::string::npos)
		{
			Word = Text.substr(0, Pos);

			if (Word != "")
				vSplitedWords.push_back(Word);

			Text.erase(0, Pos + Delim.length());
		}

		if (Text != "")
			vSplitedWords.push_back(Text);

		return vSplitedWords;
	}

	void Split(string Delim)
	{
		_vSplited = Split(_String, Delim);
	}

	static string ReplaceWord(string Text, string WordToReplace, string ReplaceTo)
	{
		short Pos = Text.find(WordToReplace);

		while (Pos != std::string::npos)
		{
			Text = Text.replace(Pos, WordToReplace.length(), ReplaceTo);
			Pos = Text.find(WordToReplace);
		}

		return Text;
	}

	void ReplaceWord(string WordToReplace, string ReplaceTo)
	{
		_String = ReplaceWord(_String, WordToReplace, ReplaceTo);
		_vSplited = Split(_String, " ");
	}

	static string ReverseWords(string Text, string Delim = " ")
	{
		vector <string> vTextWords;
		string ReversedText = "";
		vTextWords = Split(Text, Delim);

		vector <string>::iterator iteration = vTextWords.end();

		while (iteration != vTextWords.begin())
		{
			iteration--;

			ReversedText += *iteration + Delim;
		}

		return ReversedText.substr(0, ReversedText.length() - Delim.length());
	}

	void ReverseWords(string Delim)
	{
		_String = ReverseWords(_String, Delim);
		_vSplited = Split(_String, " ");
	}

	static short CountTotalWords(string Text)
	{
		short WordCounter = 0;
		short Pos = 0;
		string Space = " ";
		string Word = "";

		while ((Pos = Text.find(Space)) != std::string::npos)
		{
			Word = Text.substr(0, Pos);

			if (Word != "")
				WordCounter++;

			Text.erase(0, Pos + Space.length());
		}

		if (Text != "")
			WordCounter++;

		return WordCounter;
	}

	short CountTotalWords()
	{
		return CountTotalWords(_String);
	}

	static void PrintWords(string Text)
	{
		short Pos = 0;
		string Space = " ";
		string Word = "";

		while ((Pos = Text.find(Space)) != std::string::npos)
		{
			Word = Text.substr(0, Pos);

			if (Word != "")
				cout << Word << endl;

			Text.erase(0, Pos + Space.length());
		}

		if (Text != "")
			cout << Text << endl;
	}

	void PrintWords()
	{
		PrintWords(_String);
	}

	static short CountVowelLetters(string Text)
	{
		short Counter = 0;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (clsChar::isVowel(Text[i - 1]))
				Counter++;
		}

		return Counter;
	}

	short CountVowelLetters()
	{
		return CountVowelLetters(_String);
	}

	static short CountTargetCharacter(string Text, char TargetChar, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (MatchCase)
			{
				if (Text[i - 1] == TargetChar)
					Counter++;
			}
			else
			{
				if (tolower(Text[i - 1]) == tolower(TargetChar))
					Counter++;
			}
		}

		return Counter;
	}

	short CountTargetCharacter(char TargetChar, bool MatchCase = true)
	{
		return CountTargetCharacter(_String, TargetChar, MatchCase);
	}

	static short CountUpperCharacters(string Text)
	{
		short Counter = 0;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (isupper(Text[i - 1]))
				Counter++;
		}

		return Counter;
	}

	short CountUpperCharacters()
	{
		return CountUpperCharacters(_String);
	}

	static string LowerFirstLetterOfWords(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (Text[i - 1] != ' ' && Text[i - 1] != '\t' && Text[i - 1] != '\n' && isFirstLetter)
				Text[i - 1] = tolower(Text[i - 1]);

			isFirstLetter = (Text[i - 1] == ' ' || Text[i - 1] == '\t' || Text[i - 1] == '\n' ? true : false);
		}

		return Text;
	}

	void LowerFirstLetterOfWords()
	{
		_String = LowerFirstLetterOfWords(_String);
		_vSplited = Split(_String, " ");
	}

	static string UpperFirstLetterOfWords(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (Text[i - 1] != ' ' && Text[i - 1] != '\t' && Text[i - 1] != '\n' && isFirstLetter)
				Text[i - 1] = toupper(Text[i - 1]);

			isFirstLetter = (Text[i - 1] == ' ' || Text[i - 1] == '\t' || Text[i - 1] == '\n' ? true : false);
		}

		return Text;
	}

	void UpperFirstLetterOfWords()
	{
		_String = UpperFirstLetterOfWords(_String);
		_vSplited = Split(_String, " ");
	}

	static void PrintFirstLetterOfWords(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 1; i <= Text.length(); i++)
		{
			if (Text[i - 1] != ' ' && Text[i - 1] != '\t' && Text[i - 1] != '\n' && isFirstLetter)
				cout << Text[i - 1] << endl;

			isFirstLetter = (Text[i - 1] == ' ' || Text[i - 1] == '\t' || Text[i - 1] == '\n' ? true : false);
		}
	}

	void PrintFirstLetterOfWords()
	{
		PrintFirstLetterOfWords(_String);
	}

	static string ToUpperCase(string Text)
	{
		for (short i = 1; i <= Text.length(); i++)
			Text[i - 1] = toupper(Text[i - 1]);

		return Text;
	}

	void ToUpperCase()
	{
		_String = ToUpperCase(_String);
		_vSplited = Split(_String, " ");
	}

	static string ToLowerCase(string Text)
	{
		for (short i = 1; i <= Text.length(); i++)
			Text[i - 1] = tolower(Text[i - 1]);

		return Text;
	}

	void ToLowerCase()
	{
		_String = ToLowerCase(_String);
		_vSplited = Split(_String, " ");
	}

	static string Replace(string Text, string Delim, string WordToReplace, string ReplaceTo, bool MatchCase = true)
	{
		vector <string> vTextWords = Split(Text, " ");

		for (string& i : vTextWords)
		{
			if (MatchCase)
			{
				if (i == WordToReplace)
					i = ReplaceTo;
			}
			else
			{
				if (ToLowerCase(i) == ToLowerCase(WordToReplace))
					i = ReplaceTo;
			}
		}

		return Join(vTextWords, " ");
	}

	void Replace(string Delim, string WordToReplace, string ReplaceTo, bool MatchCase = true)
	{
		_String = Replace(_String, Delim, WordToReplace, ReplaceTo, MatchCase);
		_vSplited = Split(_String, " ");
	}

};

