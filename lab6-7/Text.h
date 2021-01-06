#pragma once
#include <string>
#include <iostream>

using namespace std;

class IText
{
public:
	virtual string GetOriginalText() = 0;
	virtual string GetAllInfo() = 0;
};

class Text : public IText
{
public:
	Text();
	Text(string text);
	string GetOriginalText();
	string GetAllInfo();
private:
	string original_text;
};

class DecoratorText : public IText
{
public:
	virtual string GetOriginalText() = 0;
	virtual string GetAllInfo() = 0;
	DecoratorText(IText *_text);
protected:
	IText *text;
};

class LanguageText : public DecoratorText
{
public:
	LanguageText(string _language, IText *_text);
	string GetOriginalText();
	string GetAllInfo();

	string GetLanguage();
private:
	string language;
};

class DescriptionText : public DecoratorText
{
public:
	DescriptionText(string _description, IText *_text);
	string GetOriginalText();
	string GetAllInfo();

	string GetDescription();
private:
	string description;
};

class AuthorText : public DecoratorText
{
public:
	AuthorText(string _author, IText *_text);
	string GetOriginalText();
	string GetAllInfo();

	string GetAuthor();
private:
	string author;
};

class SimpleText
{
public:
	virtual string GetText() = 0;
};

class Adapter : public SimpleText
{
public:
	Adapter(IText *_text);
	string GetText();
private:
	IText *text;
};

