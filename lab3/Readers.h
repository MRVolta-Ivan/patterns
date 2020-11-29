#pragma once
#include "Text.h"
#include <fstream>
#include <iostream>

class IReader
{
public:
	virtual Text Read() = 0;
};


class ReaderFromFile : public IReader
{
public:
	Text Read();
};

class ReaderFromConsole : public IReader
{
public:
	Text Read();
};
