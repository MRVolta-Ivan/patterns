#pragma once
#include "Analyzer.h"

class FacadeAnalyzer
{
public:
	FacadeAnalyzer(string typeReadWrite);
	void DoAnalys();
private:
	IAnalyzer *analyzer;
};

