#pragma once
#include "Ruchome.h"
class CAvatar :
	public CRuchome
{
private:
	int _zycie;
	int _poprzX;
	int _poprzY;
	bool _koniec;
	int _szer;
	int _wys;
public:
	CAvatar();
	~CAvatar();
	CAvatar(int x, int y, int predX, int predY);
	int dajSzer();
	int dajWys();
	void przesun();
	int gdzieX();
	int gdzieY();
	bool zderzenie( CFigura *Figura);
	void zmienZycie(bool zycie);
	int zwrocZycie();
	int dajPoprzX();
	int dajPoprzY();
	bool koniecGry();

};

