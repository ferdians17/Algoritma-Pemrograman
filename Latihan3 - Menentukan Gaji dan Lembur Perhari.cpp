#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string namaPegawai,
		   jabatanPegawai;
		   
	int gajiPerjam = 500;
	
	float jamKerja,
		  totalGaji,
		  totalLembur;
		  
	cout << "Nama Pegawai: ";
	cin >>  namaPegawai;
		  
	cout << "Jabatan Pegawai: ";
	cin >>  jabatanPegawai;
	
	cout << "Jumlah jam Kerja:";
	cin >> jamKerja;
	
	if (jamKerja > 7)
	{
		totalLembur = jamKerja - 7;
		totalGaji	=  (gajiPerjam * 7) + (totalLembur * 1.5 * gajiPerjam);
		cout << "Jumlah jam Lembur:" << totalLembur << "\n";
	}
	else totalGaji = gajiPerjam * jamKerja;
	
	cout << "Total Gaji Harian Pegawai: " << totalGaji;
	
	return 0;
}
