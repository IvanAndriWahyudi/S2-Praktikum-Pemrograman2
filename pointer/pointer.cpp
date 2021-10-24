#include <iostream>

using namespace std;

int main(){

	float volume, r, pi = 3.14;

	cout << "\nPROGRAM MENGHITUNG VOLUME BOLA" <<endl;
	cout << "================================" << endl;
	cout << "\nMasukan Jari-jari Bola = ";
	cin >> r;

	volume = pi * r * r * r * 4 / 3;
	cout << "Volume Bola Adalah = " << volume << " cm " << endl;
	cout << "Alamat memory pada Volume Bola adalah = " << &volume << endl;


	return 0;
}
