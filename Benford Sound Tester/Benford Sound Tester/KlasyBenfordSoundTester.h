#include <math.h>
#include <iostream>
#include <vector>

//Funkcja A - Dane
class Dane{
public:

Dane()
{
	tabtab=0;
	
	rozmiar_tab=0;

	
	schowek=0;

	rozmiar_schowka=0;

	start_buf=0;

	end_buf=0;

	error=0;

	error_is=false;

	zakres=false;

	sa_dane=false;

}

~Dane()
{

	UsunBufor();

	UsunSchowek();

}

private:

	double * tabtab; //pocz¹tek tablicy ze zbiorem danych
	long rozmiar_tab; //rozmiar ca³ego zbioru danych
	
	double * schowek; //adres schowka na dane
	long rozmiar_schowka; //rozmiar ca³ego zbioru danych

	long start_buf; //Znacznick pocz¹tku zaznaczenia

	long end_buf; //Znacznik koñca zaznaczenia

	bool schowek_zap; //po

	int error; //Przechowuje numer b³êdu

	long i,j,k,stop; //iteratory

	bool error_is; //true if error is

	bool zakres; //true je¿eli jest ustawiony jakiœ zakres

	bool sa_dane; //true je¿eli jest obszar danych w tablicy

public:

	int TestujZgodnoscChi2(Dane & empir, Dane & teoret, int il_kat, long double & wynik); //A_1_1 TestujZgodnoscChi2

	int TestujMoment1(Dane & empir, Dane & teoret, long double & wynik);

	int GenerujRozkladBenforda(Dane & rozklad, long il_cyfr);										//A_1_4_GenerujRozkladBenforda

	int WezRozklad1Cyfr(int ilosc, Dane & rozklad);			//A_2_7_WyciagnijPierwszeCyfry

	int UstawZakres(long poczatek, long koniec);					//A_2_8_UstawZakres

	int ZmienRozmiar(long rozmiar);			//A2.9Z_mienRozmiar

	int WezAtom(double atom);

	int WezAtom(double atom, long ktory);

	double ZwrocAtom();

	double ZwrocAtom(long ktory);

	int WyslijDane(double * dane);									//A.4_WyslijDane

	int OdbierzDane(double * dane);									//A.5_OdbierzDane

	int	KopiujDaneDoSchowka(void);	//funkcja kopiuj¹ca dane do schowka

	int KopiujDane(double * bufor, long & rozmiark);

	int WytnijDaneDoSchowka(void);

	int WyczyscDane(void);

	int UsunDane(void);

	long WezRozmiar(void);

private:

	int ZarezerwujBufor(long rozmiar);			//A6.1_ZarezerwujBufor
	
	int ZarezerwujBufor(double * bufor, long rozmiar); //A6.2_Rezerwacja bufora innego ni¿ g³ówny bufor danych

	int UsunBufor();					//A6.3_UsunBufor
	
	int UsunSchowek();					//A6.3_UsunBufor
};

//skoñczona i przetestowana jednak trzeba j¹ dodatkowo sprawdziæ
int Dane::TestujZgodnoscChi2(Dane & empir, Dane & teoret, int il_kat, long double & wynik){

	double *emp=0, *teor=0;

	emp=new double[il_kat];
	teor=new double[il_kat];
	empir.UstawZakres(0,il_kat);
	empir.WyslijDane(emp);
	teoret.UstawZakres(0,il_kat);
	teoret.WyslijDane(teor);

	if(il_kat>0)
	{
		double n=0;
		wynik=0;
		double war_buf, teor_buf;
		for(int i=0; i<il_kat; i++)
		{
			if(emp[i]<=0.0)return -1;
			else if(teor[i]<=0.0)return -2;
			else if(teor[i]>=1.0)return -3;
			n=n+emp[i];
		}

		for(int i=0; i<il_kat; i++)
		{
			teor_buf=teor[i]*n;
			war_buf=emp[i]-teor_buf;
			wynik=wynik+((war_buf*war_buf)/teor_buf);
		
		}
		
		return 1;
	
	}else return -4;

}

