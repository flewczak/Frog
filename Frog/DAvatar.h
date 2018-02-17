#pragma once
#include "DWyswietl.h"
class CDAvatar :
	public CDWyswietl
{
public:
	CDAvatar();
	~CDAvatar();
	CDAvatar(CDWyswietl * ekran, CFigura * avatar);
	void CDAvatar::rysuj(CDWyswietl *ekran);
};

