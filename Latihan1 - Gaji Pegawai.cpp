#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string namaPegawai, jabatanPegawai;
	float  gajiPegawai, pajakPegawai, pinjamanPegawai, gajiBersih;
	
	system("title GAJI KARYAWAN");	
	system("color f2");
	
	cout << setprecision(10);
	
	cout << "GAJI KARYAWAN STMIK PENUSA\n";
	cout << "==========================\n";
	
	cout << "Nama Pegawai:";
	cin >> namaPegawai;
	
	cout << "Jabatan Pegawai:";
	cin >> jabatanPegawai;
	
	cout << "Gaji Pokok:";
	cin >> gajiPegawai;
	
	cout << "Pinjaman:";
	cin >> pinjamanPegawai;
	
	pajakPegawai = gajiPegawai * 0.15;
	cout << "Pajak: " << pajakPegawai <<endl;
	
	gajiBersih = gajiPegawai  - (pajakPegawai + pinjamanPegawai);
	cout << "Total Gaji Bersih diterima: " << gajiBersih <<endl;
	
	return 0;
}
