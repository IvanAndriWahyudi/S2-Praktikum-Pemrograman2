#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <string.h> 
#include <iomanip> 
#include "header.h"
using namespace std;


struct datapasien
{
char norm[20];
char nama[20];
char jenis_kelamin[10];
int tensi;
} pas;
main()
{
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
<<setw(10) <<"| JENIS KELAMIN |"
<<setw(20)<<"| TENSI |"
<<setw(17)<<"| KETERANGAN "<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------|"<<endl;
pasFile.read((char *)&pas,sizeof(pas)); 
while (!pasFile.eof())
{
infopasien(pas.norm, pas.nama, pas.jenis_kelamin, pas.tensi);
pasFile.read((char*)&pas, sizeof(pas)); 
}
cout<<"---------------------------------------------------------------------------------------------------------------|"<<endl;
pasFile.close();
}
