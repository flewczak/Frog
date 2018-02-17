#pragma once
#include "DWyswietl.h"
class CDDrzewo :
	public CDWyswietl
{
public:
	CDDrzewo();
	~CDDrzewo();
	CDDrzewo(CDWyswietl * ekran, CFigura * drzewo);
	void CDDrzewo::rysuj(CDWyswietl *ekran);
};

