#pragma warning(disable : 4996)
//***************************************************
// Program z paragrafu   21.18 (str 654)
//***************************************************

          // dla exit()
////////////////////////////////////////////////////////
class duza_tablica {                                      //
      char *nazwa_pliku;       // nazwa pliku dyskowego
      FILE * plik;

      long rozmiar ;

      double * podobszar ;          // linijka w zapasie pamieci
      long dlug_podobszaru ;
      long nr_obecnego ;          // nr wiersza nad kt¢rym pracujemy
public:
       duza_tablica(char *nazwa_pliku, long wym, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, int wypelniacz = 0){
			duza_tablica(nazwa_pliku, wym, wypelniacz);
	   }
	   ~duza_tablica() ;

       double odczytaj(long nr_chcianego) ;
	   void zapisz(double element, long nr_chcianego);
	   void zapiszblok(double * blok, long nr_bloku, long brozmiar);
private:
       void error();
} ;
/*******************************************************/
duza_tablica::duza_tablica(char *nazwa, long wym, int wypelniacz) : rozmiar(wym)              //
{
     plik=fopen(nazwa, "w+") ;

     nazwa_pliku = nazwa ;                               //

     if(!plik){
          error() ;
     }
	 podobszar = 0;
     podobszar = new double[rozmiar] ;                  //
     dlug_podobszaru = rozmiar * sizeof(double);

     // ------------------------- wstepne wypelnienie
	 for(int i=0; i<rozmiar; i++)
	 {
		podobszar[i]=wypelniacz;
	 }

     // -----------------------zapis tego do pliku
     fwrite(podobszar, sizeof(double), rozmiar, plik ) ;
                                                       //

     if(!plik){

          error();
     }
     nr_obecnego = 0 ;
}
/*******************************************************/
duza_tablica::~duza_tablica()      //
{


     fclose(plik);        // zamkniecie pliku
     delete [] podobszar ;     // zwolnienie rezerwacji
	 remove(nazwa_pliku);
}

double duza_tablica::odczytaj(long nr_chcianego)
{                                                      //
	double chciany;

     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
			chciany = podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
           return chciany;    // nic nie trzeba robic !
     }else{

	 nr_obecnego = nr_chcianego/rozmiar ;

     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(double),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(double), rozmiar, plik) ){
     
          error();
     }

     // uaktualnienie notatek

     // zwracamy wskaznik do tablicy roboczej
	 chciany = podobszar[nr_chcianego-(nr_obecnego*rozmiar)];
     return chciany;
	 }
}
void duza_tablica::zapisz(double element, long nr_chcianego){
			   
	if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           podobszar[nr_chcianego-(nr_obecnego*rozmiar)]=element ;    // nic nie trzeba robic !
     }else{
	
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(double),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, sizeof(double) , rozmiar, plik) ){
          error();
     }
  
	 nr_obecnego = nr_chcianego/rozmiar ; 
	
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(double),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(double), rozmiar, plik) ){
     
          error();
     }
     // uaktualnienie notatek
	 podobszar[nr_chcianego-(nr_obecnego*rozmiar)]=element ;
	
	}
     // zwracamy wskaznik do tablicy roboczej
     
}
void duza_tablica::zapiszblok(double * blok, long nr_bloku, long brozmiar){

   
     if(!fseek(plik,nr_bloku * brozmiar * sizeof(double),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, sizeof(double) , brozmiar, plik) ){
          error();
	 }

	 if(!fseek(plik, rozmiar*nr_obecnego,SEEK_SET)) {
          error();
     }

	 if(!fread(podobszar, sizeof(double), rozmiar, plik) ){
     
          error();
     }
	 
}
/*******************************************************/
void duza_tablica::error()
{
    /* if(plik.eof())  cout << "Koniec pliku " ;
     if(plik.fail())
          cout << " -FAIL strumienia do pliku : "
                << nazwa_pliku << endl ;
     exit(1);*/
}

//***************************************************
// Program z paragrafu   21.18 (str 654)
//***************************************************

          // dla exit()
////////////////////////////////////////////////////////

class duza_tablicachar {                                                        //
      char *nazwa_pliku;       // nazwa pliku dyskowego
      FILE * plik;

      long rozmiar ;

      char * podobszar ;          // linijka w zapasie pamieci
      long dlug_podobszaru ;
      long nr_obecnego ;          // nr wiersza nad kt¢rym pracujemy
public:
      duza_tablicachar(char *nazwa_pliku, long wym, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, int wypelniacz = 0){
			duza_tablicachar(nazwa_pliku, wym, wypelniacz);
	   }
	   ~duza_tablicachar() ;

