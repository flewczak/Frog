#include "stdafx.h"
#include "Ruchome.h"


CRuchome::CRuchome()
{
	_predkoscX = 0;
	_predkoscY = 0;
}


CRuchome::~CRuchome()
{
}




void CRuchome::zmianaPredkosci(int predX, int predY)
{
	_predkoscX = predX;
	_predkoscY = predY;
	
}

