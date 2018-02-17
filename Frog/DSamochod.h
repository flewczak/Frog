#pragma once
#include "DWyswietl.h"
#include "Samochod.h"
#include "Figura.h"

class CDSamochod
	:public CDWyswietl

{

public:
	CDSamochod();
	CDSamochod(CDWyswietl *ekran, CFigura *samochod);
	~CDSamochod();
	void CDSamochod::rysuj(CDWyswietl *ekran);
};

