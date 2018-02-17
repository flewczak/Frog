#pragma once


class CPunkt 
{
private:
	int _x;
	int _y;
public:
	CPunkt();
	CPunkt(int x, int y);
	void wpiszWspolrzedne(int x, int y);
	int dajX();
	int dajY();
	virtual ~CPunkt();
	void wyswietle(std::fstream &plik);
};

