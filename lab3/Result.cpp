#include "Result.h"

SEOResult::SEOResult()
{
	count_letters = 0;
	count_word = 0;
}

SEOResult::SEOResult(int _count_letters, int _count_word, vector<string> _keyword)
{
	count_letters = _count_letters;
	count_word = _count_word;
	keyword = _keyword;
}

int SEOResult::GetCountLetters()
{
	return count_letters;
}

int SEOResult::GetCountWord()
{
	return count_word;
}

vector<string> SEOResult::GetKeyword()
{
	return keyword;
}

OrtoResult::OrtoResult()
{
}

OrtoResult::OrtoResult(vector<string> _mistake_word)
{
	mistake_word = _mistake_word;
}

vector<string> OrtoResult::GetMistakeWord()
{
	return mistake_word;
}
