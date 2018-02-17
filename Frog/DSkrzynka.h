#pragma once
#include "DWyswietl.h"
class CDSkrzynka :
	public CDWyswietl
{
public:
	CDSkrzynka();
	~CDSkrzynka();
	CDSkrzynka(CDWyswietl * ekran, CFigura * skrzynka);
	void CDSkrzynka::rysuj(CDWyswietl *ekran);
};

