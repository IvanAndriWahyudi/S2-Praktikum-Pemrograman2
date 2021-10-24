#include <iostream>

using namespace std;

float proses(float angka1, float angka2, char operasi){

	if (operasi == '*'){
		return angka1 * angka2;
	}else if (operasi == '/'){
		return  angka1 / angka2;
	}else if (operasi == '+'){
		return  angka1 + angka2;
	}else if (operasi == '-'){
		return  angka1 - angka2;
	}else {
		cout << "Anda Salah Memasukan perintah" << endl;
		return 0;
	}
}



int main(){

	float bil1, bil2;
	char operasi;
	

	cout << "Masukan Angka Pertama 					= ";
	cin >> bil1;
	cout << "Silahkan Pilih Operasi Berikut ? ? (*), (/), (+), (-), 	= ";
	cin >> operasi;
	cout << "Masukan Angka Kedua 					= ";
	cin >> bil2;

	cout << "Hasil dari " <<bil1 <<" " << operasi << " " << bil2 << " 					= " << proses(bil1,bil2,operasi) << endl;

	return 0;
}

