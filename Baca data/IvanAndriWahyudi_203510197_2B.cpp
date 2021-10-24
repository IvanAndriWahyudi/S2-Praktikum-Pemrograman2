#include <stdio.h>
#include <string.h>
#include  "IvanAndriWahyudi_203510197_2B.h"

using namespace std;

int main(){

	float BB, tinggi;
	char nama[20];

	cout << "\n\tProgram Menghitung Berat Badan Ideal" << endl;

	cout << "Masukan Nama 		= ";
	gets(nama);
	cout << "Masukan Tinggi Badan 	= ";
	cin >> tinggi;

	cout << "\n==================================" << endl;

	strupr(nama);
	cout << "Nama 			= " << nama << endl;
	cout << "Tinggi 			= " << tinggi << "cm" << endl;
	cout << "Berat Badan Ideal 	= " << beratbadan(tinggi) << "Kg" << endl;


	return 0;
}
