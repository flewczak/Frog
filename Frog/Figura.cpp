#include "stdafx.h"
#include "Punkt.h"
#include "Figura.h"



CFigura::CFigura()
{
	CPunkt *Punkt = new CPunkt(0,0);
	_Punkt = Punkt;
}

CFigura::CFigura(int x, int y)
{
	CPunkt *Punkt = new CPunkt(x, y);
	_Punkt = Punkt;
}



CFigura::~CFigura()
{
	CPunkt *punkt=_Punkt;
	delete punkt;
}


void CFigura::wpiszWspPunktu(int x, int y)
{
	_Punkt->wpiszWspolrzedne(x, y);
}




