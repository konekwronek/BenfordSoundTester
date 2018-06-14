#include <math.h>

#include <iostream>
#include <vector>
//#include "KlasaPlik.h"
#include "tablica2.h"


//Funkcja A - Dane
class Dane{
public:

Dane()
{		
	//tabtab = 0;

	rozmiar_tab=0;
	
	rozmiar_schowka=0;

	schowek=0;

	start_buf=0;

	end_buf=0;

	zakres=false;
		
	error=0;

	error_is=false;

	sample_rate=0;
	
}


~Dane()
{

//	UsunBufor();

//	UsunSchowek();

}


private:

	
	std::vector<long> tabtab;	 //pocz¹tek tablicy ze zbiorem danych
	
	char nazwap[20][20];
	long * schowek; //adres schowka na dane
	long rozmiar_schowka; //rozmiar ca³ego zbioru danych
	long long rozmiar_tab; //rozmiar ca³ego zbioru danych
	long start_buf; //Znacznick pocz¹tku zaznaczenia

	long end_buf; //Znacznik koñca zaznaczenia

	bool schowek_zap; //po

	int error; //Przechowuje numer b³êdu

	long long i,j,k,stop; //iteratory

	bool error_is; //true if error is

	bool zakres; //true je¿eli jest ustawiony jakiœ zakres

	bool sa_dane; //true je¿eli jest obszar danych w tablicy

	long sample_rate;

public:


	int UstawZakres(long poczatek, long koniec);					//A_2_8_UstawZakres

	int ZmienRozmiar(long long rozmiar);			//A2.9Z_mienRozmiar

	int WezAtom(long atom, long long ktory);

	long ZwrocAtom(long long ktory);

	int WyslijDane(long * dane);									//A.4_WyslijDane

	int OdbierzDane(long * dane);									//A.5_OdbierzDane

	int	KopiujDaneDoSchowka();	//funkcja kopiuj¹ca dane do schowka

	int KopiujDane(long * bufor, long & rozmiark);
	
	int KopiujDane(Dane * zrodlo,  Dane * cel);

	int WytnijDaneDoSchowka();

	int WyczyscDane();

	int UsunDane();

	long WezRozmiar();

	int UstawSampleRate(long rate){
		if(rate>0)sample_rate=rate;
		return 1;
	}

	int UsunBufor();					//A6.3_UsunBufor

private:
	
	//int ZarezerwujBufor(double * bufor, long rozmiar); //A6.2_Rezerwacja bufora innego ni¿ g³ówny bufor danych

	
	int UsunSchowek();					//A6.3_UsunBufor
};

//skoñczona i przetestowana jednak trzeba j¹ dodatkowo sprawdziæ

//skoñczona (wszystko OK)!
int Dane::UstawZakres(long poczatek, long koniec)
{
	if(poczatek>=0 && koniec>=0 && poczatek<=koniec && koniec<=rozmiar_tab)
	{

		start_buf=poczatek;
		end_buf=koniec;
		zakres=true;
		return 1;

	}
	else
	{
		zakres=false;	
		return -1;	
	}
}
//Mo¿na j¹ póŸniej poprawiæ
int Dane::ZmienRozmiar(long long rozmiar)
{ 
	rozmiar_tab = rozmiar;
		
	tabtab.resize(rozmiar);
	//	if(tabtab != 0){
			for(i = 0 ; i < rozmiar; i++)
			{
				tabtab[i] = 0;
			}
			UstawZakres(0, rozmiar);
			return 1;
//		}else return -1;

}


int Dane::WezAtom(long atom, long long ktory)
{
	if(ktory>=0 && ktory<rozmiar_tab)
	{
		tabtab[ktory] = atom;
		return 1;
	}return -1;

}


long Dane::ZwrocAtom(long long ktory)
{
	if(ktory >= 0 && ktory<rozmiar_tab){
		return tabtab[ktory];
	}else return -1999;
}

int Dane::WyslijDane(long * dane)
{
	if(zakres == true)
	{
		for(i = start_buf; i < end_buf; i++)
		{
			dane[i] = this->ZwrocAtom(i);
		}
		return 1;

	}return -1;

}

int Dane::OdbierzDane(long * dane)
{

	if(zakres==true)
	{
		for(i=start_buf; i<end_buf; i++)
		{

			if(this->WezAtom(dane[i],i)==1);
			else return -2;
		}
		return 1;
	}else return -1;
	
	
}


int Dane::KopiujDane(long * bufor, long & rozmiark)
{
	if(zakres==true)
	{
		//if(ZarezerwujBufor(bufor, end_buf-start_buf)>=0)
		{
		for(i=start_buf; i<end_buf; i++)
			{
				bufor[i]=tabtab[i];
			}
			rozmiark=end_buf-start_buf;
			return 1;
		} return -1;

	}
}
//niedokoñczona
int Dane::KopiujDane(Dane * zrodlo, Dane * cel){
	long rozmiar;
	rozmiar=zrodlo->WezRozmiar();
	if(cel->ZmienRozmiar(rozmiar)>0){
	cel->UstawZakres(0, rozmiar);
	for(long i=0; i<rozmiar; i++){
		cel->WezAtom(zrodlo->ZwrocAtom(i),i);
	}
	return 1;
	} return -1;
}
int Dane::WytnijDaneDoSchowka()
{
/*	if(KopiujDaneDoSchowka()>=0)
	{
		
	
	
	}*/
	return 0;
}
//niedokoñczona
int Dane::UsunDane()
{
	/*if(sa_dane==true)
	{
		if(zakres==false)
		{
		
			if(UsunBufor()>=0) return 1;
			else return -2;
		}else{
		
			
		
		}
	
	
	}else return -1;
	*/
	return 0;
}

int Dane::WyczyscDane()
{
	if(zakres==true){

		for(i=start_buf; i<end_buf; i++)
		{
			this->WezAtom(0,i);
		}
		return 1;

	}return -1;

}

/*int Dane::ZarezerwujBufor(double * bufor, long rozmiar)
	{
		if(bufor=new double[rozmiar])
		{
			return 1;
		}else return -1;

	}
	*/
int Dane::UsunBufor()
	{
		if(rozmiar_tab>0){
			
			tabtab.resize(0);

			rozmiar_tab=0;
			
	//		tabtab=0;

			zakres=false;

			return 1;

		} else return -1;
	}
/*
int Dane::UsunSchowek()
	{
		if(rozmiar_schowka>0){
			
			delete [] schowek;

			rozmiar_schowka=0;
			
			schowek=0;

			return 1;

		} else return -1;
	}
	*/
long Dane::WezRozmiar()
{
	return rozmiar_tab;
}