#include <iostream>
#include <fstream>
using namespace std;



class encryptor
{
	
	char* result;
	char* encrypt(char *, int);
	char* decrypt (char* ,int);
	//int whichCode(char*);
	//int frequencyChanger(int);
public:
	encryptor()
	{
		result=new char [1];
	}
	~encryptor()
	{
		delete [] result;
	}
	char* decryptEverything(char*);

	char* encryptMessageToMessage (char*, int );
	char* decryptMessageToMessage (char* , int);
	void encryptMessageToFile (char *  , int , const char *);
	char* decryptFileToMessege(const char* , int);
	void encryptFileToFile(const char * ,int , const char * );
	void decryptFileToFile(const char * , int , const char* );


};
