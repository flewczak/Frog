#pragma once
#include "DWyswietl.h"
#include "Pociag.h"
class CDPociag :
	public CDWyswietl
{
public:
	CDPociag();
	~CDPociag();
	CDPociag(CDWyswietl * ekran, CFigura * pociag);
	void CDPociag::rysuj(CDWyswietl *ekran);
};

