#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X =x;
	coord.Y =y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct mahasiswa
{
	char npm[9];
	char nama[20];
	char nHuruf;
	int nMid;
	int nSem;
	int nAkhir;
} mhs[100];

int main()
{
	char input = 'y';
	int i = 0, n = 0;
	
	system("title Data Nilai Ujian Pemrograman C++");
	
	cout << "+===================================+\n";
	cout << "| DATA NILAI UJIAN PEMROGRAMAN C++  |\n";
	cout << "|==============[DOSEN]==============|\n";
	cout << "| JAKARIA SEMBIRING, S.KOM., M.KOM. |\n";
	cout << "+===================================+\n";
	
	while( input == 'Y' || input == 'y')
	{
		cout << "-----------------\n";
		cout << "Input Nilai Ujian\n";
		cout << "-----------------\n";
		
		cout << setw(20) << left << "NPM" << ":";
		gets(mhs[n].npm);
		
		cout << setw(20) << "Nama Lengkap" << ":";
		gets(mhs[n].nama);
		
		cout << setw(20) << "Nilai Mid Semester" << ":";
		cin >> mhs[n].nMid;
		
		cout << setw(20) << "Nilai Semester" << ":";
		cin >> mhs[n].nSem;
		
		mhs[n].nAkhir = (0.4 * mhs[n].nMid) + (0.6 * mhs[n].nSem);
		
		if(mhs[n].nAkhir >= 80 && mhs[n].nAkhir <= 100) mhs[n].nHuruf = 'A';
		else if(mhs[n].nAkhir >= 70 && mhs[n].nAkhir <= 79) mhs[n].nHuruf = 'B';
		else if(mhs[n].nAkhir >= 55 && mhs[n].nAkhir <= 59) mhs[n].nHuruf = 'C';
		else if(mhs[n].nAkhir >= 40 && mhs[n].nAkhir <= 54) mhs[n].nHuruf = 'D';
		else mhs[n].nHuruf = 'E';
		
		
		cout << setw(20) << "Nilai Akhir" << ":" << mhs[n].nAkhir << endl;
		cout << setw(20) << "Nilai Huruf" << ":" << mhs[n].nHuruf << endl;
		
		n++;
		
		cout << "Ingin melanjutkan? (y/t):"; cin >> input;
		cout << endl;
		cin.ignore();
	}
	
	system("cls");

	cout << "+===================================+\n";
	cout << "| DATA NILAI UJIAN PEMROGRAMAN C++  |\n";
	cout << "|==============[DOSEN]==============|\n";
	cout << "| JAKARIA SEMBIRING, S.KOM., M.KOM. |\n";
	cout << "+===================================+\n";
	
	gotoxy(1,7); cout << "+-----+---------------+---------------+---------------+---------------+---------------+---------------+\n";
	gotoxy(1,8); cout << "| No. | NPM           | NAMA LENGKAP  | NILAI MID     | NILAI SEMESTER| NILAI AKHIR   | NILAI HURUF   |\n";
	gotoxy(1,9); cout << "+-----+---------------+---------------+---------------+---------------+---------------+---------------+\n";
	
	for(i = 0; i < n; i++)
	{
		gotoxy(1, (10+i)); cout << "|" << (i+1);
		gotoxy(7, (10+i)); cout << "|" << mhs[i].npm;
		gotoxy(23, (10+i)); cout << "|" << mhs[i].nama;
		gotoxy(39, (10+i)); cout << "|" << mhs[i].nMid;
		gotoxy(55, (10+i)); cout << "|" << mhs[i].nSem;
		gotoxy(71, (10+i)); cout << "|" << mhs[i].nAkhir;
		gotoxy(87, (10+i)); cout << "|" << mhs[i].nHuruf;
		gotoxy(103, (10+i)); cout << "|\n";
	}
	gotoxy(1,10+i); cout << "+-----+---------------+---------------+---------------+---------------+---------------+---------------+\n";
	
	return 0;
}
