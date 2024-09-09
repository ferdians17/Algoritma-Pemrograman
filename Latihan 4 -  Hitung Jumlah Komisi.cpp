#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int harga, barang, jumlah, total, komisiA = 0, komisiB = 0;
	
	cout << setprecision(10);
	cout << "TOKO ELEKTRONIK KASIH BUNDA" << endl;
	cout << "===========================" << endl;
	cout << "1. TELEVISI 21 INCH - Rp. 7.430.000 \n";
	cout << "2. KULKAS 4 PINTU - RP. 4.500.000 \n";
	cout << "3. AC 4 PK - Rp. 2.800.000 \n";
	cout << "4. PROYEKTOR MINI - Rp. 1.200.000 \n";
	cout << "5. Kipas Angin - Rp. 200.000 \n";
	cout << "==================================" << endl;
	cin >> barang;
	
	switch(barang)
	{
		case 1:
			harga = 7430000;
			break ;
			
		case 2:
			harga = 4500000;
			break ;
			
		case 3:
			harga = 2800000;
			break ;
			
		case 4:
			harga = 1200000;
			break ;
			
		case 5:
			harga = 200000;
			break ;
			
		default:
			cout  << "Barang yang diminta tidak terdaftar \n";
			break ;
	}
	
	cout << "Jumlah barang dibeli:";
	cin >> jumlah;
	
	total = jumlah * harga;
	
	if( total > 500000)
	{
		komisiA = 500000 * 0.1;
		komisiB = (total - 500000) * 0.15;
	}
	else if ( total == 500000) komisiA = 500000 * 0.1;
	else komisiA = 0;
	
	cout << "Total Harga Barang terjual: " << total <<endl;
	cout << "Total Komisi: " << (komisiA + komisiB) <<endl;
	
	return 0;
}
