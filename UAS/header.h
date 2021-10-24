#include <iostream>

using namespace std;


void infopasien(char nomor[20], char name[20], char gender[10], int ttensi) 
{
	int no=0;
	char pre[18];
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
		cout <<setiosflags(ios::left)<<no<<setw(3) << ". "
		<<setw(21)<<nomor
		<<setw(25)<<name
		<<setw(23) <<gender
		<<setw(13) <<ttensi
		<< setw(17)<<pre<<endl;
}

void info(int tenssi){
	int total;
}