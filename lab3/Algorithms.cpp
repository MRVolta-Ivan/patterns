#include "Algorithms.h"

SEOResult SEOAlgorithm::DoAlgorithm(Text text)
{
	//Вместо реального Сео анализа выполняется следующее:
	//Выводится длина текста.
	//Выводится количество слов.
	//Выводятся все слова.
	string original_text = text.GetOriginalText();
	int count_letters = text.GetOriginalText().length();
	
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

OrtoResult OrtoAlgorithm::DoAlgorithm(Text text)
{
	//Вместо ортографического анализа выводятся все слова.
	string original_text = text.GetOriginalText();

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
