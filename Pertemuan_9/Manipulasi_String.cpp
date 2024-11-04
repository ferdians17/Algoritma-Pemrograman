#include <iostream>
#include <conio.h>
#include <string>

/*
Pertemuan 9
Membahas mengenai penggunaan fungsi manipulasi string/text
dimana ada:
	sizeof(text) untuk menghitung jumlah karakter dalam memory
	str + str yang digunakan untuk menggabungkan lebih dari 1 string (concantenated)
	string.length() digunakan untuk menghitung jumlah karakter yang ada pada string.
	string.substr(awal,akhir) digunakan untuk mengambil sebagian text dengan posisi yang telah ditentukan
	string.find() digunakan untuk mencari posisi sebelum text yang dicari
	string.replace(awal,akhir,perubahan) digunakan untuk merubah kata yang ada di dalam string
*/
using namespace std;

int main()
{
	string awal, akhir, hasil, kosong;
	size_t panjang;
	awal = "STMIK";
	akhir = "PENUSA";
	
	//penggabungan text / string concatenated
	hasil = awal + " " + akhir;	
	cout << "Nama Kampus : " + awal + " " + akhir << endl;
	cout << "Nama Kampus : " + hasil << endl;
	
	//panjang karakter /length
	panjang = hasil.length();
	cout << "Panjang karakter dari awal dan akhir adalah : " << panjang << endl;
	
	//mengambil sebagian text / substring
	kosong = hasil.substr(6,6);
	cout << "Karakter ke 7 - ke 12 dari \"" << hasil << "\" adalah \"" << kosong << "\"\n";
	
	//mencari posisi text / find
	panjang = hasil.find("PEN");
	cout << "Jumlah karakter sebelum Posisi kata \"PEN\" dalam \"" << hasil << "\" adalah : " << panjang << endl;
	
	//mengganti text / replace
	kosong = hasil;
	kosong.replace(0,5,"Hi"); // kata STMIK pada posisi 0-5 akan diubah menjadi Hi
	cout << "Kata \"" << hasil << "\" akan diubah menjadi \"" << kosong << "\"\n";
	
//	char nama[20], alamat[35];
//	
//	cout << "Masukkan Nama Anda :";
//	cin.getline(nama, sizeof(nama));
//	
//	cout << "Masukkan Alamat Anda :";
//	cin.getline(alamat, sizeof(alamat));
//	
//	cout << "Nama Anda adalah : " << nama << endl;
//	cout << "Alamat Anda adalah : " << alamat << endl;

	return 0;
}
