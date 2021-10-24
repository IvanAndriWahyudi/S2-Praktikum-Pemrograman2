#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;

void rekamData();
void bacaData();
void infopasien();
struct datapasien{
char norm[20];
char nama[20];
char jenis_kelamin[10];
int tensi;
}pas;



main (){
int menu = 1;
while(menu<=2){
	cout<<" ============================ \n";
	cout<<"|             MENU           |\n";
	cout<<" ============================ \n";
	cout<<"1} Merekam Dan Menulis Data   \n";
	cout<<"2} Membaca Data File          \n";
	cout<<"3} Keluar Dari Program        \n";
	cout<<"Masukkan Inputan : "             ;cin>>menu;
	if(menu==1){
		rekamData();
	}
	else{
		if(menu==2){
			bacaData();
		}
		else{
			exit(1);
		}
	}
}
}

	void rekamData(){
	ofstream Filepas ("datapasien.dat", ios::out); // append=menambah
if (!Filepas)
{
cerr<<"File tidak dapat dibuka..."<<endl;
exit(1);
}
char jwb='Y';
cout<<"Input Data diri kamu"<<endl;
while (jwb=='Y' || jwb=='y')
{

cout << endl;
cin.ignore(); 
		cout << "NoRm 	= ";
		cin >> pas.norm;
		cin.ignore();
		cout << "Nama 	= ";
		gets(pas.nama);
		cout << "Jenis Kelamin 	= ";
		gets(pas.jenis_kelamin);
		cout << "Tensi 	= ";
		cin >> pas.tensi;
Filepas.write((char*)&pas, sizeof(pas)); // perintah merekam data
cout << "Ada Data Lagi [Y/T] = "; cin >> jwb;
}
Filepas.close();
}
	void bacaData(){
ifstream pasFile ("datapasien.dat", ios::in);
if (!pasFile)
{
cerr<<"File could not be opened"<<endl;
exit(1);
}
cout<<"---------------------------------------------------------------------------------------------------------------|"<<endl;
cout <<setiosflags(ios::left)<<setw(5)<<"No."
<<setw(21)<<"| NO RM |"
<<setw(21)<<"| NAMA PASIEN |"
<<setw(27) <<"| JENIS KELAMIN |"
<<setw(20)<<"| TENSI |"
<<setw(5)<<"| KETERANGAN "<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------|"<<endl;
pasFile.read((char *)&pas,sizeof(pas)); 
while (!pasFile.eof())
{
infopasien();
pasFile.read((char*)&pas, sizeof(pas)); 
}
cout<<"---------------------------------------------------------------------------------------------------------------|"<<endl;
pasFile.close();
}
int no=0;
char pre[18];
void infopasien() 
{
no++;
if (pas.tensi <=120)
strcpy(pre,"NORMAL");
else
if (pas.tensi>=121<=139)
strcpy(pre,"PREHIPERTENSI");
else
if (pas.tensi >=140)
strcpy(pre,"PREHIPERTENSI");
else
strcpy(pre," | ");
cout <<setiosflags(ios::left)<<no<<setw(7) << ". "
<<setw(21)<<pas.norm
<<setw(25)<<pas.nama
<<setw(23) <<pas.jenis_kelamin
<<setw(13) <<pas.tensi
<< setw(17)<<pre<<endl;

}