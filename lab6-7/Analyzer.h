#pragma once
#include "Algorithms.h"
#include "Readers.h"
#include "Writers.h"
#include <ctime>

class IAnalyzer
{
public:
	virtual void Read() = 0;
	virtual void Write() = 0;
	virtual void PrintText() = 0;
	virtual void DoSEOAnalis() = 0;
	virtual void DoOrtoAnalis() = 0;
	virtual void DoCountAnalis() = 0;
};

class Analyzer : public IAnalyzer
{
public:
	Analyzer(
		IWriter *_writer,
		IReader *_reader,
		SEOAlgorithm *_seo_analis,
		OrtoAlgorithm *_orto_analis,
		CountSymbolAlgorithm *_count_analis
	);

	void Read();
	void Write();
	void PrintText();
	void DoSEOAnalis();
	void DoOrtoAnalis();
	void DoCountAnalis();
	
private:
	IText *text;
	
	SEOAlgorithm *seo_analis;
	OrtoAlgorithm *orto_analis;
	CountSymbolAlgorithm *count_analis;
	
	SEOResult seo_result;
	OrtoResult orto_result;
	CountSymbolResult count_result;

	IWriter *writer;
	IReader *reader;
};

class ProxyAnalyzer : public IAnalyzer
{
public:
	ProxyAnalyzer(
		IWriter *_writer, 
		IReader *_reader, 
		SEOAlgorithm *_seo_analis, 
		OrtoAlgorithm *_orto_analis,
		CountSymbolAlgorithm *_count_analis
	);
	~ProxyAnalyzer();

	void Read();
	void Write();
	void PrintText();
	void DoSEOAnalis();
	void DoOrtoAnalis();
	void DoCountAnalis();

private:
	IAnalyzer *ptr_analyzer;
};

