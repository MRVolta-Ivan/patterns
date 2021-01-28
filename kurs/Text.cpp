#include "Text.h"

Text::Text()
{
	original_text = "";
}

Text::Text(string text)
{
	original_text = text;
}

string Text::GetOriginalText()
{
	return original_text;
}

string Text::GetAllInfo()
{
	return "Текст: " + original_text + "\n";
}

Adapter::Adapter(IText * _text)
{
	text = _text;
}

string Adapter::GetText()
{
	cout << "Адаптер: GetText." << endl;
	cout << "Вызывается GetOriginalText IText* text." << endl;

	return text->GetOriginalText();
}

DecoratorText::DecoratorText(IText *_text)
{
	text = _text;
}

LanguageText::LanguageText(string _language, IText * _text) 
	: DecoratorText(_text)
{
	language = _language;
}

string LanguageText::GetOriginalText()
{
	cout << "Декоратор LanguageText: GetOriginalText." << endl;
	cout << "Вызывается GetOriginalText IText* text." << endl;

	return text->GetOriginalText();
}

string LanguageText::GetAllInfo()
{
	cout << "Декоратор LanguageText: GetAllInfo." << endl;
	cout << "Собирает все данные. Вызывается GetAllInfo IText* text." << endl;

	return "Язык текста: " + language + "\n" + text->GetAllInfo();
}

string LanguageText::GetLanguage()
{
	return language;
}

DescriptionText::DescriptionText(string _description, IText * _text) 
	: DecoratorText(_text)
{
	description = _description;
}

string DescriptionText::GetOriginalText()
{
	cout << "Декоратор DescriptionText: GetOriginalText." << endl;
	cout << "Вызывается GetOriginalText IText* text." << endl;

	return text->GetOriginalText();
}

string DescriptionText::GetAllInfo()
{
	cout << "Декоратор DescriptionText: GetAllInfo." << endl;
	cout << "Собирает все данные. Вызывается GetAllInfo IText* text." << endl;

	return "Описание: " + description + "\n" + text->GetAllInfo();
}

string DescriptionText::GetDescription()
{
	return description;
}

AuthorText::AuthorText(string _author, IText * _text) 
	: DecoratorText(_text)
{
	author = _author;
}

string AuthorText::GetOriginalText()
{
	cout << "Декоратор AuthorText: GetOriginalText." << endl;
	cout << "Вызывается GetOriginalText IText* text." << endl;

	return text->GetOriginalText();
}

string AuthorText::GetAllInfo()
{
	cout << "Декоратор AuthorText: GetAllInfo." << endl;
	cout << "Собирает все данные. Вызывается GetAllInfo IText* text." << endl;

	return "Автор/Алгоритм: " + author + "\n" + text->GetAllInfo();
}

string AuthorText::GetAuthor()
{
	return author;
}
