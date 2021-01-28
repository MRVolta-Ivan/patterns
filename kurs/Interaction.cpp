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
	return new ReaderFromFile();
}

IWriter * FileInterectionFactory::createWriter()
{
	cout << "Файл. Создаём Writer." << endl;
	return new WriterToFile();
}

Interaction::Interaction(InteractionFactory * _factory)
{
	factory = _factory;
}

IText * Interaction::Read()
{
	return reader->Read();
}

void Interaction::Create()
{
	reader = factory->createReader();
	writer = factory->createWriter();
}

void Interaction::Write(SEOResult result)
{
	writer->Write(result);
}

void Interaction::Write(OrtoResult result)
{
	writer->Write(result);
}

void Interaction::update(SEOResult result)
{
	cout << "Я получил результат работы СЕО алгоритма." << endl;

	Write(result);
}
