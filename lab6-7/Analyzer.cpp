#include "Analyzer.h"

Analyzer::Analyzer(
	IWriter *_writer, 
	IReader *_reader, 
	SEOAlgorithm *_seo_analis, 
	OrtoAlgorithm *_orto_analis,
	CountSymbolAlgorithm *_count_analis
)
{
	writer = _writer;
	reader = _reader;
	seo_analis = _seo_analis;
	orto_analis = _orto_analis;
	count_analis = _count_analis;
}

void Analyzer::Read()
{
	text = reader->Read();
}

void Analyzer::Write()
{
	if (seo_analis == NULL)
		cout << "СЕО анализа нет!" << endl;
	else
		writer->Write(seo_result);

	if (orto_analis == NULL)
		cout << "Ортографического анализа нет!" << endl;
	else
		writer->Write(orto_result);

	if (count_analis == NULL)
		cout << "Count анализа нет!" << endl;
	else
		writer->Write(count_result);
}

void Analyzer::PrintText()
{
	//Выведем текст над которым мы делаем анализ с полной информацией.
	cout << "Текст над которым работает алгоритмы:" << endl;
	cout << text->GetAllInfo() << endl;
}

void Analyzer::DoSEOAnalis()
{
	if (seo_analis != NULL)
	{
		cout << endl << "Вызывается SEOAnalis:" << endl;
		seo_result = seo_analis->DoAlgorithm(text);
	}
}

void Analyzer::DoOrtoAnalis()
{
	if (orto_analis != NULL)
	{
		cout << endl << "Вызывается OrtoAnalis:" << endl;
		orto_result = orto_analis->DoAlgorithm(text);
	}
}

void Analyzer::DoCountAnalis()
{
	if (count_analis != NULL)
	{
		cout << endl << "Вызывается CountAnalis:" << endl;
		count_result = count_analis->DoAlgorithm(new Adapter(text));
	}
}

ProxyAnalyzer::ProxyAnalyzer(
	IWriter *_writer, 
	IReader *_reader, 
	SEOAlgorithm *_seo_analis, 
	OrtoAlgorithm *_orto_analis,
	CountSymbolAlgorithm *_count_analis
)
{
	ptr_analyzer = new Analyzer(_writer, _reader, _seo_analis, _orto_analis, _count_analis);
}

ProxyAnalyzer::~ProxyAnalyzer()
{
	delete ptr_analyzer;
}

void ProxyAnalyzer::Read()
{
	cout << "Операция Read." << endl;
	int time_start = clock();
	ptr_analyzer->Read();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}

void ProxyAnalyzer::Write()
{
	cout << "Операция Write." << endl;
	int time_start = clock();
	ptr_analyzer->Write();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}

void ProxyAnalyzer::PrintText()
{
	cout << "Операция PrintText." << endl;
	int time_start = clock();
	ptr_analyzer->PrintText();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}

void ProxyAnalyzer::DoSEOAnalis()
{
	cout << "Операция SEO Analis." << endl;
	int time_start = clock();
	ptr_analyzer->DoSEOAnalis();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}

void ProxyAnalyzer::DoOrtoAnalis()
{
	cout << "Операция OrtoAnalis." << endl;
	int time_start = clock();
	ptr_analyzer->DoOrtoAnalis();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}

void ProxyAnalyzer::DoCountAnalis()
{
	cout << "Операция CountWordAnalis." << endl;
	int time_start = clock();
	ptr_analyzer->DoCountAnalis();
	cout << "Конец операции. Время: " << (clock() - time_start) / 1000 << endl;
}
