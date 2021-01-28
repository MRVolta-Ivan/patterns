#include "Writers.h"

WriterToFile::WriterToFile()
{
	nameFile = "output.txt";
}

void WriterToFile::Write(SEOResult result)
{
	ofstream output_file("seo_" + nameFile);

	output_file << "Количество символов: " << result.GetCountLetters() << endl;
	output_file << "Количество слов: " << result.GetCountWord() << endl;
	map<string, int> keyword = result.GetKeyword();
	map<string, double> percent = result.GetPercentText();

	output_file << "Слова и сколько раз они встречаются в тексте: " << endl;

	for (map<string, int> ::iterator it = keyword.begin(); it != keyword.end(); it++)
	{
		output_file << (*it).first << " - кол-во: " << (*it).second;
		output_file << " - процент: " << percent[(*it).first] << "%" << endl;
	}

	output_file << endl;

	output_file.close();
}

void WriterToFile::Write(OrtoResult result)
{
	ofstream output_file("orto_" + nameFile);

	vector<string> mistake_word = result.GetMistakeWord();

	output_file << "слова, в которых допущенна ошибка: ";
	for (int i = 0; i < mistake_word.size(); i++)
		output_file << mistake_word[i] << " ";

	output_file << endl;

	output_file.close();
}

void WriterToConsole::Write(SEOResult result)
{
	cout << "Результат SEO analis." << endl;
	cout << "Количество символов: " << result.GetCountLetters() << endl;
	cout << "Количество слов: " << result.GetCountWord() << endl;
	cout << "Слова и сколько раз они встречаются в тексте: " << endl;
	map<string, int> keyword = result.GetKeyword();
	map<string, double> percent = result.GetPercentText();

	for (map<string, int> ::iterator it = keyword.begin(); it != keyword.end(); it++)
	{
		cout << (*it).first << " - кол-во: " << (*it).second;
		cout << " - процент: " << percent[(*it).first] << "%" << endl;
	}

	cout << endl;
}
 
void WriterToConsole::Write(OrtoResult result)
{
	vector<string> mistake_word = result.GetMistakeWord();

	cout << "Результат Orto analis." << endl;
	cout << "Cлова, в которых допущенна ошибка: " << endl;
	for (int i = 0; i < mistake_word.size(); i++)
		cout << mistake_word[i] << " ";

	cout << endl;
}
