#include "Readers.h"

Text ReaderFromFile::Read()
{
	string text = "";

	ifstream input_file("input.txt");

	string language = "";

	input_file >> language;

	while (!input_file.eof())
	{
		string word;
		input_file >> word;
		text += word + " ";
	}

	input_file.close();

	return Text(language, text);
}

Text ReaderFromConsole::Read()
{
	string text = "";

	string language = "";

	cout << "Введите язык:" << endl;

	cin >> language;

	cout << "Введите предложение (для прекращения ввода введите !stop):" << endl;
	
	string word = "";

	while (true)
	{
		cin >> word;
		if (word == "!stop")
			break;
		text += word + " ";
	}

	return Text(language, text);
}
