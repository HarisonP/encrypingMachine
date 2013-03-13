#include "EncryptionTools.h"


char* encryptor::encrypt(char * message,int frequency)
{
	int size=strlen(message);
	frequency%=70;
	delete [] result;
	result= new char [size + 1];
	int j=0;
	for(int i=0; i<size; i++)
	{
		if(message[i]!=' ')
			result[i]=message[i]+frequency;
		else 
			result[i]=message[i];
	}
	result[size]='\0';
	return result;
}
char* encryptor::decrypt(char* message,int frequency)
{
	int size=strlen(message);
	delete [] result;
	result= new char [size + 1];
	frequency%=70;
	for(int i=0; i<size; i++)
	{
		if(message[i]!=' ')
			result[i]=message[i]-frequency;
		else
			result[i]=message[i];
	}
	result[size]='\0';
	return result;
}
//char* encryptor::decryptEverything(char* message)
//{
//	int frequency= (int) message[0];
//	int size = strlen(message);
//	delete [] result;
//	result = new char [size+1];
//	//char* result = new char [size+1];
//	for(int i=1; i<size ; i++)
//		result[i-1]=(char) ((int) message[i] - frequency);
//	result[size-1]='\0';
//	return result;
//
//}







char* encryptor::encryptMessageToMessage(char* message, int frequency)
{ 
	return this->encrypt(message,frequency);
}
char* encryptor::decryptMessageToMessage(char* message, int frequency)
{
	return this->decrypt(message,frequency);
}

void encryptor::encryptMessageToFile(char* message, int frequency , const char* fileName)
{
	ofstream inserter(fileName,ios::out | ios::trunc);
	inserter << this->encrypt(message,frequency);
}
char* encryptor::decryptFileToMessege(const char* fileName,int frequency)
{
	ifstream getter(fileName,ios::in);
	getter.seekg(0,ios::end);
	unsigned int fileSize= getter.tellg();
	getter.seekg(0,ios::beg);
	char* result=new char [fileSize+1];
	getter.read(result,fileSize);
	result[fileSize]='\0';
	result=this->decrypt(result,frequency);
	this->result=result;
	return result;
}

void encryptor::encryptFileToFile(const char* source,int frequency, const char* end)
{

	ifstream getter(source,ios::in);
	getter.seekg(0,ios::end);
	unsigned int fileSize= getter.tellg();
	getter.seekg(0,ios::beg);
	char* result=new char [fileSize+1];
	getter.read(result,fileSize);
	result[fileSize]='\0';
	encryptMessageToFile(result,frequency,end);
	this->result=result;
}
void encryptor::decryptFileToFile(const char* source , int frequency, const char* end)
{
	char* helper=decryptFileToMessege(source,frequency);
	ofstream inserter(end, ios::ate | ios::trunc);
	inserter.write(helper,strlen(helper));
}





