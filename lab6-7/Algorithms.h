#pragma once
#include <map>

#include "Result.h"
#include "Text.h"

class SEOAlgorithm
{
public:
	SEOResult DoAlgorithm(IText *text);
};

class OrtoAlgorithm
{
public:
	OrtoResult DoAlgorithm(IText *text);
};

class CountSymbolAlgorithm
{
public:
	CountSymbolResult DoAlgorithm(SimpleText *text);
};
