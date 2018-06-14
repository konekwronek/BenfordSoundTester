#include "KlasaPlik.h"

class Tester{
private:

	long i,j,k,stop; //iteratory

public:

	int TestujZgodnoscChi2(Dane & empir, double * teoret, int il_kat, long double & wynik); //A_1_1 TestujZgodnoscChi2

	int TestujZgodnoscCyfryChi2(Dane & empir, double * teoret, int il_kat, int cyfra, long double & wynik); //A_1_1 TestujZgodnoscCyfryChi2

	int TestujMiernik1(Dane & empir, double * teoret, long double & wynik);

	int GenerujRozkladBenforda(double * rozklad, long il_cyfr);										//A_1_4_GenerujRozkladBenforda

	int WezRozklad1Cyfr(int ilosc, Dane & dane, Dane & rozklad);			//A_2_7_WyciagnijPierwszeCyfry

	int Srednia(Dane & dane, long double & srednia);

	int Wariancja(Dane & dane, long double srednia, long double & wariancja);

	int GestoscRozkladuNormalnego(long double x, long double srednia, long double odchstd, long double & plevel);

};

int Tester::TestujZgodnoscChi2(Dane & empir, double * teoret, int il_kat, long double & wynik){


	if(il_kat>0)
	{
		double n=0;
		wynik=0;
		double war_buf, teor_buf;
		for(int i=0; i<il_kat; i++)
		{
			n=n+empir.ZwrocAtom(i);
	
		}

		for(int i=0; i<il_kat; i++)
		{
			teor_buf=teoret[i]*n*1.0;
			war_buf=empir.ZwrocAtom(i)-teor_buf;
			wynik=wynik+((war_buf*war_buf*1.0)/teor_buf);
		}
		
		return 1;
	
	}else return -1;

}

int Tester::TestujZgodnoscCyfryChi2(Dane & empir, double * teoret, int il_kat, int cyfra, long double & wynik)
{
	long n = 0;

	for(int i = 0; i<il_kat; i++)
	{
		n = n + empir.ZwrocAtom(i);
	}
	long emp = empir.ZwrocAtom(cyfra - 1);
	if(n > 0){
		long double upper = (double(empir.ZwrocAtom(cyfra - 1)) / n * 1.0) - teoret[cyfra - 1];
		long double down = (teoret[cyfra - 1] * (1.0 - teoret[cyfra - 1])) / n * 1.0;
		down = sqrt(down);
		wynik = upper / down;
		return 1;
	}else return -1;
	
}

int Tester::TestujMiernik1(Dane & empir, double * teoret, long double & wynik)
{
	long double n=0, kawalek=0, teor=0, empi=0;
	wynik=0;
	
		for(i=0; i<9; i++){
			n=n+empir.ZwrocAtom(i);	
			
		}
		for(i=0; i<9;i++){
			teor=teoret[i]*n*1.0;
			kawalek=(empir.ZwrocAtom(i)-teor*1.0)/teor*1.0;	
			if(kawalek<0)kawalek=-kawalek;
			wynik=wynik+kawalek;
			
		}
		wynik=wynik/9.0;
		//wynik=sqrt(wynik);
		return 1;
	
}
//do przetestowania!
int Tester::GenerujRozkladBenforda(double * rozklad, long il_cyfr)
{
	long atom;
	
	for(i=1; i<=il_cyfr; i++)
	{
		rozklad[i-1]=log10(1.0+(1.0/i*1.0));
	} return 1; 

}
//do przetestowania!
int Tester::WezRozklad1Cyfr(int ilosc, Dane & dane, Dane & rozklad)
{
	double dziel;
	long	bufer;
	long * tab;
	
	int rozmiarb, ktorydzielnik, ok;
	int cyfra;
	double wynik;

	dziel=pow(10.0,ilosc);
	rozmiarb=dziel;
	tab = new long[rozmiarb];
	if(tab != 0){
		for(i=0;i<rozmiarb; i++)
		{
			tab[i]=0;
		}

	
		for(long i=0;i<dane.WezRozmiar();i++)
		{	
			bufer=dane.ZwrocAtom(i);
			if(bufer != 0){

				if(bufer<0)bufer=-bufer;
				while(bufer >= rozmiarb) bufer = bufer / rozmiarb;
				tab[bufer-1]++;

			}else tab[rozmiarb-1]++;
		
		}

		if(rozklad.ZmienRozmiar(rozmiarb));
		else return -1;
		
		{
			bufer=0;
			for(int i=0;i<9;i++)
			{
				rozklad.WezAtom(tab[i], i);
				bufer = bufer + rozklad.ZwrocAtom(i);
			
			}
			rozklad.WezAtom(bufer, 9);
		}
		return 1;
	}
	else return -3;
	

}

int Tester::Srednia(Dane & dane, long double & srednia)
{
	long n = dane.WezRozmiar();
	if(n > 0)
	{
		srednia = 0;
		for(int i = 0; i < n; i++)
		{
			srednia = srednia + dane.ZwrocAtom(i);
		}
		srednia = srednia / n * 1.0;
		return 1;
	}else return -1;
}

int Tester::Wariancja(Dane & dane, long double srednia, long double & wariancja)
{
	long n = dane.WezRozmiar();
	long double odchylenie;
	wariancja = 0;
	if(n > 0)
	{
		for(int i = 0; i < n; i++)
		{
			odchylenie = dane.ZwrocAtom(i) - srednia;
			wariancja = wariancja + (odchylenie * odchylenie);
		}
		return 1;
	}else return -1;
}

int Tester::GestoscRozkladuNormalnego(long double x, long double srednia, long double odchstd, long double & plevel)
{
	long double res1, res2;
	long double PI = 3.14159265358979323846;
	if(odchstd > 0)
	{
		res1 = 1.0 / (sqrt(2.0 * PI));
		res2 = - (x * x) / 2.0;
		plevel = res1 * Math::Pow(Math::E, res2);
		return 1;
	} else return -1;
}