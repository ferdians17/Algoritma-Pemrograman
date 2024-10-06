#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string barang[99];
	int harga[99], jumlah[99], subTotal[99], total = 0, c = 0;
	char aksi = 'y';
	
	cout << "==============================\n";
	cout << "----- PT. MAKMUR SENTOSA -----\n";
	cout << "==============================\n";
	cout << "Data Penjualan Bulan Oktober \n";
	
	while( aksi == 'y' || aksi == 'Y' )
	{
		cout << "Masukkan Nama Barang:"; cin >> barang[c];
		cout << "Satuan Harga Barang:"; cin >> harga[c];
		cout << "Jumlah Barang Terjual:"; cin >> jumlah[c];
		
		cout << "==============================\n";
		cout << "Lanjut transaksi lagi (Y/N) ?:"; cin >> aksi;
		
		subTotal[c] = harga[c] * jumlah[c];
		total += subTotal[c];
		c++;
	}
	
	cout << "+-----+--------------------+--------------------+----------+--------------------+\n";
	cout << "| " << left << setw(4) << "No." << setw(21) << "| Nama Barang" << setw(21);
	cout << "| Harga barang" << setw(11) << "| Jumlah " << setw(21) << "| Sub total" << left << "|\n";
	cout << "+-----+--------------------+--------------------+----------+--------------------+\n";
	
	for(int t = 0; t < c; t++)
	{
		cout << "| " << setw(4) << left << (t+1)  << "| "<< setw(19) << barang[t];
		cout << "| " << setw(19) << harga[t] << "| " << setw(9) << jumlah[t] << "| " << setw(19) << subTotal[t] << right << "|\n";
	}
	
	cout << "+-----+--------------------+--------------------+----------+--------------------+\n";
	cout << "| " << setw(57) << left << "TOTAL PENJUALAN" << "|" << setw(20) << total << "|\n";
	cout << "+----------------------------------------------------------+--------------------+\n";
	
	return 0;
}
