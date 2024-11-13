#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>

using namespace std;

struct dataKaryawan
{
	string
		nik,
		nama,
		alamat;
	float
		jamKerja,
		gajiPokok,
		uangLembur,
		uangMakan,
		uangJasa,
		totalGaji;
}karyawan[100];

void tampil(dataKaryawan karyawan[], int jumlah);

int main()
{
	int hit = 0,
        gaji = 2000,
        jam = 0;
	string lanjut = "y";
	
	system("title Aplikasi Gaji Karyawan");
	cout << setprecision(10);
	cout << "============================\n";
	cout << "===[ PT. Rezeki Nomplok ]===\n";
	cout << "============================\n\n";
	do
	{
		cout << "=====[ Data Karyawan ]=====\n";
		cout << setw(17) << left << "NIK" << ":";
		cin >> karyawan[hit].nik;
		
		cout << setw(17) << "Nama Karyawan" << ":";
		cin >> karyawan[hit].nama;
		
		cout << setw(17) << "Alamat" << ":";
		cin >> karyawan[hit].alamat;
		
		cout << setw(17) << "Jumlah Jam Kerja" << ":";
		cin >> jam;

        karyawan[hit].jamKerja = jam;
        karyawan[hit].gajiPokok = jam * gaji;
        karyawan[hit].uangLembur = 0;
        karyawan[hit].uangMakan = 0;
        karyawan[hit].uangJasa = 0;

        if( jam > 7)
        {
            karyawan[hit].gajiPokok = gaji * 7;
            karyawan[hit].uangLembur = (1.5 * gaji) * (jam - 7);
            
            if( jam  >= 8 && jam <= 10)
            {
                karyawan[hit].uangMakan = 1500;
            }
            else if( jam > 10)
            {
                karyawan[hit].uangMakan = 2500;
            }

            if( jam >= 9) karyawan[hit].uangJasa = 3000;

        }

        
        karyawan[hit].totalGaji = karyawan[hit].gajiPokok + karyawan[hit].uangLembur + karyawan[hit].uangMakan + karyawan[hit].uangJasa;
		
		cout << "---------------------------\n"	;	
		cout << "Lanjut (y) atau selesai (x) ? :";
		cin >> lanjut;
		cout << "\n";
		
		hit++;
	}
	while( lanjut == "Y" || lanjut == "y" );
	
	int jKaryawan = sizeof(karyawan) / sizeof(karyawan[0]);
	tampil(karyawan, jKaryawan);
	
	return 0;
}

void tampil(dataKaryawan karyawan[], int jumlah)
{
	cout << "+----------+---------------+---------------+----------+---------------+---------------+---------------+---------------+---------------+\n";
	cout << "|" << setw(10) << left << "NIK" << "|";
	cout << setw(15) << "Nama" << "|";
	cout << setw(15) << "Alamat" << "|";
	cout << setw(10) << "Jam Kerja" << "|";
	cout << setw(15) << "Gaji Pokok" << "|";
	cout << setw(15) << "Uang Lembur" << "|";
	cout << setw(15) << "Uang Makan" << "|";
	cout << setw(15) << "Uang Jasa" << "|";
	cout << setw(15) << "Total Gaji" << "|\n";
	cout << "+----------+---------------+---------------+----------+---------------+---------------+---------------+---------------+---------------+\n";

	for(int x=0; x < jumlah; x++)
	{
		if(karyawan[x].nik == "") break;
		cout << "|" << setw(10) << karyawan[x].nik << "|";
		cout << setw(15) << karyawan[x].nama << "|";
		cout << setw(15) << karyawan[x].alamat << "|";
		cout << setw(10) << karyawan[x].jamKerja << "|";
		cout << setw(15) << karyawan[x].gajiPokok << "|";
		cout << setw(15) << karyawan[x].uangLembur << "|";
		cout << setw(15) << karyawan[x].uangMakan << "|";
		cout << setw(15) << karyawan[x].uangJasa << "|";
		cout << setw(15) << karyawan[x].totalGaji << "|\n";
	}

	cout << "+----------+---------------+---------------+----------+---------------+---------------+---------------+---------------+---------------+\n";
}