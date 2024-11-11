#include <iostream>
#include <conio.h>

using namespace std;

//definisi fungsi dengan 1 parameter
float hitung( int s);

int main()
{
	float volume, sisi;
	cout << "Menghitung Volume KUBUS" <<endl;
	cout << "Sisi Kubus (m):";
	cin >> sisi;
	
    //penggunaan fungsi dengan parameter
	volume = hitung(sisi);
	cout << "Volume KUBUS adalah :" << volume << " m.";
	return 0;
}

//deklarasi fungsi dengan 1 parameter
float hitung( int s)
{
	return s * s * s;
}