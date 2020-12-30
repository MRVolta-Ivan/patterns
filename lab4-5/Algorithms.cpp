#include "Algorithms.h"

SEOResult SEOAlgorithm::DoAlgorithm(IText *text)
{
	//Вместо реального Сео анализа выполняется следующее:
	//Выводится длина текста.
	//Выводится количество слов.
	//Выводятся все слова.
	string original_text = text->GetOriginalText();
	int count_letters = text->GetOriginalText().length();
	
	int count_word = 0;
	for (int i = 0; i < original_text.length(); i++)
		if (original_text[i] == ' ')
			count_word++;


	string delimiter = " ";
	vector<string> token;
	int start = 0;
	int end = original_text.find(delimiter);
	while (end != string::npos)
	{
		token.push_back(original_text.substr(start, end - start));
		start = end + delimiter.length();
		end = original_text.find(delimiter, start);
	}

	return SEOResult(count_letters, count_word, token);
}

OrtoResult OrtoAlgorithm::DoAlgorithm(IText *text)
{
	//Вместо ортографичческого анализа выводятся все слова.
	string original_text = text->GetOriginalText();

	string delimiter = " ";
	vector<string> token;
	int start = 0;
	int end = original_text.find(delimiter);
	while (end != string::npos)
	{
		token.push_back(original_text.substr(start, end - start));
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
