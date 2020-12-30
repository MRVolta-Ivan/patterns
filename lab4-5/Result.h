#pragma once
#include <vector>
#include <string>

using namespace std;

class SEOResult
{
public:
	SEOResult();
	SEOResult(int _count_letters, int _count_word, vector<string> _keyword);
	int GetCountLetters();
	int GetCountWord();
	vector<string> GetKeyword();
private:
	int count_letters;
	int count_word;
	vector<string> keyword;
};

class OrtoResult
{
public:
	OrtoResult();
	OrtoResult(vector<string> _mistake_word);
	vector<string> GetMistakeWord();
private:
	vector<string> mistake_word;
};

class CountSymbolResult
{
public:
	CountSymbolResult();
	CountSymbolResult(int word, int symbol);
	int GetCountLetter();
	int GetCountSymbol();
private:
	int count_letter;
	int count_symbol;
};