       char odczytaj(long nr_chcianego) ;
	   void zapisz(char element, long nr_chcianego);
	   void zapiszblok(char * blok, long nr_bloku, long brozmiar);
private:
       void error();
} ;
/*******************************************************/
duza_tablicachar::duza_tablicachar(char *nazwa, long wym, int wypelniacz) : rozmiar(wym)              //
{
     plik=fopen(nazwa, "w+") ;

     nazwa_pliku = nazwa ;                               //

     if(!plik){
          error() ;
     }
	 podobszar = 0;
     podobszar = new char[rozmiar] ;                  //
     dlug_podobszaru = rozmiar * sizeof(char);

     // ------------------------- wstepne wypelnienie
	 for(int i=0; i<rozmiar; i++)
	 {
		podobszar[i]=wypelniacz;
	 }

     // -----------------------zapis tego do pliku
     fwrite(podobszar, sizeof(char), rozmiar, plik ) ;
                                                       //

     if(!plik){

          error();
     }
     nr_obecnego = 0 ;
}
/*******************************************************/
duza_tablicachar::~duza_tablicachar()      //
{


     fclose(plik);        // zamkniecie pliku
     delete [] podobszar ;     // zwolnienie rezerwacji
	 remove(nazwa_pliku);
}

char duza_tablicachar::odczytaj(long nr_chcianego)
{                                                      //
	char chciany;

     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
			chciany = podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
           return chciany;    // nic nie trzeba robic !
     }else{

	 nr_obecnego = nr_chcianego/rozmiar ;

     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(char),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(char), rozmiar, plik) ){
     
          error();
     }

     // uaktualnienie notatek

     // zwracamy wskaznik do tablicy roboczej
	 chciany = podobszar[nr_chcianego-(nr_obecnego*rozmiar)];
     return chciany;
	 }
}
void duza_tablicachar::zapisz(char element, long nr_chcianego){
			   
	if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           podobszar[nr_chcianego-(nr_obecnego*rozmiar)]=element ;    // nic nie trzeba robic !
     }else{
	
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(char),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, sizeof(char) , rozmiar, plik) ){
          error();
     }
  
	 nr_obecnego = nr_chcianego/rozmiar ; 
	
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(char),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(char), rozmiar, plik) ){
     
          error();
     }
     // uaktualnienie notatek
	 podobszar[nr_chcianego-(nr_obecnego*rozmiar)]=element ;
	
	}
     // zwracamy wskaznik do tablicy roboczej
     
}
void duza_tablicachar::zapiszblok(char * blok, long nr_bloku, long brozmiar){

   
     if(!fseek(plik,nr_bloku * brozmiar * sizeof(char),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, sizeof(char) , brozmiar, plik) ){
          error();
	 }

	 if(!fseek(plik, rozmiar*nr_obecnego,SEEK_SET)) {
          error();
     }

	 if(!fread(podobszar, sizeof(char), rozmiar, plik) ){
     
          error();
     }
	 
}
/*******************************************************/
void duza_tablicachar::error()
{
    /* if(plik.eof())  cout << "Koniec pliku " ;
     if(plik.fail())
          cout << " -FAIL strumienia do pliku : "
                << nazwa_pliku << endl ;
     exit(1);*/
}

//***************************************************
// Program z paragrafu   21.18 (str 654)
//***************************************************

          // dla exit()
////////////////////////////////////////////////////////

/*******************************************************
main()                                               //
{
int i, k;
const int wymiar = 50 ;
duza_tablica t("macierz.tmp", wymiar) ;                //


     // wpisanie jakichs danych do tablicy t
     for(i = 0 ; i < wymiar ; i++)
          for(k = 0 ; k < wymiar ; k++)
                    t[i][k] = i * 100 + k ;                 //

     cout << "Element t [24][7] ma wartosc = "
          << t [24][7] << endl ;                       //

     // -------------------------------------------
     cout << "Przykladowo robimy transpozycje " <<endl ;

     duza_tablica m("macierz1.tmp", wymiar) ;          //
     for(i = 0 ; i < wymiar ; i++)
          for(k = 0 ; k < wymiar ; k++)
               m[i][k] = t[k][i] ;                     //

     cout << "transpozycja skonczona, oto rezultat\n"
               "Przykladowo elementy t[7][31] = " << t[7][31]
          << ", \tt[31][7] = " << t[31][7] << endl ;

     cout << "  Natomiast elementy m[7][31] = " << m[7][31]
          << ", \tm[31][7] = " << m[31][7] << endl ;
}
*/
//***************************************************
// Program z paragrafu   21.18 (str 654)
//***************************************************

          // dla exit()
