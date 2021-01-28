#pragma once
#include "Result.h"

//Наблюдатель
class IObserverSEO
{
public:
	virtual void update(SEOResult result) = 0;
};

class IobservableSEO
{
public:
	virtual void AddObserver(IObserverSEO* obs) = 0;
	virtual void RemoveObserver(IObserverSEO* obs) = 0;
	virtual void NotifyObservers(SEOResult result) = 0;
};

