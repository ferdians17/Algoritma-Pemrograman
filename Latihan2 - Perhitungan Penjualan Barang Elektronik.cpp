#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string namaBarang;
	float hargaBarang,
		  jumlahJual,
		  totalHarga,
		  diskon,
		  totalBayar;
		  
	
	system("title PENJUALAN BARANG ELEKTRONIK");	
	system("color f2");
	
	cout << setprecision(10);
	
	cout << "PENJUALAN BARANG ELEKTRONIK\n";
	cout << "==========================\n";
	
	cout << "Nama Barang:";
	cin >> namaBarang;
	
	cout << "Harga:";
	cin >> hargaBarang;
	
	cout << "Jumlah Jual:";
	cin >> jumlahJual;
	
	totalHarga = hargaBarang * jumlahJual;
	cout << "Total Harga: " << totalHarga << endl;
	
	diskon = totalHarga * 0.1;
	cout << "Diskon: " << diskon <<endl;
	
	totalBayar = totalHarga - diskon;
	cout << "Total Bayar: " << totalBayar <<endl;
	
	return 0;
}