////////////////////////////////////////////////////////

class duza_tablicashort {                                      //
      char *nazwa_pliku;       // nazwa pliku dyskowego
      FILE * plik;

      long rozmiar ;

      short * podobszar ;          // linijka w zapasie pamieci
      long dlug_podobszaru ;
      long nr_obecnego ;          // nr wiersza nad kt¢rym pracujemy
public:
       duza_tablicashort(char *nazwa_pliku, long wym, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, int wypelniacz = 0){
			duza_tablica(nazwa_pliku, wym, wypelniacz);
	   }
	   ~duza_tablicashort() ;

       short odczytaj(long nr_chcianego) ;
	   void zapisz(short element, long nr_chcianego);
	   void zapiszblok(short * blok, long nr_bloku);
private:
       void error();
} ;
/*******************************************************/
duza_tablicashort::duza_tablicashort(char *nazwa, long wym, int wypelniacz)             //
{
    rozmiar = wym; 
	
	podobszar = NULL;
	plik=fopen(nazwa, "w+") ;
	 
     nazwa_pliku = nazwa ;                               //

     if(!plik){
          error() ;
     }

     podobszar = new short[rozmiar] ;//
	 for(long i = 0 ; i < rozmiar ; i++){
		podobszar[i] = wypelniacz;
	 }
     dlug_podobszaru = rozmiar * sizeof(short);

     // ------------------------- wstepne wypelnienie
    

     // -----------------------zapis tego do pliku
     fwrite(podobszar, sizeof(short), rozmiar, plik ) ;
                                                       //

     if(!plik){

          error();
     }
     nr_obecnego = 0 ;
}
/*******************************************************/
duza_tablicashort::~duza_tablicashort()      //
{
     // skoro koniec to musimy odeslac na dysk wiersz
     // kt¢ry jest jeszcze w tablicy linijka

     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(short),SEEK_SET)) {
          error();
     }
     // zapisanie tam ---------
     if(!fwrite(podobszar , sizeof(short), rozmiar, plik) ){
      
          error();
     }

     fclose(plik);        // zamkniecie pliku
     delete podobszar ;     // zwolnienie rezerwacji
}
/*******************************************************/
// przeladowanie operatora []
/*******************************************************/
short duza_tablicashort::odczytaj(long nr_chcianego)
{                                                      //

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;    // nic nie trzeba robic !
     }else{

     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(short),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, sizeof(short) , rozmiar, plik) ){
          error();
     }
     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest
	 nr_obecnego = nr_chcianego/rozmiar ;
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(short),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(short), rozmiar, plik) ){
     
          error();
     }
	 return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
     // uaktualnienie notatek
	 }

     // zwracamy wskaznik do tablicy roboczej
    
}
void duza_tablicashort::zapisz(short element, long nr_chcianego){

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
			   
	if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           podobszar[nr_chcianego-(nr_obecnego*rozmiar)]=element ;    // nic nie trzeba robic !
     }
	if(nr_chcianego<=nr_obecnego*rozmiar+rozmiar && nr_chcianego>=nr_obecnego*rozmiar);
	else {
     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(short),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, sizeof(short) , rozmiar, plik) ){
          error();
     }

     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest
	 nr_obecnego = nr_chcianego/rozmiar ;      
     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(short),SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, sizeof(short), rozmiar, plik) ){
     
          error();
     }
	 }
     // uaktualnienie notatek

	
     // zwracamy wskaznik do tablicy roboczej
     //return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
}
void duza_tablicashort::zapiszblok(short * blok, long nr_bloku){

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
			   
	
     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_bloku * rozmiar * sizeof(short),SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, sizeof(short) , rozmiar, plik) ){
          error();
     }
	 for ( long i = 0 ; i < rozmiar ; i ++){
		podobszar[i] = blok[i];
	 }
	 nr_obecnego = nr_bloku ;      
}
/*******************************************************/
void duza_tablicashort::error()
{
    /* if(plik.eof())  cout << "Koniec pliku " ;
     if(plik.fail())
          cout << " -FAIL strumienia do pliku : "
                << nazwa_pliku << endl ;
     exit(1);*/
}
