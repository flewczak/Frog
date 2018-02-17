#pragma once
#include "Figura.h"
class CRuchome :
	public CFigura
{
protected:
	int _predkoscX;
	int _predkoscY;

public:
	CRuchome();
	virtual ~CRuchome();
	virtual void zmianaPredkosci(int predX, int predY);
	virtual int gdzieX()=0;
	virtual int gdzieY()=0;
	virtual void przesun()=0;
	virtual bool zderzenie(CFigura *Figura)=0;

};

