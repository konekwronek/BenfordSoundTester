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
       duza_tablica(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0){
			duza_tablica(nazwa_pliku, wym, rozm, wypelniacz);
	   }
	   ~duza_tablica() ;

       double & odczytaj(long nr_chcianego) ;
	   void zapisz(double element, long nr_chcianego);
	   void zapiszblok(double * blok, long nr_bloku);
private:
       void error();
} ;
/*******************************************************/
duza_tablica::duza_tablica(char *nazwa, long wym, long rozm, int wypelniacz) : rozmiar(wym)              //
{
     plik=fopen(nazwa, "w+") ;

     nazwa_pliku = nazwa ;                               //

     if(!plik){
          error() ;
     }

     podobszar = new double[rozmiar] ;                  //
     dlug_podobszaru = rozmiar * sizeof(double);

     // ------------------------- wstepne wypelnienie
    

     // -----------------------zapis tego do pliku
     fwrite(podobszar, 1, rozmiar, plik ) ;
                                                       //

     if(!plik){

          error();
     }
     nr_obecnego = 0 ;
}
/*******************************************************/
duza_tablica::~duza_tablica()      //
{
     // skoro koniec to musimy odeslac na dysk wiersz
     // kt¢ry jest jeszcze w tablicy linijka

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam ---------
     if(!fwrite(podobszar , 1, rozmiar, plik) ){
      
          error();
     }

     fclose(plik);        // zamkniecie pliku
     delete podobszar ;     // zwolnienie rezerwacji
	 remove(nazwa_pliku);
}
/*******************************************************/
// przeladowanie operatora []
/*******************************************************/
double & duza_tablica::odczytaj(long nr_chcianego)
{                                                      //

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;    // nic nie trzeba robic !
     }

     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, 1 , rozmiar, plik) ){
          error();
     }
     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, 1, rozmiar, plik) ){
     
          error();
     }

     // uaktualnienie notatek
     nr_obecnego = nr_chcianego/rozmiar ;

     // zwracamy wskaznik do tablicy roboczej
     return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
}
void duza_tablica::zapisz(double element, long nr_chcianego){

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
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, 1 , rozmiar, plik) ){
          error();
     }
     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, 1, rozmiar, plik) ){
     
          error();
     }
	 }
     // uaktualnienie notatek

	nr_obecnego = nr_chcianego/rozmiar ;      
     // zwracamy wskaznik do tablicy roboczej
     //return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
}
void duza_tablica::zapiszblok(double * blok, long nr_bloku){

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
			   
	
     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_bloku * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, 1 , rozmiar, plik) ){
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

class duza_tablicachar {                                      //
      char *nazwa_pliku;       // nazwa pliku dyskowego
      FILE * plik;

      long rozmiar ;

      char * podobszar ;          // linijka w zapasie pamieci
      long dlug_podobszaru ;
      long nr_obecnego ;          // nr wiersza nad kt¢rym pracujemy
public:
       duza_tablicachar(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0){
			duza_tablica(nazwa_pliku, wym, rozm, wypelniacz);
	   }
	   ~duza_tablicachar() ;

       char & odczytaj(long nr_chcianego) ;
	   void zapisz(char element, long nr_chcianego);
	   void zapiszblok(char * blok, long nr_bloku);
private:
       void error();
} ;
/*******************************************************/
duza_tablicachar::duza_tablicachar(char *nazwa, long wym, long rozm, int wypelniacz)             //
{
    rozmiar = wym; 
	
	podobszar = NULL;
	plik=fopen(nazwa, "w+") ;
	 
     nazwa_pliku = nazwa ;                               //

     if(!plik){
          error() ;
     }

     podobszar = new char[rozmiar] ;//
	 for(long i = 0 ; i < rozmiar ; i++){
		podobszar[i] = wypelniacz;
	 }
     dlug_podobszaru = rozmiar * sizeof(char);

     // ------------------------- wstepne wypelnienie
    

     // -----------------------zapis tego do pliku
     fwrite(podobszar, 1, rozmiar, plik ) ;
                                                       //

     if(!plik){

          error();
     }
     nr_obecnego = 0 ;
}
/*******************************************************/
duza_tablicachar::~duza_tablicachar()      //
{
     // skoro koniec to musimy odeslac na dysk wiersz
     // kt¢ry jest jeszcze w tablicy linijka

     if(!fseek(plik,nr_obecnego * rozmiar * sizeof(char),SEEK_SET)) {
          error();
     }
     // zapisanie tam ---------
     if(!fwrite(podobszar , sizeof(char), rozmiar, plik) ){
      
          error();
     }

     fclose(plik);        // zamkniecie pliku
     delete podobszar ;     // zwolnienie rezerwacji
}
/*******************************************************/
// przeladowanie operatora []
/*******************************************************/
char & duza_tablicachar::odczytaj(long nr_chcianego)
{                                                      //

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;    // nic nie trzeba robic !
     }

     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, 1 , rozmiar, plik) ){
          error();
     }
     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, 1, rozmiar, plik) ){
     
          error();
     }

     // uaktualnienie notatek
     nr_obecnego = nr_chcianego/rozmiar ;

     // zwracamy wskaznik do tablicy roboczej
     return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
}
void duza_tablicachar::zapisz(char element, long nr_chcianego){

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
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, 1 , rozmiar, plik) ){
          error();
     }

     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, 1, rozmiar, plik) ){
     
          error();
     }
	 }
     // uaktualnienie notatek

	nr_obecnego = nr_chcianego/rozmiar ;      
     // zwracamy wskaznik do tablicy roboczej
     //return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
}
void duza_tablicachar::zapiszblok(char * blok, long nr_bloku){

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
			   
	
     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_bloku * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, 1 , rozmiar, plik) ){
          error();
     }
	 for ( long i = 0 ; i < rozmiar ; i ++){
		podobszar[i] = blok[i];
	 }
	 nr_obecnego = nr_bloku ;      
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
       duza_tablicashort(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0);
	   void start(char *nazwa_pliku, long wym, long rozm, int wypelniacz = 0){
			duza_tablica(nazwa_pliku, wym, rozm, wypelniacz);
	   }
	   ~duza_tablicashort() ;

       short & odczytaj(long nr_chcianego) ;
	   void zapisz(short element, long nr_chcianego);
	   void zapiszblok(short * blok, long nr_bloku);
