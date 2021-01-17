#include "Interaction.h"

IReader * ConsoleInteractionFactory::createReader()
{
	cout << "Консоль. Создаём Reader." << endl;
	return new ReaderFromConsole();
}

IWriter * ConsoleInteractionFactory::createWriter()
{
	cout << "Консоль. Создаём Writer." << endl;
	return new WriterToConsole();
}

IReader * FileInterectionFactory::createReader()
{
	cout << "Файл. Создаём Reader." << endl;
	return new ReaderFromFile;
}

IWriter * FileInterectionFactory::createWriter()
{
	cout << "Файл. Создаём Writer." << endl;
	return new WriterToFile();
}

Interaction::Interaction(InteractionFactory * _factory)
{
	factory = _factory;
	reader = factory->createReader();
	writer = factory->createWriter();
}

IText * Interaction::Read()
{
	return reader->Read();
}

void Interaction::Write(SEOResult result)
{
	writer->Write(result);
}

void Interaction::Write(OrtoResult result)
{
	writer->Write(result);
}

void Interaction::Write(CountSymbolResult result)
{
	writer->Write(result);
}
