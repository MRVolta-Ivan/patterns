#pragma once
#include "Readers.h"
#include "Writers.h"

class InteractionFactory
{
public:
	virtual IReader* createReader() = 0;
	virtual IWriter* createWriter() = 0;
};

class ConsoleInteractionFactory : public InteractionFactory
{
public:
	IReader* createReader();
	IWriter* createWriter();
};

class FileInterectionFactory : public InteractionFactory
{
public:
	IReader* createReader();
	IWriter* createWriter();
};

class Interaction
{
public:
	Interaction(InteractionFactory* _factory);
	IText* Read();
	void Write(SEOResult result);
	void Write(OrtoResult result);
	void Write(CountSymbolResult result);
private:
	IWriter* writer;
	IReader* reader;
	InteractionFactory* factory;
};

