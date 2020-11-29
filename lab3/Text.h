#pragma once
#include <string>

using namespace std;

class Text
{
public:
	Text();
	Text(string _language, string text);
	string GetOriginalText();
private:
	string language;
	string original_text;
};


