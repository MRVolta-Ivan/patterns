#pragma once
#include "Analyzer.h"

class FacadeAnalyzer
{
public:
	FacadeAnalyzer();
	FacadeAnalyzer(string inputFile, string outputFile);
	void DoAnalys();
private:
	IAnalyzer *analyzer;
};

