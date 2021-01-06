#include "Algorithms.h"

SEOResult SEOAlgorithm::DoAlgorithm(IText *text)
{
	//Вместо реального Сео анализа выполняется следующее:
	//Выводится длина текста.
	//Выводится количество слов.
	//Выводятся слова и сколько раз они встречаются.
	//Выводятся все слова.
	string original_text = text->GetOriginalText();
	int count_letters = text->GetOriginalText().length();;

	string delimiter = " ";
	vector<string> token;
	int start = 0;
	int end = original_text.find(delimiter);
	while (end != string::npos)
	{
		string substr = original_text.substr(start, end - start);
		for (int i = 0; i < substr.size(); i++)
		{
			if (substr[i] == '.' ||
				substr[i] == ',' ||
				substr[i] == '!' ||
				substr[i] == '?' ||
				substr[i] == ':' ||
				substr[i] == ';' ||
				substr[i] == '(' ||
				substr[i] == ')' ||
				substr[i] == '-' ||
				substr[i] == '"' ||
				substr[i] == '«' ||
				substr[i] == '—' ||
				substr[i] == '„' ||
				substr[i] == '“' ||
				substr[i] == '»')
			{
				substr.erase(i, 1);
				i--;
				continue;
			}
			if (substr[i] >= 'A' && substr[i] <= 'Z')
			{
				substr[i] -= 'A' - 'a';
			}

			if (substr[i] >= 'А' && substr[i] <= 'Я')
			{
				substr[i] -= 'А' - 'а';
			}
		}
		if (substr != "")
		{
			token.push_back(substr);
		}
		start = end + delimiter.length();
		end = original_text.find(delimiter, start);
	}

	int count_word = token.size();

	map<string, int> dict;

	for (int i = 0; i < token.size(); i++)
	{
		if (dict.find(token[i]) == dict.end())
			dict[token[i]] = 1;
		else
			dict[token[i]]++;
	}

	return SEOResult(count_letters, count_word, dict);
}

OrtoResult OrtoAlgorithm::DoAlgorithm(IText *text)
{
	//Вместо ортографического анализа выводятся все слова.
	string original_text = text->GetOriginalText();

	string delimiter = " ";
	vector<string> token;
	int start = 0;
	int end = original_text.find(delimiter);
	while (end != string::npos)
	{
		string substr = original_text.substr(start, end - start);
		for (int i = 0; i < substr.size(); i++)
		{
			if (substr[i] == '.' ||
				substr[i] == ',' ||
				substr[i] == '!' ||
				substr[i] == '?' ||
				substr[i] == ':' ||
				substr[i] == ';' ||
				substr[i] == '(' ||
				substr[i] == ')' ||
				substr[i] == '-' ||
				substr[i] == '"' ||
				substr[i] == '«' ||
				substr[i] == '—' ||
				substr[i] == '„' ||
				substr[i] == '“' ||
				substr[i] == '»')
			{
				substr.erase(i, 1);
				i--;
				continue;
			}
			if (substr[i] >= 'A' && substr[i] <= 'Z')
			{
				substr[i] -= 'A' - 'a';
			}

			if (substr[i] >= 'А' && substr[i] <= 'Я')
			{
				substr[i] -= 'А' - 'а';
			}
		}
		if (substr != "")
		{
			token.push_back(substr);
		}
		start = end + delimiter.length();
		end = original_text.find(delimiter, start);
	}

	return OrtoResult(token);
}

CountSymbolResult CountSymbolAlgorithm::DoAlgorithm(SimpleText * text)
{
	string original_text = text->GetText();

	int count_word = 0;
	int count_symbol = 0;

	for (int i = 0; i < original_text.size(); i++)
	{
		if (original_text[i] >= 'а' && original_text[i] <= 'я' ||
			original_text[i] >= 'А' && original_text[i] <= 'Я')
			count_word++;
		else
			count_symbol++;
	}

	return CountSymbolResult(count_word, count_symbol);
}
