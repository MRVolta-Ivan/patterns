#include <Windows.h>
#include "Analyzer.h"
#include "FacadeAnalyzer.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Используем файсад.
	FacadeAnalyzer facade("console");

	facade.DoAnalys();


	//Воспользуемся файловым вводом/выводом.
	Interaction* interaction = new Interaction(new FileInterectionFactory());

	//Будем использовать пользовательские настройки.
	ParamFactoryMethod* param = new UserParamFactoryMethod();

	Analyzer analyzer(
		interaction,
		param,
		SEOAlgorithm::GetSEOAlgorithm(),
		OrtoAlgorithm::GetOrtoAlgorithm(),
		CountSymbolAlgorithm::GetCountSymbolAlgorithm()
	);

	analyzer.Read();
	analyzer.PrintText();
	analyzer.DoSEOAnalis();
	analyzer.DoOrtoAnalis();
	analyzer.DoCountAnalis();
	analyzer.Write();

	return 0;
}