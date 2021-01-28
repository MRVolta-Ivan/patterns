#pragma once
#include "Algorithms.h"
#include "Interaction.h"
#include <ctime>
#include "Param.h"

class IAnalyzerState;

class Analyzer
{
public:
	Analyzer(
		Interaction* _interaction,
		ParamFactoryMethod* _paramfactory,
		SEOAlgorithm *_seo_analis,
		OrtoAlgorithm *_orto_analis
	);

	void SetState(IAnalyzerState* _state);

	void ClientConfigurate();
	void ClientRead();
	void ClientWrite();
	void ClientDoFullAnalis();
	void ClientPrintText();

	void Configurate();
	void Read();
	void Write();
	void PrintText();
	void DoFullAnalis();
	void DoSEOAnalis();
	void DoOrtoAnalis();
	
private:
	IText *text;
	
	SEOAlgorithm *seo_analis;
	OrtoAlgorithm *orto_analis;
	
	SEOResult seo_result;
	OrtoResult orto_result;

	ParamFactoryMethod* paramfactory;

	Interaction* interaction;

	IAnalyzerState* state;
};

//Состояние.
class IAnalyzerState
{
protected:
	;
public:
	virtual void Configurate(Analyzer* context) = 0;
	virtual void Read(Analyzer* context) = 0;
	virtual void PrintText(Analyzer* context) = 0;
	virtual void DoFullAnalis(Analyzer* context) = 0;
	virtual void Write(Analyzer* context) = 0;

};

class NoConfigurateState : public IAnalyzerState
{
	void Configurate(Analyzer* context);
	void Read(Analyzer* context);
	void PrintText(Analyzer* context);
	void DoFullAnalis(Analyzer* context);
	void Write(Analyzer* context);
};

class NoReadState : public IAnalyzerState
{
	void Configurate(Analyzer* context);
	void Read(Analyzer* context);
	void PrintText(Analyzer* context);
	void DoFullAnalis(Analyzer* context);
	void Write(Analyzer* context);
};

class NoAnalisState : public IAnalyzerState
{
	void Configurate(Analyzer* context);
	void Read(Analyzer* context);
	void PrintText(Analyzer* context);
	void DoFullAnalis(Analyzer* context);
	void Write(Analyzer* context);
};

class FullWorkState : public IAnalyzerState
{
	void Configurate(Analyzer* context);
	void Read(Analyzer* context);
	void PrintText(Analyzer* context);
	void DoFullAnalis(Analyzer* context);
	void Write(Analyzer* context);
};
