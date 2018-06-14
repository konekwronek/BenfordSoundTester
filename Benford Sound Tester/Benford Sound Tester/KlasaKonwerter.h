#include "KlasaTester.h"

class Konwerter{

private:

	unsigned long i,j,k,stop; //iteratory

public:

	int SumaInterwalowa(Dane & dane, Dane & wynik, int interwal);
	int SredniaInterwalowa(Dane & dane, Dane & wynik, long interwal);
	int Bezwzgledna(Dane & dane);
	int KasujZera(Dane & dane);
	int WaveNaDane(array<unsigned char>^&Buffer, Dane * kanaly, streaminfo & fileinfo);
	int UstawKanalyWave(Dane * kanaly, streaminfo & fileinfo){
		for(int i=0; i<fileinfo.number_of_channels; i++){
				
			kanaly[i].ZmienRozmiar((fileinfo.subchunk2size/fileinfo.bytes_per_sample/fileinfo.number_of_channels));
			
			kanaly[i].UstawZakres(0,(fileinfo.subchunk2size/fileinfo.bytes_per_sample/fileinfo.number_of_channels));
				
			fileinfo.channel_size=(fileinfo.subchunk2size/fileinfo.number_of_channels/fileinfo.bytes_per_sample);
							
		}
		return 1;		
	}




};
//do przetestowania
int Konwerter::SumaInterwalowa(Dane & dane, Dane & wynik, int interwal){
	
	long rozmiar=dane.WezRozmiar();
	double bit=0;
	if(interwal>0 && interwal<rozmiar && wynik.WezRozmiar()>rozmiar/interwal){
		
		for(i=0;i<rozmiar;i+interwal){
			
			for(j=i;j<i+interwal;j++){
			
				bit=bit+dane.ZwrocAtom(j);

			}
			wynik.WezAtom(bit,i);
		}
	
	}else return -1;

	return 1;
}

int Konwerter::SredniaInterwalowa(Dane & dane, Dane & wynik, long interwal){
	
	long rozmiar=dane.WezRozmiar();
	double bit=0, bit2;
	if(interwal>0 && interwal<rozmiar){
		wynik.ZmienRozmiar(rozmiar/interwal);
		for(i=0;i<rozmiar;i=i+interwal){
			for(j=0;j<interwal;j++){
				bit2=dane.ZwrocAtom(i+j);
				bit=bit+bit2;
			}
			wynik.WezAtom(bit/interwal*1000.0,i/interwal);
			bit=0;
		}
		return 1;
	}else return -1;
}

int Konwerter::KasujZera(Dane & dane)
{
	Dane buf;
	stop=dane.WezRozmiar();
	j=0; k=0;
	for(i=0; i<stop; i++)
	{
		if(dane.ZwrocAtom(i)==0)k++;
	}
	if(buf.ZmienRozmiar(stop-k)>0){
	for(i=0;i<stop-k;i++)
	{
		if(dane.ZwrocAtom(i)!=0)buf.WezAtom(dane.ZwrocAtom(i),j);
		j++;
	}
	dane.ZmienRozmiar(stop-k);
	//dane.KopiujDane(buf,dane, nr);	
	
	return 1;
	} return -1;
}

int Konwerter::WaveNaDane(array<unsigned char>^&Buffer, Dane * kanaly, streaminfo & fileinfo)
{
	short sh_bits;
	long l_bits;
	char c_bits;

	long long pointer, i, j, jj, k;

	//if(fileinfo.bytes_per_sample == 4){
	//	for(j = 0; j < fileinfo.subchunk2size/(fileinfo.number_of_channels*fileinfo.bytes_per_sample); j++){
	//		jj = j * fileinfo.number_of_channels * fileinfo.bytes_per_sample;
	//		for(i=0; i < fileinfo.number_of_channels; i++){
	//			pointer= jj + i * fileinfo.bytes_per_sample;
	//			l_bits =  Buffer[pointer + 28 + fileinfo.subchunk1size] | (Buffer[pointer + 29 + fileinfo.subchunk1size] << 8) | (Buffer[pointer + 30 + fileinfo.subchunk1size] << 16) | (Buffer[pointer + 31 + fileinfo.subchunk1size] << 24);
	//			kanaly[i].WezAtom(l_bits, j);
	//		}				
	//	}
	//}

	if(fileinfo.bytes_per_sample == 2){
		for(j = 0; j < fileinfo.subchunk2size/(fileinfo.number_of_channels*fileinfo.bytes_per_sample); j++){
			jj = j * fileinfo.number_of_channels * fileinfo.bytes_per_sample;
			for(i=0; i < fileinfo.number_of_channels; i++){
				pointer= jj + i * fileinfo.bytes_per_sample;
				sh_bits =  Buffer[pointer + 28 + fileinfo.subchunk1size] | (Buffer[pointer + 29 + fileinfo.subchunk1size] << 8);
				kanaly[i].WezAtom(long(sh_bits), j);
			}				
		}
	}

	if(fileinfo.bytes_per_sample == 1){
		for(j = 0; j < fileinfo.subchunk2size/(fileinfo.number_of_channels*fileinfo.bytes_per_sample); j++){
			jj = j * fileinfo.number_of_channels * fileinfo.bytes_per_sample;
			for(i=0; i < fileinfo.number_of_channels; i++){
				pointer= jj + i * fileinfo.bytes_per_sample;
				c_bits = Buffer[pointer + 28 + fileinfo.subchunk1size];
				kanaly[i].WezAtom(long(c_bits), j);
			}			
		}
	}

	return 1;
}