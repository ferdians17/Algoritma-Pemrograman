#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int main()
{
	struct lokal
	{
		string nama;
		char jurusan[50],  kode[50];
		int npm, awal, cicilan, besaran, uangKuliah, bayar, terbayar, sisa;
	} lok[100];

	int	i = 0;
	char entry = 'y';
		
	cout << setprecision(10);
	system("cls");
	system("title PEMBAYARAN UANG KULIAH");
	
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
	cout << "======================================" << endl;
	cout << "======[ PEMBAYARAN UANG KULIAH ]======" << endl;
	cout << "======[ STMIK PELITA NUSANTARA ]======" << endl;
	cout << "======================================\n" << endl;
	
//	BAGIAN INPUT DATA MAHASISWA
	while(entry == 'Y' || entry == 'y')
	{
		cout << "============[ Data Mahasiswa ]============\n";
		cout << " Perhatikan!!!\n Gunakan gaya penulisan\n huruf besar semua atau kecil semua\n";
		cout << "------------------------------------------\n";
		
		cout << setw(30) << "Nama Mahasiswa" << ":"; cin >> lok[i].nama;
		cout << setw(30) <<  "Nomor Pokok Mahasiswa (NPM)" << ":"; cin >> lok[i].npm;
		cout << setw(30) <<  "Kode Jurusan" << ":"; cin >> lok[i].kode;
		
		if( strcmp(lok[i].kode, "SI") == 0 || strcmp(lok[i].kode, "si") == 0)
		{
			strcpy(lok[i].jurusan, "Sistem Informasi");
			lok[i].awal = 2100000;
			lok[i].cicilan = 7;
			lok[i].besaran = 300000;
			lok[i].uangKuliah = lok[i].awal + (lok[i].cicilan * lok[i].besaran);
		}		
		else if( strcmp(lok[i].kode, "TI") == 0 || strcmp(lok[i].kode, "ti") == 0)
		{
			strcpy(lok[i].jurusan, "Teknik Informatika");
			lok[i].awal = 2500000;
			lok[i].cicilan = 7;
			lok[i].besaran = 300000;
			lok[i].uangKuliah = lok[i].awal + (lok[i].cicilan * lok[i].besaran);
		}		
		else if( strcmp(lok[i].kode, "KA") == 0 || strcmp(lok[i].kode, "ka") == 0)
		{
			strcpy(lok[i].jurusan, "Komputer Akuntansi");
			lok[i].awal = 1750000;
			lok[i].cicilan = 6;
			lok[i].besaran = 200000;
			lok[i].uangKuliah = lok[i].awal + (lok[i].cicilan * lok[i].besaran);
		}		
		else if( strcmp(lok[i].kode, "MI") == 0 || strcmp(lok[i].kode, "mi") == 0)
		{
			strcpy(lok[i].jurusan, "Manajemen Informatika");
			lok[i].awal = 1500000;
			lok[i].cicilan = 6;
			lok[i].besaran = 250000;
			lok[i].uangKuliah = lok[i].awal + (lok[i].cicilan * lok[i].besaran);
		}		
		else
		{
			strcpy(lok[i].jurusan, "Tidak Terdaftar");
			lok[i].awal = 0;
			lok[i].cicilan = 0;
			lok[i].besaran = 0;
			lok[i].uangKuliah = lok[i].awal + (lok[i].cicilan * lok[i].besaran);
		}
		
		cout << setw(30) << "Jurusan" << ":" << lok[i].jurusan << endl;
		cout << setw(30) << "Pembayaran Awal" << ":Rp." << lok[i].awal << endl;
		cout << setw(30) << "Jumlah Cicilan" << ":" << lok[i].cicilan << endl;
		cout << setw(30) << "Besar Cicilan" << ":Rp." << lok[i].besaran << endl;
		
		if( strcmp(lok[i].jurusan, "Tidak Terdaftar") == 0) lok[i].bayar == 0;
		else
		{
			cout << setw(30) << "Pembayaran Ke-" << ":";
			cin >> lok[i].bayar;
		}
		
		if(lok[i].bayar <= lok[i].cicilan)
		{
			lok[i].terbayar = lok[i].awal + (lok[i].bayar * lok[i].besaran);
			lok[i].sisa = lok[i].uangKuliah - lok[i].terbayar;
		}
		else
		{
			lok[i].terbayar = lok[i].uangKuliah;
			lok[i].sisa = 0;
		}
		
		cout << setw(30) << "Uang Kuliah" << ":Rp." << lok[i].uangKuliah << endl;
		cout << setw(30) << "Uang Kuliah Terbayar" << ":Rp." << lok[i].terbayar << endl;
		cout << setw(30) << "Sisa Uang Kuliah" << ":Rp." << lok[i].sisa << endl;
		cout << setw(30) << "Masih ingin menghitung [Y/T]" << ":"; cin >> entry;
		i++;
	}
	
	cout << "============[ SELESAI ]============\n";	
	cout << "+-----+----------+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
	cout << "|" << setw(5) << left << "No." << "|" << setw(10) << "NPM" << "|" << setw(25) << "Mahasiswa" << "|" << setw(21) << "Jurusan" << "|" << setw(20) << "Uang Kuliah" << "|";
	cout << setw(20) << "Sudah Dibayar" << "|" << setw(20) << "Belum Dibayar" << "|\n";
	cout << "+-----+----------+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
		
	for(int g=0; g < i; g++)
	{
		cout << "|" << setw(5) << left << g+1 << "|" << setw(10) << lok[g].npm << "|" << setw(25) << lok[g].nama << "|" << setw(21) << lok[g].jurusan << "|" << setw(20) << lok[g].uangKuliah << "|";
		cout << setw(20) << lok[g].terbayar << "|" << setw(20) << lok[g].sisa << "|\n";
	}
	
	cout << "+-----+----------+-------------------------+---------------------+--------------------+--------------------+--------------------+\n";
	
	return 0;
}
