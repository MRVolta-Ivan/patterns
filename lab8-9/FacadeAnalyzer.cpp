#include "FacadeAnalyzer.h"

FacadeAnalyzer::FacadeAnalyzer(string typeReadWrite)
{
	Interaction* interaction;

	if (typeReadWrite == "console")
		interaction = new Interaction(
			new ConsoleInteractionFactory());
	else
		interaction = new Interaction(
			new FileInterectionFactory());

	SEOAlgorithm *seo = SEOAlgorithm::GetSEOAlgorithm();
	OrtoAlgorithm *orto = OrtoAlgorithm::GetOrtoAlgorithm();
	CountSymbolAlgorithm *count = CountSymbolAlgorithm::GetCountSymbolAlgorithm();

	ParamFactoryMethod *paramfactory = new StandartParamFactoryMethod();

	analyzer = new Analyzer(
		interaction,
		paramfactory,
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
