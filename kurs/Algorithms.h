#pragma once
#include <map>
#include <vector>

#include "Result.h"
#include "Text.h"
#include "Observer.h"

class SEOAlgorithm : public IobservableSEO
{
public:
	static SEOAlgorithm* GetSEOAlgorithm();
	SEOResult DoAlgorithm(IText *text);

	void AddObserver(IObserverSEO* obs);
	void RemoveObserver(IObserverSEO* obs);
	void NotifyObservers(SEOResult result);
private:
	vector<IObserverSEO*> observers;
	SEOAlgorithm();
	static SEOAlgorithm* p_instance;
};

class OrtoAlgorithm
{
public:
	static OrtoAlgorithm* GetOrtoAlgorithm();
	OrtoResult DoAlgorithm(IText *text);
private:
	OrtoAlgorithm();
	static OrtoAlgorithm* p_instance;
};
