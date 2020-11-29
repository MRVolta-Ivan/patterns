#include "Analyzer.h"

Analyzer::Analyzer(IWriter *_writer, IReader *_reader, SEOAlgorithm *_seo_analis, OrtoAlgorithm *_orto_analis)
{
	writer = _writer;
	reader = _reader;
	seo_analis = _seo_analis;
	orto_analis = _orto_analis;
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
}

void Analyzer::DoSEOAnalis()
{
	if (seo_analis != NULL)
		seo_result = seo_analis->DoAlgorithm(text);
}

void Analyzer::DoOrtoAnalis()
{
	if (orto_analis != NULL)
		orto_result = orto_analis->DoAlgorithm(text);
}

ProxyAnalyzer::ProxyAnalyzer(IWriter *_writer, IReader *_reader, SEOAlgorithm *_seo_analis, OrtoAlgorithm *_orto_analis)
{
	ptr_analyzer = new Analyzer(_writer, _reader, _seo_analis, _orto_analis);
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
