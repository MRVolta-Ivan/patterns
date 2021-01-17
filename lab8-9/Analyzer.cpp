#include "Analyzer.h"

Analyzer::Analyzer(
	Interaction* _interaction,
	ParamFactoryMethod* _paramfactory,
	SEOAlgorithm *_seo_analis, 
	OrtoAlgorithm *_orto_analis,
	CountSymbolAlgorithm *_count_analis
)
{
	interaction = _interaction;

	paramfactory = _paramfactory;
	paramfactory->CreateParam();

	seo_analis = _seo_analis;
	orto_analis = _orto_analis;
	count_analis = _count_analis;
}

void Analyzer::Read()
{
	text = interaction->Read();
}

void Analyzer::Write()
{
	if (seo_analis == NULL)
		if (paramfactory->IsSEO())
			cout << "СЕО анализа нет!" << endl;
	else
		interaction->Write(seo_result);

	if (orto_analis == NULL)
		if (paramfactory->IsOrto())
			cout << "Ортографического анализа нет!" << endl;
	else
		interaction->Write(orto_result);

	if (count_analis == NULL)
		if (paramfactory->IsCountSymbol())
			cout << "Count анализа нет!" << endl;
	else
		interaction->Write(count_result);
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
		if (paramfactory->IsSEO())
			seo_result = seo_analis->DoAlgorithm(text);
		else
			cout << "Пользователь не выбрал SEOAnalis." << endl;
	}
}

void Analyzer::DoOrtoAnalis()
{
	if (orto_analis != NULL)
	{
		cout << endl << "Вызывается OrtoAnalis:" << endl;\
		if (paramfactory->IsOrto())
			orto_result = orto_analis->DoAlgorithm(text);
		else
			cout << "Пользователь не выбрал OrtoAnalis." << endl;
	}
}

void Analyzer::DoCountAnalis()
{
	if (count_analis != NULL)
	{
		cout << endl << "Вызывается CountAnalis:" << endl;
		if (paramfactory->IsCountSymbol())
			count_result = count_analis->DoAlgorithm(new Adapter(text));
		else
			cout << "Пользователь не выбрал CountAnalis." << endl;
	}
}

ProxyAnalyzer::ProxyAnalyzer(
	Interaction* _interaction, 
	ParamFactoryMethod * _paramfactory,
	SEOAlgorithm *_seo_analis, 
	OrtoAlgorithm *_orto_analis,
	CountSymbolAlgorithm *_count_analis
)
{
	ptr_analyzer = new Analyzer(_interaction, _paramfactory, _seo_analis, _orto_analis, _count_analis);
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
