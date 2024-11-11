#include <iostream>
#include <conio.h>

using namespace std;

//definisi fungsi dengan 2 parameter
float luas( int a, int b);

int main()
{
	float panjang, lebar;
	
	cout << "Menghitung Luas" <<endl;
	cout << "Tentukan Panjang (m):";
	cin >> panjang;
	
	cout << "Tentukan Lebar (m):";
	cin >> lebar;
	
    //penggunaan fungsi dengan 2 parameter
	cout << "Luas Segi Empat adalah :" << luas(panjang, lebar) << " m.";
	return 0;
}

//deklarasi fungsi dengan 2 parameter
float luas( int a, int b)
{
	return a * b;
}