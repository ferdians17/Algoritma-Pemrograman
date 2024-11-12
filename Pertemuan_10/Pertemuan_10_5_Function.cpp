#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

float
	gajiPegawai(char golongan),
	pajakPegawai(float gaji),
	tunjanganPegawai(float gaji, char status, int anak);

void garis();

int main()
{
	int anak;
	char golongan, status;
	float gaji, gajiPokok, tunjangan, pajak;
	
	cout << setprecision(10);
	
	while(1)
	{
		cout << "Program Penghitung Gaji Karyawan \n";
		cout << "Untuk menghentikan program ketik (x) pada golongan \n";
		garis();
	
		cout << "Golongan Karyawan (A-C) & (x) untuk selesai \n";
		golongan = getche();
		
		if(golongan == 'x' || golongan == 'X')
		break;
		
		cout << "Status karyawan (N=Nikah & B=Belum) :\n";
		status = getche();
		
		if( status == 'N' || status == 'n')
		{
			cout << "Jumlah Anak:\n";
			cin >> anak;
		}
			gajiPokok = gajiPegawai(golongan);
			tunjangan = tunjanganPegawai(gajiPokok, status, anak);
			pajak = pajakPegawai(gajiPokok);
			gaji = gajiPokok + tunjangan - pajak;
			
			cout << "\n\n";
			cout << "Gaji Pokok = Rp." << gajiPokok << endl;
			cout << "Tunjangan = Rp." << tunjangan << endl;
			cout << "------------------------------------\n";
			cout << "Total = Rp. " << gajiPokok + tunjangan << endl;
			cout << "Pajak = Rp. " << pajak << endl;
			cout << "------------------------------------\n";
			cout << "Gaji Bersih = Rp. " << gaji << endl;
			cout << "------------------------------------\n";
			cout << "Tekan sembarang tombol \n";
			getch();
			
	}
	return 0;
}

void garis()
{
	for( int i=1; i <=50; i++) cout << "\xB1";
	cout << "\n\n";
}

float gajiPegawai( char golongan)
{
	switch(golongan)
	{
		case 'A':
		case 'a':
			return 50000;
		case 'B':
		case 'b':
			return 45000;
		case 'C':
		case 'c':
			return 35000;
		default:
			return 0;
	}
}

float tunjanganPegawai(float gaji, char status, int anak)
{
	float tunjanganAwal, tunjanganAkhir;
	if( status == 'B' || status == 'b' )
	{
		tunjanganAwal = 0;
		tunjanganAkhir = 0;
	}
	else if( status == 'N' || status == 'n' )
	{
		tunjanganAwal = 0.15 * gaji;
		tunjanganAkhir = anak > 3 ? 3 * .1 * gaji : anak * .1 * gaji;
	}
	return tunjanganAwal * tunjanganAkhir;
}

float pajakPegawai(float gaji)
{
	return gaji <= 96000 ? 0 : .15 * (gaji - 96000);
}