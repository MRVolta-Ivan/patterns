#include "FacadeAnalyzer.h"

FacadeAnalyzer::FacadeAnalyzer()
{
	IReader *reader = new ReaderFromConsole();
	IWriter *writer = new WriterToConsole();

	SEOAlgorithm *seo = new SEOAlgorithm();
	OrtoAlgorithm *orto = new OrtoAlgorithm();
	CountSymbolAlgorithm *count = new CountSymbolAlgorithm();

	analyzer = new Analyzer(
		writer,
		reader,
		seo,
		orto,
		count);

}

FacadeAnalyzer::FacadeAnalyzer(string inputFile, string outputFile)
{
	cout << "создаём фасад." << endl;
	IReader *reader = new ReaderFromFile(inputFile);
	IWriter *writer = new WriterToFile(outputFile);

	SEOAlgorithm *seo = new SEOAlgorithm();
	OrtoAlgorithm *orto = new OrtoAlgorithm();
	CountSymbolAlgorithm *count = new CountSymbolAlgorithm();

	analyzer = new Analyzer(
		writer,
		reader,
		seo,
		orto,
		count);
}

void FacadeAnalyzer::DoAnalys()
{
	cout << "Фасад. Читаем данные." << endl;
	analyzer->Read();
	cout << "Фасад. Выводим информацию о тексте." << endl;
	analyzer->PrintText();
	cout << "Фасад. Выполняем анализ." << endl;
	analyzer->DoSEOAnalis();
	analyzer->DoOrtoAnalis();
	analyzer->DoCountAnalis();
	cout << "Фасад. Сохраняем результат анализов." << endl;
	analyzer->Write();
}
