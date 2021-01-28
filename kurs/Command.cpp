#include "Command.h"

void ICommand::SetAnalyzer(Analyzer * _analyzer)
{
	analyzer = _analyzer;
}

void DoAnalisCommand::Execute()
{
	cout << "Команда - DoAnalis" << endl;
	analyzer->ClientDoFullAnalis();
}

void PrintTextCommand::Execute()
{
	cout << "Команда - PrintText" << endl;
	analyzer->ClientPrintText();
}

void ReadCommand::Execute()
{
	cout << "Команда - Read" << endl;
	analyzer->ClientRead();
}

void ConfigCommand::Execute()
{
	cout << "Команда - Config" << endl;
	analyzer->ClientConfigurate();
}

void WriteCommand::Execute()
{
	cout << "Команда - Write" << endl;
	analyzer->ClientWrite();
}

AnalyzerRunner::AnalyzerRunner(Analyzer * _analyzer)
{
	analyzer = _analyzer;
}

void AnalyzerRunner::RunCommand(ICommand * com)
{
	cout << "Получил команду. Начинаю выполнение" << endl;
	com->SetAnalyzer(analyzer);
	com->Execute();
}
