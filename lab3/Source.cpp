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
		new OrtoAlgorithm());

	analyzer.Read();
	analyzer.DoSEOAnalis();
	analyzer.DoOrtoAnalis();
	analyzer.Write();

	cout << endl << "Работа с прокси:" << endl;
	 
	ProxyAnalyzer proxy(
		new WtiterToFile(),
		new ReaderFromFile(),
		new SEOAlgorithm(),
		new OrtoAlgorithm());;

	proxy.Read();
	proxy.DoSEOAnalis();
	proxy.DoOrtoAnalis();
	proxy.Write();

	return 0;
}