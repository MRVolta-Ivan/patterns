#pragma once
#include "Readers.h"
#include "Writers.h"

#include "Observer.h"
#include "Result.h"

//Абстракная фабрика.
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

class Interaction : public IObserverSEO
{
public:
	Interaction(InteractionFactory* _factory);
	IText* Read();
	void Create();
	void Write(SEOResult result);
	void Write(OrtoResult result);

	void update(SEOResult result);
private:
	IWriter* writer;
	IReader* reader;
	InteractionFactory* factory;
};

