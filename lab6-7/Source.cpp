#include <Windows.h>
#include "Analyzer.h"
#include "FacadeAnalyzer.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Используем файсад.
	FacadeAnalyzer facade;

	facade.DoAnalys();

	cout << endl << "Работа с прокси:" << endl;
	 
	ProxyAnalyzer proxy(
		new WriterToFile(),
		new ReaderFromFile(),
		new SEOAlgorithm(),
		new OrtoAlgorithm(),
		new CountSymbolAlgorithm());

	proxy.Read();
	proxy.PrintText();
	proxy.DoSEOAnalis();
	proxy.DoOrtoAnalis();
	proxy.DoCountAnalis();
	proxy.Write();

	return 0;
}