#include "Text.h"

Text::Text()
{
	language = "";
	original_text = "";
}

Text::Text(string _language, string text)
{
	language = _language;
	original_text = text;
}

string Text::GetOriginalText()
{
	return original_text;
}