private:
       void error();
} ;
/*******************************************************/
duza_tablicashort::duza_tablicashort(char *nazwa, long wym, long rozm, int wypelniacz)             //
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
     fwrite(podobszar, 1, rozmiar, plik ) ;
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

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam ---------
     if(!fwrite(podobszar , 1, rozmiar, plik) ){
      
          error();
     }

     fclose(plik);        // zamkniecie pliku
     delete podobszar ;     // zwolnienie rezerwacji
}
/*******************************************************/
// przeladowanie operatora []
/*******************************************************/
short & duza_tablicashort::odczytaj(long nr_chcianego)
{                                                      //

     //=============================
     //      moze dany fragment tablicy jest pod reka ?
     //=============================
     if(nr_chcianego >= nr_obecnego*rozmiar && nr_chcianego < nr_obecnego*rozmiar+rozmiar){
           return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;    // nic nie trzeba robic !
     }

     //=============================
     // jesli nie, to najpierw odsylamy obecny wiersz=
     // ============================
     // obliczenie gdzie go poslac
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
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

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, , rozmiar, plik) ){
     
          error();
     }

     // uaktualnienie notatek
     nr_obecnego = nr_chcianego/rozmiar ;

     // zwracamy wskaznik do tablicy roboczej
     return podobszar[nr_chcianego-(nr_obecnego*rozmiar)] ;
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
     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(podobszar, 1 , rozmiar, plik) ){
          error();
     }

     // ===================================
     // sprowadzamy potrzebny wiersz    ===
     // ===================================
     // obliczenie gdzie  on w pliku jest

     if(!fseek(plik,nr_obecnego * rozmiar,SEEK_SET))
     {
          error();
     }

     // przeczytanie tego fragmentu ------------------------
     if(!fread(podobszar, 1, rozmiar, plik) ){
     
          error();
     }
	 }
     // uaktualnienie notatek

	nr_obecnego = nr_chcianego/rozmiar ;      
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
     if(!fseek(plik,nr_bloku * rozmiar,SEEK_SET)) {
          error();
     }
     // zapisanie tam -------------------------
     if(!fwrite(blok, 1 , rozmiar, plik) ){
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
