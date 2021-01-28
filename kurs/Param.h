#pragma once
#include <iostream>
#include <string>

using namespace std;

class IParam
{
public:
	virtual bool IsSEO() = 0;
	virtual bool IsOrto() = 0;
};

class UserParam : public IParam
{
private:
	bool SEOflag;
	bool Ortoflag;
public:
	UserParam(bool seo, bool orto);
	bool IsSEO();
	bool IsOrto();
};

class StandartParam : public IParam
{
public:
	bool IsSEO();
	bool IsOrto();
};

//Фабричный метод
class ParamFactoryMethod
{
public:
	virtual void CreateParam() = 0;
	bool IsSEO();
	bool IsOrto();
protected:
	IParam * param;
};

class UserParamFactoryMethod : public ParamFactoryMethod
{
public:
	void CreateParam();
};

class StandartParamFactoryMethod : public ParamFactoryMethod
{
	void CreateParam();
};
