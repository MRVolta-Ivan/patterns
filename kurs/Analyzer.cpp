#include "Analyzer.h"

Analyzer::Analyzer(
	Interaction* _interaction,
	ParamFactoryMethod* _paramfactory,
	SEOAlgorithm *_seo_analis, 
	OrtoAlgorithm *_orto_analis
)
{
	interaction = _interaction;

	paramfactory = _paramfactory;

	seo_analis = _seo_analis;
	orto_analis = _orto_analis;
}

void Analyzer::SetState(IAnalyzerState * _state)
{
	delete state;
	state = _state;
}

void Analyzer::ClientConfigurate()
{
	state->Configurate(this);
}

void Analyzer::ClientRead()
{
	state->Read(this);
}

void Analyzer::ClientWrite()
{
	state->Write(this);
}

void Analyzer::ClientDoFullAnalis()
{
	state->DoFullAnalis(this);
}

void Analyzer::ClientPrintText()
{
	state->PrintText(this);
}

void Analyzer::Configurate()
{
	paramfactory->CreateParam();
	interaction->Create();
}

void Analyzer::Read()
{
	text = interaction->Read();
}

void Analyzer::Write()
{
	if (!paramfactory->IsSEO())
			cout << "СЕО анализа нет!" << endl;
	else
		interaction->Write(seo_result);

	if (!paramfactory->IsOrto())
			cout << "Ортографического анализа нет!" << endl;
	else
		interaction->Write(orto_result);
}

void Analyzer::PrintText()
{
	//Выведем текст над которым мы делаем анализ с полной информацией.
	cout << "Текст над которым работает алгоритмы:" << endl;
	cout << text->GetAllInfo() << endl;
}

void Analyzer::DoFullAnalis()
{
	DoSEOAnalis();
	DoOrtoAnalis();
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

void NoConfigurateState::Configurate(Analyzer * context)
{
	context->Configurate();
	context->SetState(new NoReadState());
}

void NoConfigurateState::Read(Analyzer* context)
{
	cout << "Сначала настройте анализатор!" << endl;
}

void NoConfigurateState::PrintText(Analyzer* context)
{
	cout << "Сначала настройте анализатор!" << endl;
}

void NoConfigurateState::DoFullAnalis(Analyzer* context)
{
	cout << "Сначала настройте анализатор!" << endl;
}

void NoConfigurateState::Write(Analyzer* context)
{
	cout << "Сначала настройте анализатор!" << endl;
}

void NoReadState::Configurate(Analyzer* context)
{
	context->Configurate();
}

void NoReadState::Read(Analyzer* context)
{
	context->Read();
	context->SetState(new NoAnalisState());
}

void NoReadState::PrintText(Analyzer* context)
{
	cout << "Для начала работы введите текст!" << endl;
}

void NoReadState::DoFullAnalis(Analyzer* context)
{
	cout << "Для начала работы введите текст!" << endl;
}

void NoReadState::Write(Analyzer* context)
{
	cout << "Для начала работы введите текст!" << endl;
}

void FullWorkState::Configurate(Analyzer* context)
{
	context->Configurate();
}

void FullWorkState::Read(Analyzer* context)
{
	context->Read();
}

void FullWorkState::PrintText(Analyzer* context)
{
	context->PrintText();
}

void FullWorkState::DoFullAnalis(Analyzer* context)
{
	context->DoFullAnalis();
}

void FullWorkState::Write(Analyzer* context)
{
	context->Write();
}

void NoAnalisState::Configurate(Analyzer * context)
{
	context->Configurate();
}

void NoAnalisState::Read(Analyzer * context)
{
	context->Read();
}

void NoAnalisState::PrintText(Analyzer * context)
{
	context->PrintText();
}

void NoAnalisState::DoFullAnalis(Analyzer * context)
{
	context->DoFullAnalis();
	context->SetState(new FullWorkState());
}

void NoAnalisState::Write(Analyzer * context)
{
	cout << "Выполните анализ текста, чтобы вывести его результат!" << endl;
}
