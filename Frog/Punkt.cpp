#include "stdafx.h"
#include "Punkt.h"


CPunkt::CPunkt()
{
}

CPunkt::CPunkt(int x, int y)
{
	_x = x;
	_y = y;

}

void CPunkt::wpiszWspolrzedne(int x, int y)
{
	_x = x;
	_y = y;
}

int CPunkt::dajX()
{
	return _x;
}

int CPunkt::dajY()
{
	return _y;
}

CPunkt::~CPunkt()
{
}

void CPunkt::wyswietle(std::fstream &plik)
{
	plik << _x << "  " << _y << std::endl;
}



