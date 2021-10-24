#include <iostream> 
#include <fstream> 
#include <stdlib.h>
#include <stdio.h> 
using namespace std;
struct datapribadi
{
char norm[20];
char nama[20];
char jenis_kelamin[10];
int tensi;

} pas;
main()
{
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
		Filepas.write((char*)&pas, sizeof(pas));
		cout << "Ada Data Lagi [Y/T = ";
		cin >> jwb;
}
Filepas.close();
}