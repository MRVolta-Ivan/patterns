#include <Windows.h>
#include "Analyzer.h"
#include "Command.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Воспользуемся файловым вводом/выводом.
	Interaction* interaction = new Interaction(new ConsoleInteractionFactory());

	Interaction* interaction2 = new Interaction(new FileInterectionFactory());

	interaction2->Create();

	SEOAlgorithm::GetSEOAlgorithm()->AddObserver(interaction);
	SEOAlgorithm::GetSEOAlgorithm()->AddObserver(interaction2);

	//Будем использовать пользовательские настройки.
	ParamFactoryMethod* param = new UserParamFactoryMethod();

	Analyzer* analyzer = new Analyzer(
		interaction,
		param,
		SEOAlgorithm::GetSEOAlgorithm(),
		OrtoAlgorithm::GetOrtoAlgorithm()
	);

	analyzer->SetState(new NoConfigurateState());

	AnalyzerRunner runner(analyzer);

	//Менюшечка.
	int answer = 0;

	while (answer != 6)
	{
		answer = 0;
		cout << "Выбирите действие:" << endl;
		cout << "1 - Настроить анализатор." << endl;
		cout << "2 - Задать текст." << endl;
		cout << "3 - Напечатать заданный текст." << endl;
		cout << "4 - Выполнить анализ текста." << endl;
		cout << "5 - Напечатать результат анализа." << endl;
		cout << "6 - Выйти из программы." << endl;
		cin >> answer;

		ICommand* com;

		switch (answer)
		{
		case 1:
			com = new ConfigCommand();
			runner.RunCommand(com);
			break;
		case 2:
			com = new ReadCommand();
			runner.RunCommand(com);
			break;
		case 3:
			com = new PrintTextCommand();
			runner.RunCommand(com);
			break;
		case 4:
			com = new DoAnalisCommand();
			runner.RunCommand(com);
			break;
		case 5:
			com = new WriteCommand();
			runner.RunCommand(com);
			break;
		case 6:
			break;
		}
	}




	return 0;
}