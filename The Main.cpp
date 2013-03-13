#include "EncryptionTools.h"
#include <cstring>
void intervalCheck(int begin, int end , int cur)
{
	while(cur<begin || cur>end || cin.fail() )
	{
		cin.sync();
		cin.clear();
		cout<<"Napravili ste nevaliden izbor. Molq izberete otnovo "; cin >> cur;
	}
}
void codeMessage()
{
	encryptor help;
	const int MAXSIZE=100000;
	int  frequency;
	char message[MAXSIZE];
	cout<<"Vuvedetete izraz za KODIRANE: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(message,100001);
	cout<<endl<<"Vuvedete 4ESTOTA na kodiraneto: "; 
	cin>>frequency;
	cout<<endl<<endl<<"Resultat:"<<endl << help.encryptMessageToMessage(message,frequency)<<endl;
}
void decodeMessage()
{
	encryptor help;
	const int MAXSIZE=100000;
	int frequency;
	char message[MAXSIZE];
	cout<<"Vuvedetete izraz za DEKODIRANE: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(message,100001);
	cout<<endl<<"Vuvedete 4ESTOTA na dekodiraneto: ";
	cin>>frequency;
	cout<<endl<<endl<<"Resultat:"<<endl << help.decryptMessageToMessage(message,frequency)<<endl;
}
void codeFile()
{
	encryptor help;
	const int MAXSIZE=1000;
	int frequency;
	char source[MAXSIZE];
	char end[MAXSIZE];
	cout<<"Vuvedetete ime na fail za KODIRANE: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(source,1001);
	cout<<endl<<"Vuvedete 4ESTOTA na kodiraneto: ";
	cin>>frequency;
	cout<<endl<<"Vuvedete ime na GOTOVIQ KODIRAN fail: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(end,1001);

	strcat(end,".mp3");
	help.encryptFileToFile(source,frequency,end);
	cout<<"Done :)"<<endl;
}
void decodeFile()
{
	encryptor help;
	const int MAXSIZE=1000;
	int frequency;
	char source[MAXSIZE];
	char end[MAXSIZE];
	cout<<"Vuvedetete ime na fail za DEKODIRANE: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(source,1001);
	cout<<endl<<"Vuvedete 4ESTOTA na dekodiraneto: ";
	cin>>frequency;
	cout<<endl<<"Vuvedete ime na GOTOVIQ DEKODIRAN fail: "; 
	cin.clear(); 
	cin.sync();
	cin.getline(end,1001);

	strcat(end,".txt");
	help.decryptFileToFile(source,frequency,end);
	cout<<"Done :)"<<endl;
}




void workWithMessages ()
{
	int choise=0;
	cout<<"Za KODIRANE na saob6teniq natisnete 1 "<<endl;
	cout<<"Za RAZKODIRANE na saob6teniq natisnete 2 "<<endl;
	cout<<"Sistemata o4akva va6iq izbor: "; cin >> choise;
	intervalCheck(1,2,choise);
	system("cls");
	if(choise==1) codeMessage();
	else decodeMessage();
}
void workWithFile()
{
	int choise=0;
	cout<<"Za KODIRANE na file natisnete 1 "<<endl;
	cout<<"Za RAZKODIRANE na file natisnete 2 "<<endl;
	cout<<"Sistemata o4akva va6iq izbor: "; cin >> choise;
	intervalCheck(1,2,choise);
	system("cls");
	if(choise==1) codeFile();
	else decodeFile();
}
void Begin()
{
	int choise=0;
	while (choise!=3)
	{
		
		cout<<"SISTEMA ZA KODIRANE NA FAILOVE I TEKSTOVI SUOB6TENIQ" <<endl<<endl <<endl;
		cout<<"Za rabota s failove natisnete 1"<<endl;
		cout<<"Za rabota s suob6teniq natisnete 2"<<endl;
		cout<<"Za izhod ot programata natisnete 3"<<endl;
		cout<<"Napravete va6iqt izbor: "; cin >>choise;
		system("cls");
		intervalCheck(1,3,choise);
		switch(choise)
		{
		case 1:
			workWithFile();
			break;
		case 2:
			workWithMessages();
			break;
		case 3:
			return;
		}
	}
}




int main ()
{ 
	Begin();
	system("cls");
	cout<<"                  +++++++++++++++++++"<<endl;
	cout<<"********************************************************************************"<<endl;
	cout<<"                 BLAGODARQ VI 4E IZPOLZVAHTE NA6IQT SOFTUER :)                                 "<<endl;
	cout<<"********************************************************************************";
	cout<<"                  ++++++++++++++++++++"<<endl;
	system("pause");
	
	
	return 0;
}
