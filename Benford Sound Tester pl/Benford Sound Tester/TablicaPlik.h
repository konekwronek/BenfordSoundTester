#include <iostream>

using namespace std;
using namespace System;
using namespace System::IO;

class TableFile{
    array<unsigned char>^* buffer;
    long bufferSize;
    long fileSize;
    long aktualPartNumber;
    long partsCount;
	FileStream^* fileStream;
    enum error{
        ERR_CANT_OPEN_FILE,
        ERR_OUT_OF_RANGE,
        ERR_FILE_NOT_OPENED
    };
    error er;

public:
    TableFile(long buffSize);
    int fileOpen(System::String ^ InfileName);
    int readByte(long whichOne, char & byte);
	char operator[](long whichOne);
    int readWord(long whichOne, short & byte, bool bigEndian);
    int readLongWord(long whichOne, long & byte, bool bigEndian);
    char * printError(void);
    ~TableFile()
    {
        delete [] buffer;
    }
private:
    int readBuffer(long partNumber);
};

TableFile::TableFile(long buffSize)
{
    bufferSize = buffSize;
    fileSize = 0; partsCount = 0;
}

int TableFile::fileOpen(System::String ^ InfileName)
{
     
	fileStream[0] = File::Open( InfileName, FileMode::Open, FileAccess::Read );
	if(fileStream[0]->Length > 0){
        fileSize = fileStream[0]->Length;
        partsCount = (fileSize / bufferSize) + 1;
        aktualPartNumber = 0;
        readBuffer(aktualPartNumber);
        return 1;
    }else{
        er = ERR_CANT_OPEN_FILE;
        return 0;
    }

}

int TableFile::readByte(long whichOne, char & byte)
{
    if(fileStream[0]->Length > 0){
        if(whichOne < fileSize && whichOne >=0){
            if(aktualPartNumber != (whichOne / bufferSize)){
                aktualPartNumber = (whichOne / bufferSize);
                readBuffer(aktualPartNumber);
            }
            whichOne = whichOne - (aktualPartNumber * bufferSize);
            byte = buffer[0][whichOne];
            return 1;
        }else{
            er = ERR_OUT_OF_RANGE;
            return 0;
        }
    }else{
        er = ERR_FILE_NOT_OPENED;
        return 0;
    }
}
char TableFile::operator[](long whichOne)
{
    if(fileStream[0]->Length > 0){
        if(whichOne < fileSize && whichOne >=0){
            if(aktualPartNumber != (whichOne / bufferSize)){
                aktualPartNumber = (whichOne / bufferSize);
                readBuffer(aktualPartNumber);
            }
            whichOne = whichOne - (aktualPartNumber * bufferSize);
            return buffer[0][whichOne];
            return 1;
        }else{
            er = ERR_OUT_OF_RANGE;
            return 0;
        }
    }else{
        er = ERR_FILE_NOT_OPENED;
        return 0;
    }
}

char * TableFile::printError(void)
{
    switch(er)
    {
        case ERR_CANT_OPEN_FILE : return "Can't open file!";
        case ERR_FILE_NOT_OPENED : return "File is not opened!";
        case ERR_OUT_OF_RANGE : return "Selected item is out of range!";
        default : return "No error.";
    };
}

int TableFile::readBuffer(long partNumber)
{
		if(fileStream[0]->Length > 0){
            fileStream[0]->Read(buffer[0], partNumber*bufferSize, bufferSize);
		}else{
			return 0;
		}
        aktualPartNumber = partNumber;
        return 1;
}

