﻿#pragma once
#include "Result.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IWriter
{
public:
	virtual void Write(SEOResult result) = 0;
	virtual void Write(OrtoResult result) = 0;
	virtual void Write(CountSymbolResult result) = 0;
};

class WtiterToFile : public IWriter
{
public:
	void Write(SEOResult result);
	void Write(OrtoResult result);
	void Write(CountSymbolResult result);
};

class WriterToConsole : public IWriter
{
public:
	void Write(SEOResult result);
	void Write(OrtoResult result);
	void Write(CountSymbolResult result);
};