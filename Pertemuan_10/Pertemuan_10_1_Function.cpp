#include <iostream>
#include <conio.h>

using namespace std;

//definisi fungsi
void hitung();

int main()
{
	cout << "Menghitung Volume KUBUS" <<endl;
	hitung(); //pemanggilan fungsi
	return 0;
}

//deklarasi fungsi
void hitung()
{
	float sisi, volume;
	cout << "Sisi Kubus (m):";
	cin >> sisi;
	volume = sisi * sisi * sisi;
	cout << "Volume KUBUS adalah :" << volume << " m.";
}