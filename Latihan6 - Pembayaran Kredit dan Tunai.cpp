#include <iostream>
#include <iomanip>
#include <string>
//#include <stdio.h>

using namespace std;

// inisialisasi pemanggilan menu
int menu();

int main()
{
	// tentukan data pembeli yang dapat koleksi
	char
		pilihTipe,
		pilihMetode,
		keluar;
		
	string namaPelanggan;
	
	int
		usiaPelanggan,
		gajiPelanggan,
		hargaKredit = 0,
		totalHarga = 0,
		
	//jumlah bulan dalam 10 tahun ( 12 bulan dikali 10 tahun
		lamaKredit = 120;
		
	label:
	
	//panggil menu yang dibuat terpisah
	menu();
	
	//masukkan data pelanggan
	cout << setprecision(12);
	
	cout << "Nama Pelanggan:";
	cin >> namaPelanggan;
	
	cout << "Usia Pelanggan:";
	cin >> usiaPelanggan;
	
	cout << "Gaji Pelanggan:";
	cin >> gajiPelanggan;
	
	// rumah yang dipilih
	cout << "Tipe Rumah:";
	cin >> pilihTipe;
	
	cout << "Metode Pembayaran:";
	cin >> pilihMetode;
	
	switch(pilihTipe)
	{
		case 'A':
		case 'a':
			totalHarga = 50000000;
			hargaKredit = 500000;
			break;
			
		case 'B':
		case 'b':
			totalHarga = 75000000;
			hargaKredit = 750000;
			break;
			
		case 'C':
		case 'c':
			totalHarga = 85000000;
			hargaKredit = 850000;
			break;
			
		case 'D':
		case 'd':
			totalHarga = 100000000;
			hargaKredit = 1000000;
			break;
		
		default:
			cout << "Tipe Rumah tidak ditemukan! \n";
			break;
	}
	
	if( pilihMetode == 'T' || pilihMetode == 't')
	{
		cout << "===========================================================\n";
		cout << "==============| Detail Pembayaran |========================\n\n";
		cout << "Metode Pembayaran [Tunai] dipilih\n";
		cout << "Total Harga Rumah harus dibayar Rp." << totalHarga << endl;
		cout << "\n\n===========================================================\n";
	}
	else if( pilihMetode == 'K' || pilihMetode == 'k')
	{
		totalHarga = lamaKredit * hargaKredit;
		cout << "===========================================================\n";
		cout << "==============| Detail Pembayaran |========================\n\n";
		cout << "Metode Pembayaran [Kredit] dipilih\n";
		cout << "Angsuran Perbulan Rp." << hargaKredit << endl;
		cout << "Total Harga Rumah harus dibayar Rp." << totalHarga << endl;
		cout << "\n\n===========================================================\n";
	}
	else cout << "Pilih Metode Pembayaran yang disetujui T = Tunai dan K = Kredit \n";
	
	cout << "Lanjut [Y], Selesai [X] :";
	cin >> keluar;
	
	if(keluar =='Y' || keluar == 'y')
	{
		goto label;
	}
	
	return 0;
}

// isi menu yang ditampilkan berulang.
int menu()
{
	system("title PT. PERUMAHAN RAKYAT");
	system("cls");
	cout << "===========================================================\n";
	cout << "PT. PERUMAHAN RAKYAT \n";
	cout << "===========================================================\n";
	cout << "Kami menjual 4 Tipe Rumah Tinggal sebagai berikut: \n\n";
	cout << "TIPE \t HARGA TUNAI (T) \t HARGA KREDIT (K) \n";
	cout << "A \t Rp. 50.000.000 \t Rp. 500.000 \n";
	cout << "B \t Rp. 75.000.000 \t Rp. 750.000 \n";
	cout << "C \t Rp. 85.000.000 \t Rp. 850.000 \n";
	cout << "D \t Rp. 100.000.000 \t Rp. 1.000.000 \n\n";
	cout << "Tekan [CTRL + C] untuk keluar\n";
	cout << "===========================================================\n";
}
