#include "Param.h"

UserParam::UserParam(bool seo, bool orto, bool countsymbol)
{
	SEOflag = seo;
	Ortoflag = orto;
	CountSymbolflag = countsymbol;
}

bool UserParam::IsSEO()
{
	return SEOflag;
}

bool UserParam::IsOrto()
{
	return Ortoflag;
}

bool UserParam::IsCountSymbol()
{
	return CountSymbolflag;
}

bool StandartParam::IsSEO()
{
	return true;
}

bool StandartParam::IsOrto()
{
	return true;
}

bool StandartParam::IsCountSymbol()
{
	return true;
}

bool ParamFactoryMethod::IsSEO()
{
	return param->IsSEO();
}

bool ParamFactoryMethod::IsOrto()
{
	return param->IsOrto();
}

bool ParamFactoryMethod::IsCountSymbol()
{
	return param->IsCountSymbol();
}

void UserParamFactoryMethod::CreateParam()
{
	bool seo, orto, count;
	cout << "Вводите y - если анализ выполнять надо!" << endl;
	
	cout << "Будем выполнять СЕО анализ?" << endl;
	
	string answer = "";
	cin >> answer;
	if (answer == "y")
		seo = true;
	else
		seo = false;

	cout << "Будем выполнять ортографический анализ?" << endl;

	answer = "";
	cin >> answer;
	if (answer == "y")
		orto = true;
	else
		orto = false;

	cout << "Будем выполнять третий анализ?" << endl;

	answer = "";
	cin >> answer;
	if (answer == "y")
		count = true;
	else
		count = false;

	cout << "Параметры. Создаём параметры пользователя." << endl;

	param = new UserParam(seo, orto, count);
}

void StandartParamFactoryMethod::CreateParam()
{
	cout << "Параметры. Создаём стандартные параметры." << endl;
	param = new StandartParam();
}
