#include <conio.h>
#include <iostream>
#include "KlasaDane.h"
#include "TablicaPlik.h"

using namespace System;
using namespace System::IO;

struct streaminfo{
	unsigned short bits_per_sample;
	long long file_size;
	long bytes_per_sample;
	int block_align;
	int number_of_channels;
	long subchunk1size;
	long long subchunk2size;
	long long channel_size;
	long sample_rate;
};

class Plik{
	FILE * handle;
	char nazwa_pliku[2500];
	long pos;
	unsigned long rozmiar;
	bool odczytany;
	long bufsize;
public:
	Plik(){
		odczytany=false;
	}

	int odczytaj_caly( System::String ^ nazwa, array<unsigned char>^&Buffer, streaminfo & fileinfo);
	int odczytaj_caly2( System::String ^ nazwa, TableFile Buffer, streaminfo & fileinfo);
	int odczytaj_czesc(char * nazwa, char * buf, unsigned long start, unsigned long end);
	int zapisz_caly(char * nazwa, char * buf, unsigned long dlug);
	unsigned long Rozmiar(char * nazwa);	
};

int Plik::odczytaj_caly( System::String ^ nazwa, array<unsigned char>^&Buffer, streaminfo & fileinfo)
{
	Buffer = File::ReadAllBytes(nazwa);
	if(Buffer.Length > 0){
		if(Buffer[0]!=0x52 && Buffer[1]!=0x49 && Buffer[2]!=0x46 && Buffer[3]!=0x46)return -2;
		fileinfo.file_size = Buffer[4] + Buffer[5]*256 + Buffer[6]*256*256 + Buffer[7]*256*256*256;
		if(Buffer[8]!=0x57 && Buffer[9]!=0x41 && Buffer[10]!=0x56 && Buffer[11]!=0x45)return -3;
		fileinfo.subchunk1size = Buffer[16] + Buffer[17]*256 + Buffer[18]*256*256 + Buffer[19]*256*256*256;
		if(Buffer[20]!=0x1 && Buffer[21]!=0x00 )return -4;
		fileinfo.number_of_channels = Buffer[22] + Buffer[23]*256;
		fileinfo.sample_rate = Buffer[24] + Buffer[25]*256 + Buffer[26]*256*256 + Buffer[27]*256*256*256;
		fileinfo.block_align = Buffer[32] + Buffer[33]*256;
		fileinfo.bits_per_sample = Buffer[34] + Buffer[35]*256;
		if(Buffer[36]!=0x64 && Buffer[37]!=0x61 && Buffer[38]!=0x74 && Buffer[39]!=0x61)return -3;
		fileinfo.subchunk2size = Buffer[24 + fileinfo.subchunk1size] + Buffer[25 + fileinfo.subchunk1size]*256 + Buffer[26 + fileinfo.subchunk1size]*256*256 + Buffer[27 + fileinfo.subchunk1size]*256*256*256;
		fileinfo.bytes_per_sample=fileinfo.bits_per_sample/8;
		fileinfo.channel_size=fileinfo.subchunk2size/fileinfo.number_of_channels/fileinfo.bytes_per_sample;
		odczytany=true;
		return 1;
	}return -1;
}

int Plik::odczytaj_caly2( System::String ^ nazwa, TableFile Buffer, streaminfo & fileinfo)
{
	if(Buffer.fileOpen(nazwa, "r")){
		if(Buffer[0]!=0x52 && Buffer[1]!=0x49 && Buffer[2]!=0x46 && Buffer[3]!=0x46)return -2;
		fileinfo.file_size = Buffer[4] + Buffer[5]*256 + Buffer[6]*256*256 + Buffer[7]*256*256*256;
		if(Buffer[8]!=0x57 && Buffer[9]!=0x41 && Buffer[10]!=0x56 && Buffer[11]!=0x45)return -3;
		fileinfo.subchunk1size = Buffer[16] + Buffer[17]*256 + Buffer[18]*256*256 + Buffer[19]*256*256*256;
		if(Buffer[20]!=0x1 && Buffer[21]!=0x00 )return -4;
		fileinfo.number_of_channels = Buffer[22] + Buffer[23]*256;
		fileinfo.sample_rate = Buffer[24] + Buffer[25]*256 + Buffer[26]*256*256 + Buffer[27]*256*256*256;
		fileinfo.block_align = Buffer[32] + Buffer[33]*256;
		fileinfo.bits_per_sample = Buffer[34] + Buffer[35]*256;
		if(Buffer[36]!=0x64 && Buffer[37]!=0x61 && Buffer[38]!=0x74 && Buffer[39]!=0x61)return -3;
		fileinfo.subchunk2size = Buffer[24 + fileinfo.subchunk1size] + Buffer[25 + fileinfo.subchunk1size]*256 + Buffer[26 + fileinfo.subchunk1size]*256*256 + Buffer[27 + fileinfo.subchunk1size]*256*256*256;
		fileinfo.bytes_per_sample=fileinfo.bits_per_sample/8;
		fileinfo.channel_size=fileinfo.subchunk2size/fileinfo.number_of_channels/fileinfo.bytes_per_sample;
		odczytany=true;
		return 1;
	}return -1;
			
}

int Plik::odczytaj_czesc(char * nazwa, char * buf, unsigned long start, unsigned long end)
{
		
	handle=fopen(nazwa,"r");
	if(handle!=0){

		fseek(handle,0,SEEK_END);
		rozmiar=ftell(handle);
		rewind(handle);
		fseek(handle,start,SEEK_SET);
		if(fread(buf,1,end,handle)<0){
			fclose(handle); return -2;
		}
			
		fclose(handle);
		odczytany=true;
		return 1;

	} else return -1;


}
int Plik::zapisz_caly(char * nazwa, char * buf, unsigned long dlug){
	
		handle=fopen(nazwa,"r+");
	if(handle!=0){

		fseek(handle,0,SEEK_SET);
		if(!fwrite(buf,1,dlug,handle)){
			fclose(handle); return -2;
		}
		return 1;

	} else return -1;

}

unsigned long Plik::Rozmiar(char * nazwa){
		
		handle=fopen(nazwa,"r");
		if(handle!=0){

			fseek(handle,0,SEEK_END);
			rozmiar=ftell(handle);
			fclose(handle); 
		//printf("%d", rozmiar);
			return rozmiar;
				
			} else return -1;
	}

