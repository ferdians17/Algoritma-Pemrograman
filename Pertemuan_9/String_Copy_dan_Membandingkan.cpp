#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>

/*
Pertemuan 9
	strcmp	=> compare / membandingkan nilai 2 buah string
	strcpy	=> mengkopi string kedalam sebuah string
	Long 	=>type data yang menampung sampai 1 triliun
*/
using namespace std;

int main()
{
	char kd[3], nama[20] = "";
	float harga=0;
	int jumlah,hasil = 0;
	long totalHarga;
	
	cout << "Penjualan Komputer STMIK PENUSA\n";
	cout << "-------------------------------\n";
	
	cout << "Input kode :";
	cin >> kd;
	
	hasil = strcmp(kd,"PII");
	if(hasil == 0)
	{
		strcpy(nama, "Komp PENTIUM II");
		harga = 1500000;
	}
	
	hasil = strcmp(kd,"PIII");
	if(hasil == 0)
	{
		strcpy(nama, "Komp PENTIUM III");
		harga = 2500000;
	}
	
	hasil = strcmp(kd,"PIV");
	if(hasil == 0)
	{
		strcpy(nama, "Komp PENTIUM IV");
		harga = 3500000;
	}
	
	cout << "Jumlah Jual:";
	cin >> jumlah;
	totalHarga =  jumlah * harga;
	
	cout << "Total Harga :" << setw(9) << totalHarga << endl;
	cout << "-----------------------------------------------\n";	

	return 0;
}
