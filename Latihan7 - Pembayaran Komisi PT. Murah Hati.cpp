#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void spasiHuruf(int panjang = 0)
{
	string spc = "";
	for (int i = 0; i < panjang; i++)
	{
		spc += " ";
	}
	
	cout << spc;
}

void spasiAngka(int jumlah, int panjang = 0)
{
	string spc = "";
	int digit;
	
	if( panjang < 10) digit = 1;
	else if( panjang < 100) digit = 2;
	else if( panjang < 1000) digit = 3;
	else if( panjang < 10000) digit = 4;
	else if( panjang < 100000) digit = 5;
	else if( panjang < 1000000) digit = 6;
	else digit = 7;
	
	digit = jumlah -  digit -1;
	
	for (int i = 0; i < digit; i++)
	{
		spc += " ";
	}
	
	cout << spc;
}

int main ()
{
	string sales[10];
	int urut = 0, penjualan[10];
	float komisi1[10] = {0,0,0,0,0,0,0,0,0,0},
		  komisi2[10] = {0,0,0,0,0,0,0,0,0,0},
		  totalKomisi = 0;
	
	int jarak[2] =  { 13, 18 };
	
	system("cls");
	system("title PEMBAYARAN KOMISI - PT MURAH HATI");
	
	cout << setprecision(10);
	cout << "======[ PT MURAH HATI ]======" << endl;
	cout << "=============================\n" << endl;
	cout << "Silahkan masukkan data" <<endl;
	
	while( urut < 10 )
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
	
	while( urut < 10)
	{
		cout << "| " << (urut+1);
		spasiAngka(jarak[0], urut+1);
		cout << "|";
		
		cout << " " << sales[urut];
		spasiHuruf(jarak[0] - sales[urut].length() - 1);
		cout << "|";
		
		cout << " " << penjualan[urut];
		spasiAngka(jarak[1], penjualan[urut]);
		cout << "|";
		
		cout << " " << komisi1[urut];
		spasiAngka(jarak[0], komisi1[urut]);
		cout << "|";
		
		cout << " " << komisi2[urut];
		spasiAngka(jarak[0], komisi2[urut]);
		cout << "|";
		
		cout << " " << komisi1[urut] + komisi2[urut];
		spasiAngka(jarak[1], komisi1[urut] + komisi2[urut]);
		cout << "|"<< endl;
		
		urut++;
	}

	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	cout << "| Total Komisi Dibayarkan PT. MURAH HATI = ";
	spasiHuruf(32);
	cout << "|";
	spasiAngka(18, totalKomisi);
	cout << totalKomisi;
	cout << " |" << endl;
	cout << "+-------------+-------------+------------------+-------------+-------------+------------------+ \n";
	
	return 0;
}
