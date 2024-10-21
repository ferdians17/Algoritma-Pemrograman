#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

void katalog()
{
	cout << "+-----+---------------------+--------------------+--------------------+--------------------+\n";
	cout << "|" << setw(5) << left << "Kode" << "|" << setw(21) << "Jurusan" << "|" << setw(20) << "Pembayaran Awal" << "|";
	cout << setw(20) << "Jumlah Cicilan" << "|" << setw(20) << "Besar Cicilan" << "|\n";
	cout << "+-----+---------------------+--------------------+--------------------+--------------------+\n";
	
	cout << "|" << setw(5) << "SI" << "|" << setw(21) << "Sistem Informasi" << "|" << setw(20) << "2.100.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "|" << setw(5) << "TI" << "|" << setw(21) << "Teknik Informatika" << "|" << setw(20) << "2.500.000" << "|";
	cout << setw(20) << "7" << "|" << setw(20) << "300.000" << "|\n";
	
	cout << "|" << setw(5) << "KA" << "|" << setw(21) << "Komputer Akuntansi" << "|" << setw(20) << "1.750.000" << "|";
	cout << setw(20) << "6" << "|" << setw(20) << "200.000" << "|\n";
	
	cout << "|" << setw(5) << "MI" << "|" << setw(21) << "Manajemen Informatika" << "|" << setw(20) << "1.500.000" << "|";
	cout << setw(20) << "6" << "|" << setw(20) << "250.000" << "|\n";
	
	cout << "+-----+---------------------+--------------------+--------------------+--------------------+\n";
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
		ulang:
		cout << setw(30) <<  "Kode Jurusan" << ":"; cin >> kode[i];

		transform(kode[i].begin(), kode[i].end(), kode[i].begin(), ::toupper);
		
		if(kode[i] == "SI")
		{
			jurusan[i] = "Sistem Informasi";
			awal[i] = 2100000;
			cicilan[i] = 7;
			besaran[i] = 300000;
			uangKuliah[i] = awal[i] + (cicilan[i] * besaran[i]);
		}		
		else if(kode[i] == "TI")
		{
			jurusan[i] = "Teknik Informatika";
			awal[i] = 2500000;
			cicilan[i] = 7;
			besaran[i] = 300000;
			uangKuliah[i] = awal[i] + (cicilan[i] * besaran[i]);
		}		
		else if(kode[i] == "KA")
		{
			jurusan[i] = "Komputer Akuntansi";
			awal[i] = 1750000;
			cicilan[i] = 6;
			besaran[i] = 200000;
			uangKuliah[i] = awal[i] + (cicilan[i] * besaran[i]);
		}		
		else if(kode[i] == "MI")
		{
			jurusan[i] = "Manajemen Informatika";
			awal[i] = 1500000;
			cicilan[i] = 6;
			besaran[i] = 250000;
			uangKuliah[i] = awal[i] + (cicilan[i] * besaran[i]);
		}
		else goto ulang;
		
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
		cout << setw(30) << "Uang Kuliah Terbayar" << ":Rp." << terbayar[i] << endl;
		cout << setw(30) << "Sisa Uang Kuliah" << ":Rp." << sisa[i] << endl;
		
		cout << setw(30) << "Masih ingin menghitung [Y/T]" << ":"; cin >> entry;
		
		i++;
	}
	
	cout << "============[ SELESAI ]============\n";
		
		cout << "+-----+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
		cout << "|" << setw(5) << left << "No." << "|" << setw(25) << "Mahasiswa" << "|" << setw(21) << "Jurusan" << "|" << setw(20) << "Uang Kuliah" << "|";
		cout << setw(20) << "Sudah Dibayar" << "|" << setw(20) << "Belum Dibayar" << "|\n";
		cout << "+-----+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
		
	for(int g=0; g < i; g++)
	{
		cout << "|" << setw(5) << left << g+1 << "|" << setw(25) << nama[g] << "|" << setw(21) << jurusan[g] << "|" << setw(20) << uangKuliah[g] << "|";
		cout << setw(20) << terbayar[g] << "|" << setw(20) << sisa[g] << "|\n";
	}
	
		cout << "+-----+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
	
	return 0;
}
