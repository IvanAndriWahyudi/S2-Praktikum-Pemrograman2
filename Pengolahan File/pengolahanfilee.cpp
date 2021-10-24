#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void rekamdata();
void bacadata();

struct datamhs{
	char npm[20];
	char nama[20];
	float ipk;
}mhs;


main(){
	int pilmenu = 1;
	while (pilmenu <= 2){

		cout << "MENU PILIHAN" << endl;
		cout << "[1] Merekam Data " << endl;
		cout << "[2] Membaca Data " << endl;
		cout << "[3] Keluar " << endl;
		cout << "Inputkan Pilihan Anda = ";
		cin >> pilmenu;
			if (pilmenu == 1){
				rekamdata();
			}else if (pilmenu == 2){
				bacadata();
			}else
				exit(1);
	}
}

void rekamdata(){
	ofstream FileMhs("datamhs.dat", ios :: out);
	if(!FileMhs){
		cerr <<"File Could Not Be Opened " << endl;
		exit(1);
	}
	char jawab = 'y';
	cout << "Inputkan Data Mahasiswa" << endl;
	while (jawab == 'Y' || jawab == 'y'){
		cout << endl;
		cin.ignore();
		cout << "Masukan Nama 	= ";
		gets(mhs.nama);
		cout << "Masukan Npm 	= ";
		cin >> mhs.npm;
		cout << "Masukan IPK	= ";
		cin >> mhs.ipk;
		FileMhs.write((char*) & mhs, sizeof(mhs));
		cout << "Ada Data Lagi [Y/T]	= ";
		cin >> jawab; 
	}
	FileMhs.close();
}

void bacadata(){
	int no = 0;
	char pre [18];
	ifstream mhsFile ("datamhs.dat", ios::in);
	if (!mhsFile)
	{
		cerr << "File Could Not Be Opened " << endl;
			exit(1);
	}
	cout << ">>>>>>>>>>>>>>>>>>>>DATA MAHASISWA>>>>>>>>>>>>>>>>>>>> " << endl;
	cout << "======================================================\n" << endl;
	cout << setiosflags(ios::left)<<setw(5)<< "No." 
	<< setw (11) << "Npm"
	<< setw (21) << "Nama"
	<< setw (8) << "Ipk"
	<< setw (17) << "Predikat" << endl;
	cout << "======================================================" << endl;
	mhsFile.read((char *) & mhs, sizeof(mhs));
	while (!mhsFile .eof()){
		no++;
			if (mhs.ipk>=80)
				strcpy(pre,"A");
			else if (mhs.ipk>=70)
				strcpy(pre,"A-");
			else if (mhs.ipk>=65)
				strcpy(pre,"B");
			else if (mhs.ipk>=60)
				strcpy(pre,"B-");
			else if (mhs.ipk>=55)
				strcpy(pre,"C");
			else if (mhs.ipk>=40)
				strcpy(pre,"C-");
			else if (mhs.ipk>=30)
				strcpy(pre,"D");
			else if (mhs.ipk<=30)
				strcpy(pre,"E");
			else if (mhs.ipk>=100)
				strcpy(pre,"eror");
			else
				strcpy(pre," Tidak ada ");
		cout <<setiosflags(ios :: left)<< setw(5) << no
		<<setw (11) << mhs.npm 
		<<setw (21) << mhs.nama
		<<setw (8) << mhs.ipk
		<<setw (17) << pre << endl;
		mhsFile.read ((char *) & mhs, sizeof(mhs)); 
	}

	cout << "======================================================" << endl;
	mhsFile.close();
	getch();
}









