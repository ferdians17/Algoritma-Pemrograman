#include <iostream>
#include <conio.h>

using namespace std;

//definisi fungsi
float hitung();

int main()
{
	float volume;
	cout << "Menghitung Volume KUBUS" <<endl;

    //penggunaan fungsi
	volume = hitung();
	cout << "Volume KUBUS adalah :" << volume << " m.";
	return 0;
}

//deklarasi fungsi
float hitung()
{
	float sisi, vol;
	cout << "Sisi Kubus (m):";
	cin >> sisi;
	vol = sisi * sisi * sisi;
	return vol;
}