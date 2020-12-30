#include <Windows.h>
#include "Analyzer.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Analyzer analyzer(
		new WriterToConsole(),
		new ReaderFromConsole(),
		new SEOAlgorithm(),
		new OrtoAlgorithm(),
		new CountSymbolAlgorithm());

	analyzer.Read();
	analyzer.PrintText();
	analyzer.DoSEOAnalis();
	analyzer.DoOrtoAnalis();
	analyzer.DoCountAnalis();
	analyzer.Write();

	cout << endl << "Работа с прокси:" << endl;
	 
	ProxyAnalyzer proxy(
		new WtiterToFile(),
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