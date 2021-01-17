#pragma once
#include <map>

#include "Result.h"
#include "Text.h"

class SEOAlgorithm
{
public:
	static SEOAlgorithm* GetSEOAlgorithm();
	SEOResult DoAlgorithm(IText *text);
private:
	SEOAlgorithm();
	static SEOAlgorithm* p_instance;
};

class OrtoAlgorithm
{
public:
	static OrtoAlgorithm* GetOrtoAlgorithm();
	OrtoResult DoAlgorithm(IText *text);
private:
	OrtoAlgorithm();
	static OrtoAlgorithm* p_instance;
};

class CountSymbolAlgorithm
{
public:
	static CountSymbolAlgorithm* GetCountSymbolAlgorithm();
	CountSymbolResult DoAlgorithm(SimpleText *text);
private:
	CountSymbolAlgorithm();
	static CountSymbolAlgorithm* p_instance;
};
