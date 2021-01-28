#pragma once
#include "Analyzer.h"

//Команда.
class ICommand
{
protected:
	Analyzer* analyzer;
public:
	virtual void Execute() = 0;
	virtual void SetAnalyzer(Analyzer* _analyzer);
};

class DoAnalisCommand : public ICommand
{
public:
	void Execute();
};

class PrintTextCommand : public ICommand
{
public:
	void Execute();
};

class ReadCommand : public ICommand
{
public:
	void Execute();
};

class ConfigCommand : public ICommand
{
public:
	void Execute();
};

class WriteCommand : public ICommand
{
public:
	void Execute();
};


class AnalyzerRunner
{
private:
	Analyzer* analyzer;
public:
	AnalyzerRunner(Analyzer* _analyzer);
	void RunCommand(ICommand* com);
};