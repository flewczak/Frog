#pragma once
class CFigura
{
protected:
	CPunkt *_Punkt;
public:
	CFigura();
	CFigura(int x, int y);
	virtual ~CFigura();
	
	virtual int gdzieX()=0;
	virtual int gdzieY()=0;
	virtual bool zderzenie(CFigura *Figura)=0;
	void wpiszWspPunktu(int x, int y);
	
};

