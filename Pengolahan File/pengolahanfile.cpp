#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct datamahasiswa{
char npm[10];
char nama[20];
int ipk;
} mhs;


main(){
	ofstream FileMhs ("datamhs.dat", ios::app); // append=menambah
		if (!FileMhs)
{
cerr<<"File tidak dapat dibuka..."<<endl;
exit(1);
}
char jwb='Y';
cout<<"Input Data Mahasiswa"<<endl;
while (jwb=='Y' || jwb=='y')
{
cout << endl;
cout << "NPM = "; cin>>mhs.npm;
cout << "Nama = "; cin.ignore(); gets(mhs.nama);
cout << "IPK = "; cin>>mhs.ipk;
FileMhs.write((char*)&mhs, sizeof(mhs)); // perintah merekam data
cout << "Ada Data Lagi [Y/T] = "; cin >> jwb;
}
FileMhs.close();





void infoMhs(); // prototype fungsi
struct datamhs
{
char npm[10];
char nama[20];
int ipk;
} mhs;
ifstream mhsFile ("datamhs.dat", ios::in);
if (!mhsFile)
{
cerr<<"File could not be opened"<<endl;
exit(1);
}
cout<<"-----------------------------------------------------------"<<endl;
cout <<setiosflags(ios::left)<<setw(5)<<"No."
<<setw(11)<<"NPM"
<<setw(21)<<"Nama Mahasiswa"
<<setw(8) <<"IPK"
<<setw(17)<<"Prediket"<<endl;
cout<<"-----------------------------------------------------------"<<endl;
mhsFile.read((char *)&mhs,sizeof(mhs)); // baca record 1
while (!mhsFile.eof())
{
infoMhs();
mhsFile.read((char*)&mhs, sizeof(mhs)); // baca record berikutnya
}
cout<<"-----------------------------------------------------------"<<endl;
mhsFile.close();
}
int no=0;
char pre[18];
void infoMhs() // definisi fungsi
{
no++;
if (mhs.ipk>=80)
strcpy(pre,"a");
else
if (mhs.ipk>=70)
strcpy(pre,"a-");
else
if (mhs.ipk>=65)
strcpy(pre,"b");
else
if (mhs.ipk>=60)
strcpy(pre,"b-");
else
if (mhs.ipk>=55)
strcpy(pre,"c");
else
if (mhs.ipk>=40)
strcpy(pre,"c-");
if (mhs.ipk>=30)
strcpy(pre,"d");
if (mhs.ipk<=30)
strcpy(pre,"e");
if (mhs.ipk>=100)
strcpy(pre,"eror");
else
strcpy(pre," ");
cout <<setiosflags(ios::left)<<no<<setw(3) << ". "
<<setw(11)<<mhs.npm
<<setw(21)<<mhs.nama
<<setw(8) << mhs.ipk
<< setw(17)<<pre<<endl;
}