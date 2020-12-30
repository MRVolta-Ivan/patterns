#pragma once
#include "Text.h"
#include <fstream>
#include <iostream>

class IReader
{
public:
	virtual IText* Read() = 0;
};


class ReaderFromFile : public IReader
{
public:
	IText* Read();
};

class ReaderFromConsole : public IReader
{
public:
	IText* Read();
};
