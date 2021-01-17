#pragma once
#include <vector>
#include <map>
#include <string>

using namespace std;

class SEOResult
{
public:
	//Информационный эксперт.
	SEOResult();
	SEOResult(int _count_letters, int _count_word, map<string, int> _keyword);
	int GetCountLetters();
	int GetCountWord();
	map<string, int> GetKeyword();
	map<string, double> GetPercentText();
private:
	int count_letters;
	int count_word;
	map<string, int> keyword;
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

