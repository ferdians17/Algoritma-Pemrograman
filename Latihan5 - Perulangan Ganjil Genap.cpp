#include <iostream>

using namespace std;

int main()
{
	cout << "NILAI I \t Keterangan \n";
	cout << "=======================\n";
	
	for(int angka = 1; angka <= 10; angka++)
	{
		if( angka %2 == 0) cout << angka << ". \t Genap \n";
		else cout << angka << ". Ganjil \n";
	}
	
	cout << "=======================\n";
	
	return 0;
}