int Dane::TestujMoment1(Dane & empir, Dane & teoret, long double & wynik)
{
	long double nn=0, kawalek=0, teor=0;
	wynik=0;
	if(empir.rozmiar_tab==teoret.rozmiar_tab)
	{
		for(i=0; i<9; i++){
			nn=nn+empir.ZwrocAtom(i);	
			
		}
		for(i=0; i<9;i++){
			teor=teoret.ZwrocAtom(i)*nn*1.0;
			kawalek=((empir.ZwrocAtom(i)-teor*1.0)/teor*1.0);	
			if(kawalek<0)kawalek=-kawalek;
			wynik=wynik+kawalek;
		}
		wynik=wynik/9.0;
		return 0;
	}else return -1;
}
//do przetestowania!
int Dane::GenerujRozkladBenforda(Dane & rozklad, long il_cyfr)
{

	long end=9;
	if(rozklad.ZmienRozmiar(end));
	else return -1;
	if(rozklad.UstawZakres(0,end));
		else return -2;
	double atom;
	
	for(i=1; i<=end; i++)
	{
		atom=log10(1.0+(1.0/i*1.0));
		if(rozklad.WezAtom(atom,i-1));
		else return -3;
	} return 1; 

}
//do przetestowania!
int Dane::WezRozklad1Cyfr(int ilosc, Dane & rozklad)
{
	double mnor, dziel, bufer, * tab;
	int rozmiarb;
	int cyfra;

	dziel=pow(10.0,ilosc);
	mnor=1.0/dziel;

	rozmiarb=dziel;
	tab=new double[rozmiarb];
	for(i=0;i<rozmiarb; i++)
	{
		tab[i]=0;
	}

	for(i=0;i<rozmiar_tab;i++)
	{
		bufer=tabtab[i];
		if(bufer<0)bufer=-bufer;
		while(bufer>=dziel)bufer=bufer*mnor;
		cyfra=bufer;
		if(cyfra>0)tab[cyfra-1]++;
		else tab[rozmiarb-1]++;
	}

	if(rozklad.ZmienRozmiar(rozmiarb));
	else return -1;
	if(rozklad.UstawZakres(0,rozmiarb));
	else return -1;
	if(rozklad.OdbierzDane(tab));
	else return -3;
	return 1;

}
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
int Dane::ZmienRozmiar(long rozmiar)
{

	//double * tymczas_tab=0; //adres bufora tymczasowego
	if(rozmiar_tab>0)
	{
		
		if(UsunBufor());
		else return -2;

		UstawZakres(0,rozmiar_tab);

	}
	
	if(ZarezerwujBufor(rozmiar))
		{
			rozmiar_tab=rozmiar;
			UstawZakres(0,rozmiar_tab);
			return 1;
		} 
	else return error;
}

int Dane::WezAtom(double atom)
{
	if(zakres==true)
	{
		tabtab[start_buf]=atom;
		if(tabtab!=0)return 1;
	}return -1;

}

int Dane::WezAtom(double atom, long ktory)
{
	UstawZakres(ktory, ktory);
	if(zakres==true)
	{
		tabtab[start_buf]=atom;
		if(tabtab!=0)return 1;
	}return -1;

}

double Dane::ZwrocAtom()
{
	if(zakres==true)
	{
		if(tabtab!=0)return tabtab[start_buf];
		else return -1;

	}return -2;


}

double Dane::ZwrocAtom(long ktory)
{
	if(UstawZakres(ktory, ktory));
	else -1;
	if(zakres==true)
	{
		if(tabtab!=0)return tabtab[start_buf];
		else return -2;

	}return -3;
}

int Dane::WyslijDane(double * dane)
{
	if(zakres==true)
	{
		for(i=start_buf; i<end_buf; i++)
		{
			dane[i]=tabtab[i];
		}
		return 1;

	}return -1;

}

int Dane::OdbierzDane(double * dane)
{

	if(zakres==true)
	{
		for(i=start_buf; i<end_buf; i++)
		{

			tabtab[i]=dane[i];

		}
		return 1;
	}else return -1;
	
	
}

int Dane::KopiujDaneDoSchowka(void)
{
	if(zakres==true)
	{
		if(ZarezerwujBufor(schowek, end_buf-start_buf)>=0)
		{
			for(i=start_buf; i<end_buf; i++)
			{
				schowek[i]=tabtab[i];
			}
			rozmiar_schowka=end_buf-start_buf;
			return 1;
		}else return -1;
	}else return -2;
}

int Dane::KopiujDane(double * bufor, long & rozmiark)
{
	if(zakres==true)
	{
		if(ZarezerwujBufor(bufor, end_buf-start_buf)>=0)
		{
		for(i=start_buf; i<end_buf; i++)
			{
				bufor[i]=tabtab[i];
			}
			rozmiark=end_buf-start_buf;
			return 1;
		}else return -1;

	}
}
//niedokoñczona
int Dane::WytnijDaneDoSchowka(void)
{
/*	if(KopiujDaneDoSchowka()>=0)
	{
		
	
	
	}*/
	return 0;
}
//niedokoñczona
int Dane::UsunDane(void)
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

int Dane::WyczyscDane(void)
{
	if(zakres==true){

		for(i=start_buf; i<end_buf; i++)
		{
			tabtab[i]=0;
		}
		return 1;

	}return -1;

}

int Dane::ZarezerwujBufor(long rozmiar)
	{
		if(tabtab==0){
		
			tabtab=new double[rozmiar];
		
			if(tabtab!=0)
			{
				rozmiar_tab=rozmiar;
			
				return 1;

			}else return -1;
		
		} else return -2;
	}

int Dane::ZarezerwujBufor(double * bufor, long rozmiar)
	{
		if(bufor=new double[rozmiar])
		{
			return 1;
		}else return -1;

	}

int Dane::UsunBufor()
	{
		if(rozmiar_tab>0){
			
			delete [] tabtab;

			rozmiar_tab=0;
			
			tabtab=0;

			zakres=false;

			return 1;

		} else return -1;
	}

int Dane::UsunSchowek()
	{
		if(rozmiar_schowka>0){
			
			delete [] schowek;

			rozmiar_schowka=0;
			
			schowek=0;

			return 1;

		} else return -1;
	}

long Dane::WezRozmiar()
{
	return rozmiar_tab;
}