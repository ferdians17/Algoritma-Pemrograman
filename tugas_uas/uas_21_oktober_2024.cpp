#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

void katalog()
{
	cout << "+-----+--------------------+--------------------+--------------------+--------------------+\n";
	cout << "|" << setw(5) << left << "Kode" << "|" << setw(20) << "Jurusan" << "|" << setw(20) << "Pembayaran Awal" << "|";
	cout << setw(20) << "Jumlah Cicilan" << "|" << setw(20) << "Besar Cicilan" << "|\n";
	cout << "+-----+--------------------+--------------------+--------------------+--------------------+\n";
	
	cout << "|" << setw(5) << "SI" << "|" << setw(20) << "Sistem Informasi" << "|" << setw(20) << "2.100.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "|" << setw(5) << "SI" << "|" << setw(20) << "Sistem Informasi" << "|" << setw(20) << "2.100.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "|" << setw(5) << "SI" << "|" << setw(20) << "Sistem Informasi" << "|" << setw(20) << "2.100.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "|" << setw(5) << "SI" << "|" << setw(20) << "Sistem Informasi" << "|" << setw(20) << "2.100.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "+-----+--------------------+--------------------+--------------------+--------------------+\n";
}

int main()
{
	string nama[100],
		   jurusan[100],
		   kode[100];
	int	npm[100],
		awal[100],
		cicilan[100],
		besaran[100],
		uangKuliah[100],
		bayar[100],
		terbayar[100],
		sisa[100],
		i = 0;
	char entry = 'y';
		
	cout << setprecision(10);
	
	system("cls");
	system("title PEMBAYARAN UANG KULIAH");
	cout << "======================================" << endl;
	cout << "======[ PEMBAYARAN UANG KULIAH ]======" << endl;
	cout << "======[ STMIK PELITA NUSANTARA ]======" << endl;
	cout << "======================================\n" << endl;
	
	katalog();
	
//	BAGIAN INPUT DATA MAHASISWA
	while(entry == 'Y' || entry == 'y')
	{
		cout << "============[ Data Mahasiswa ]============\n";
		cout << setw(30) << "Nama Mahasiswa" << ":"; cin >> nama[i];
		cout << setw(30) <<  "Nomor Pokok Mahasiswa (NPM)" << ":"; cin >> npm[i];
		cout << setw(30) <<  "Kode Jurusan" << ":"; cin >> kode[i];
		
		if(kode[i] == "SI")
		{
			jurusan[i] = "Sistem Informasi";
			awal[i] = 2100000;
			cicilan[i] = 7;
			besaran[i] = 300000;
			uangKuliah[i] = awal[i] + (cicilan[i] * besaran[i]);
		}
		
		cout << setw(30) << "Jurusan" << ":" << jurusan[i] << endl;
		cout << setw(30) << "Pembayaran Awal" << ":Rp." << awal[i] << endl;
		cout << setw(30) << "Jumlah Cicilan" << ":" << cicilan[i] << endl;
		cout << setw(30) << "Besar Cicilan" << ":Rp." << besaran[i] << endl;
		
		cout << setw(30) << "Pembayaran Ke-" << ":"; cin >> bayar[i];
		
		if(bayar[i] <= cicilan[i])
		{
			terbayar[i] = awal[i] + (bayar[i] * besaran[i]);
			sisa[i] = uangKuliah[i] - terbayar[i];
		}
		else
		{
			terbayar[i] = uangKuliah[i];
			sisa[i] = 0;
		}
		
		cout << setw(30) << "Uang Kuliah" << ":Rp." << uangKuliah[i] << endl;
		cout << setw(30) << "Uang Kuliah Terbayar" << ":" << terbayar[i] << endl;
		cout << setw(30) << "Sisa Uang Kuliah" << ":" << sisa[i] << endl;
		
		cout << "Masih ingin menghitung [Y/T] :"; cin >> entry;
		
		i++;
	}
	
	cout << "============[ SELESAI ]============\n";
	
	return 0;
}
