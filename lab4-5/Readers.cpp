#include "Readers.h"

IText* ReaderFromFile::Read()
{
	string text = "";

	ifstream input_file("input.txt");

	while (!input_file.eof())
	{
		string word;
		input_file >> word;
		text += word + " ";
	}

	input_file.close();

	return new Text(text);
}

IText* ReaderFromConsole::Read()
{
	string text = "";

	IText *result_text;

	cout << "Введите предложение (Для прекращения ввода введите !stop):" << endl;
	
	string word = "";

	while (true)
	{
		cin >> word;
		if (word == "!stop")
			break;
		text += word + " ";
	}

	result_text = new Text(text);

	cout << "Будем вводить язык текста?" << endl;
	cout << "1 - да, 2 - нет." << endl;
	word = "";

	while (true)
	{
		cin >> word;
		if (word == "1")
		{
			string language = "";
			cout << "Введите язык текста:" << endl;
			cin >> language;
			result_text = new LanguageText(language, result_text);
			break;
		}
		if (word == "2")
			break;
		word = "";
	}

	cout << "Будем вводить описание для текста?" << endl;
	cout << "1 - да, 2 - нет." << endl;
	word = "";

	while (true)
	{
		cin >> word;
		if (word == "1")
		{
			string description = "";
			cout << "Введите описание:" << endl;
			word = "";
			cout << "(Для прекращения ввода введите !stop):" << endl;
			while (true)
			{
				cin >> word;
				if (word == "!stop")
					break;
				description += word + " ";
			}
			result_text = new DescriptionText(description, result_text);
			break;
		}
		if (word == "2")
			break;
		word = "";
	}

	cout << "Будем вводить автора текста или алгоритм, который сгенерировал текст?" << endl;
	cout << "1 - да, 2 - нет." << endl;
	word = "";

	while (true)
	{
		cin >> word;
		if (word == "1")
		{
			string author = "";
			cout << "Введите автора:" << endl;
			word = "";
			cout << "(Для прекращения ввода введите !stop):" << endl;
			while (true)
			{
				cin >> word;
				if (word == "!stop")
					break;
				author += word + " ";
			}
			result_text = new AuthorText(author, result_text);
			break;
		}
		if (word == "2")
			break;
		word = "";
	}

	return result_text;
}
