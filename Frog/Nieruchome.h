#pragma once
#include "Figura.h"
class CNieruchome :
	public CFigura
{
public:
	CNieruchome();
	virtual ~CNieruchome();

	virtual int gdzieX() = 0;
	virtual int gdzieY() = 0;
	virtual bool zderzenie(CFigura *Figura) = 0;
};

