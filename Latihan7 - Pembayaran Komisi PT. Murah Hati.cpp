#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
struct Akhir
{
	string huruf;
	int angka;
};

void spasi(int jenis, int awal, Akhir akhir)
{
	int digit;
	string spc;
	
	if (jenis == 0)
	{
		if( akhir.angka < 10) digit = 1;
		else if( akhir.angka < 100) digit = 2;
		else if( akhir.angka < 1000) digit = 3;
		else if( akhir.angka < 10000) digit = 4;
		else if( akhir.angka < 100000) digit = 5;
		else if( akhir.angka < 1000000) digit = 6;
		else digit = 7;
	}
	else
	{
		digit = akhir.huruf.length() - 1;
	}
	
	digit = awal -  digit - 1;
	
	for (int i = 0; i < digit; i++)
	{
		spc += " ";
	}
	
	cout << spc;
}

int main ()
{
	Akhir akhir;
	string sales[10];
	int urut = 0, penjualan[10], panjang = 10;
	float komisi1[10] = {0,0,0,0,0,0,0,0,0,0},
		  komisi2[10] = {0,0,0,0,0,0,0,0,0,0},
		  totalKomisi = 0;
	
	int jarak[3] =  { 13, 18, 74 };
	
	system("cls");
	system("title PEMBAYARAN KOMISI - PT MURAH HATI");
	
	cout << setprecision(10);
	cout << "======[ PT MURAH HATI ]======" << endl;
	cout << "=============================\n" << endl;
	cout << "Silahkan masukkan data" <<endl;
	
	while( urut < panjang )
	{
		cout << "Nama Sales ke-[" << (urut+1) << "]:"; cin >> sales[urut];
		cout << "Jumlah Penjualan:"; cin >> penjualan[urut];
		cout << "-----------------------------" << endl;
		
		// proses perhitungan
		if( penjualan[urut] >= 500000 )
		{
			komisi1[urut] = 500000 * 0.1;
			komisi2[urut] = ( penjualan[urut] - 500000 ) * 0.15;
			totalKomisi += (komisi1[urut] + komisi2[urut]);
		}
		
		urut++;
	}
	
	urut = 0;
	
	cout << "\n=============================" << endl;		
	cout << " - DATA PEMBAYARAN KOMISI - " << endl;
	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	cout << "| No.         | Nama Sales  | Jumlah Penjualan | Komisi 1    | Komisi 2    | Total Komisi     |\n";
	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	
	while( urut < panjang)
	{
		cout << "| " << (urut+1);
		akhir.angka = (urut+1);
		spasi(0, jarak[0], akhir );
		cout << "|";
		
		cout << "" << sales[urut];
		akhir.huruf = sales[urut];
		spasi(1, jarak[0], akhir);
		cout << "|";
		
		cout << " " << penjualan[urut];
		akhir.angka = penjualan[urut];
		spasi(0, jarak[1], akhir);
		cout << "|";
		
		cout << " " << komisi1[urut];
		akhir.angka = komisi1[urut];
		spasi(0, jarak[0], akhir);
		cout << "|";
		
		cout << " " << komisi2[urut];
		akhir.angka = komisi2[urut];
		spasi(0, jarak[0], akhir);
		cout << "|";
		
		cout << " " << komisi1[urut] + komisi2[urut];
		akhir.angka = komisi1[urut] + komisi2[urut];
		spasi(0, jarak[1], akhir);
		cout << "|" << endl;
		
		urut++;
	}

	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	string kata = "| Total Komisi Dibayarkan PT. MURAH HATI = ";
	cout << kata; //43
	akhir.huruf = kata;
	spasi(1, jarak[2], akhir);
	cout << " |";
	akhir.angka = totalKomisi;
	spasi(0, jarak[1], akhir);
	cout << totalKomisi;
	cout << " |" << endl;
	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	
	return 0;
}
