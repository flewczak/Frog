// Frog.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
/*
#include "DWyswietl.h"
#include "DSamochod.h"
#include "Samochod.h"
#include "Pociag.h"
#include "DPociag.h"
#include "Nieruchome.h"
#include "Drzewo.h"
#include "DDrzewo.h"
#include "Skrzynka.h"
#include "DSkrzynka.h"
#include "Avatar.h"
#include "DAvatar.h"
*/

using namespace std;

//****************************************
//zmienne
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
int CSamochod::samochodyZderzenia=2;

int ile_liczb_w_przedziale = 4;
int startowa_liczba = 0;
int coZaLinia;
int ktoraLinia = 1;
int jakaPredkosc = 0;
int polozenieSkrzynki = 0;
int calkowitaLiczbaWierszy = 10;
int polozenieDrzewa = 0;

int k = 4, petla = 50;
bool skrzynka = 0;


int main(int argc, char * args[])
{
	srand(time(NULL));

	CDWyswietl *ekran = new CDWyswietl(1);
	CAvatar *Avatar = new CAvatar(300,0,30,30);

	CDAvatar *DAvatar = new CDAvatar(ekran, Avatar);
	
	vector <CFigura*> dane;
	vector <CRuchome*> ruchome;
	vector <CNieruchome*> nieruchome;


	vector <CDWyswietl*> Ddane;
	CFigura *fig;
	CRuchome *ruch;
	CNieruchome *nieruch;
	CDWyswietl *Dfig;

	for (int j = 0; j < calkowitaLiczbaWierszy; j++) {
		aaa:
		coZaLinia = (std::rand() % ile_liczb_w_przedziale) + startowa_liczba;
		if (coZaLinia == 2 && skrzynka == 1) {
			goto aaa;
		}
		if (coZaLinia == 0) {
			jakaPredkosc = (std::rand() % 20) + 1;
			for (int i = 0; i < k; i++) {
				ruch = new CSamochod(i * 150, ktoraLinia*30, jakaPredkosc, 0);
				ruchome.push_back(ruch);
				Dfig = new CDSamochod(ekran, ruchome[ruchome.size() - 1]);

				Ddane.push_back(Dfig);
			}
			ktoraLinia++;
		}
		if (coZaLinia == 1) {
			jakaPredkosc = (std::rand() % 20) + 1;
			for (int i = 0; i < k-2; i++) {
				ruch = new CPociag(i * 280, ktoraLinia * 30, jakaPredkosc, 0);
				ruchome.push_back(ruch);
				Dfig = new CDPociag(ekran, ruchome[ruchome.size() - 1]);

				Ddane.push_back(Dfig);
			}
			ktoraLinia++;
		}
		if (coZaLinia == 2) {
			polozenieSkrzynki = (std::rand() % 20) + 1;
			for (int i = 0; i < k-3; i++) {
				nieruch = new CSkrzynka(polozenieSkrzynki * 30, ktoraLinia * 30);
				nieruchome.push_back(nieruch);
				Dfig = new CDSkrzynka(ekran, nieruchome[nieruchome.size() - 1]);

				Ddane.push_back(Dfig);
			}
			skrzynka = 1;
			ktoraLinia++;
		}
		if (coZaLinia == 3) {
			polozenieDrzewa = (std::rand() % 4) + 1;
			polozenieDrzewa = polozenieDrzewa * 30;
			for (int i = 0; i < k-1; i++) {
				nieruch = new CDrzewo(polozenieDrzewa, ktoraLinia * 30);
				nieruchome.push_back(nieruch);
				Dfig = new CDDrzewo(ekran, nieruchome[nieruchome.size() - 1]);

				polozenieDrzewa = polozenieDrzewa + 180;

				Ddane.push_back(Dfig);
			}
			ktoraLinia++;
		}
	}

	while(1)
	{
		ekran->CDWyswietl::start();

		for (int i = 0; i < ruchome.size(); i++)
		{
			ruchome[i]->przesun();
			
			ruchome[i]->zderzenie(Avatar);
			Avatar->przesun();

			if (Avatar->zwrocZycie() <= 0) {
				break;
			}
			if (Avatar->koniecGry() == 0) {
				break;
			}
		}
		for (int i = 0; i < nieruchome.size(); i++) {
			nieruchome[i]->zderzenie(Avatar);
		}
		for (int i = 0; i < Ddane.size(); i++) {
			Ddane[i]->rysuj(ekran);
		}

		if (Avatar->zwrocZycie() <= 0) {
			break;
		}
		if (Avatar->koniecGry() == 0) {
			break;
		}
		Avatar->przesun();
		DAvatar->rysuj(ekran);
		SDL_Delay(300);
	}
		
	ekran->CDWyswietl::start();

	delete ekran;
	dane.clear();
	nieruchome.clear();
	ruchome.clear();
	Ddane.clear();

	return 0;
}



