#include "Writers.h"

void WtiterToFile::Write(SEOResult result)
{
	ofstream output_file("seo_output.txt");

	output_file << "Количество символов: " << result.GetCountLetters() << endl;
	output_file << "Количество слов: " << result.GetCountWord() << endl;
	vector<string> keyword = result.GetKeyword();

	output_file << "Ключевые слова: ";
	for (int i = 0; i < keyword.size(); i++)
		output_file << keyword[i] <<  " ";

	output_file << endl;

	output_file.close();
}

void WtiterToFile::Write(OrtoResult result)
{
	ofstream output_file("orto_output.txt");

	vector<string> mistake_word = result.GetMistakeWord();

	output_file << "слова, в которых допущенна ошибка: ";
	for (int i = 0; i < mistake_word.size(); i++)
		output_file << mistake_word[i] << " ";

	output_file << endl;

	output_file.close();
}

void WtiterToFile::Write(CountSymbolResult result)
{
	ofstream output_file("count_output.txt");

	output_file << "Количество букв: " << result.GetCountLetter() << endl;
	output_file << "Количество символов: " << result.GetCountSymbol() << endl;

	output_file << endl;

	output_file.close();
}

void WriterToConsole::Write(SEOResult result)
{

	cout << "Количество символов: " << result.GetCountLetters() << endl;
	cout << "Количество слов: " << result.GetCountWord() << endl;
	vector<string> keyword = result.GetKeyword();

	cout << "Ключевые слова: " << endl;
	for (int i = 0; i < keyword.size(); i++)
		cout << keyword[i] << " ";

	cout << endl;
}
 
void WriterToConsole::Write(OrtoResult result)
{
	vector<string> mistake_word = result.GetMistakeWord();

	cout << "Cлова, в которых допущенна ошибка: " << endl;
	for (int i = 0; i < mistake_word.size(); i++)
		cout << mistake_word[i] << " ";

	cout << endl;
}

void WriterToConsole::Write(CountSymbolResult result)
{
	cout << "Количество букв: " << result.GetCountLetter() << endl;
	cout << "Количество символов: " << result.GetCountSymbol() << endl;

	cout << endl;
}
