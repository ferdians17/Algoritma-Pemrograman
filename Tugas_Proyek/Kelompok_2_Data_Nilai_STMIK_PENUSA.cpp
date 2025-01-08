#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <commctrl.h>
#include <cstdlib>
#include <stdlib.h>

#define login 1100
#define loginProses 1101
#define register 1200
#define registerProses 1201
#define logout 1003

#define mahasiswaAdd 2100
#define mahasiswaSave 2101
#define mahasiswaData 2200

#define nilaiAdd 3100
#define nSearch 3101
#define nilaiSave 3102
#define nilaiData 3200

#define about 5000
#define exit 6000

using namespace std;

//tentukan proses
LRESULT CALLBACK proses(HWND, UINT, WPARAM, LPARAM);
//tentukan menu
void daftarMenu(HWND hw);

//daftar konten
void cls(HWND);
void _login(HWND);
void _register(HWND);

void _mahasiswaAdd(HWND);
void _dataMahasiswa(HWND hw, int tinggi);
void _kolomMahasiswa(HWND hw);
void _barisMahasiswa(HWND hw);


void _dataNilai(HWND);
void _kolomNilai(HWND);
void _barisNilai(HWND);

void _nilaiAdd(HWND);
void _nilaiSave(HWND);

void _about(HWND);

HWND inputUser, inputPass;
HWND inputNPM, inputNama, inputProgram;
HWND nNama, nProgram, nilaiKode, nilaiMatkul, nilaiSemester, nilaiTugas,
	 nilaiQuiz, nilaiUTS, nilaiUAS;

struct admin
{
	string username, password;
} Admin[3];

struct mahasiswa
{
	string npm, nama, program;
} Mahasiswa[100];

struct nilai
{
	string npm, kode, mataKuliah, semester;
	char huruf;
	float tugas, quiz, uts, uas, akhir;
} Nilai[100];

int adminCount,
	mahasiswaCount,
	nilaiCount;

INT WINAPI WinMain(HINSTANCE hi, HINSTANCE hs, LPSTR pr, int cmd)
{   
	Admin[adminCount].username = "admin";
	Admin[adminCount].password = "admin";
	adminCount++;
	
	WNDCLASS wc = {};
	
	wc.hInstance = hi;
	wc.lpfnWndProc = proses;
	wc.lpszClassName = "data_nilai";
	wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	
	if( !RegisterClass(&wc)) return 0;
	
	HWND hw = CreateWindow(
		"data_nilai",
		"Data Nilai STMIK Pelita Nusantara",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		960,
		600,
		NULL, NULL, NULL, NULL
	);
	
	ShowWindow(hw, cmd);
	MSG pesan = {};
	
	while( GetMessage(&pesan, NULL, NULL, NULL))
	{
		TranslateMessage(&pesan);
		DispatchMessage(&pesan);
	}
	
	return 0;
}

//proses yang dijalankan
LRESULT CALLBACK proses(HWND hw, UINT pesan, WPARAM wp, LPARAM lp)
{ 
	
	 switch( pesan )
	 {
	 	case WM_CREATE:
	 	{
		 	daftarMenu(hw);
	 		_login(hw);
	 	}
	 		break;
	 	
	 	case WM_COMMAND:
	 		switch(wp)
	 		{
	 			case login:
	 				_login(hw);
	 				break;
	 				
	 			case loginProses:
	 			{
	 				char username[100], password[100];
	 				bool hasil = false;
	 				GetWindowText(inputUser, username, 100);
	 				GetWindowText(inputPass, password, 100);
	 				
	 				for(int i=0; i < adminCount; i++)
	 				{
	 					if(strcmp(username, Admin[i].username.c_str()) == 0 && strcmp(password, Admin[i].password.c_str()) == 0)
	 					{
	 						hasil = true;
						}
					}
					
	 				if( hasil)
	 				{
	 					MessageBox(hw, "Selamat berhasil masuk", "Success", MB_OK | MB_ICONINFORMATION);
					}
					else {
	 					MessageBox(hw, "Acccess Denied, Login Failed!", "Access Denied", MB_OK | MB_ICONERROR);
					}
	 				break;
				}
	 				
	 			case register:
	 				_register(hw);
	 				break;
	 				
	 			case registerProses:
	 			{
	 				char username[100], password[100];
	 				GetWindowText(inputUser, username, 100);
	 				GetWindowText(inputPass, password, 100);
	 				
	 				if(adminCount < 3)
	 				{
		 				Admin[adminCount].username = username;
		 				Admin[adminCount].password = password;
		 				adminCount++;
						MessageBox(hw, "Permintaan telah di proses", "Info", MB_OK | MB_ICONINFORMATION);
						SendMessage(hw, WM_COMMAND, login, 0);
					}
					else MessageBox(hw, "Jumlah Admin melebihi batas!", "Access Denied", MB_OK | MB_ICONERROR);
				}
	 				break;
	 				
	 			case mahasiswaAdd:
	 			{
	 				_mahasiswaAdd(hw);
	 			}
	 				break;
	 				
	 			case mahasiswaSave:
	 			{
	 				char npm[100], nama[100], program[100];
	 				GetWindowText(inputNPM, npm, 100);
	 				GetWindowText(inputNama, nama, 100);
	 				GetWindowText(inputProgram, program, 100);
	 				
	 				if(adminCount < 100)
	 				{
		 				Mahasiswa[mahasiswaCount].npm = npm;
		 				Mahasiswa[mahasiswaCount].nama = nama;
		 				Mahasiswa[mahasiswaCount].program = program;
		 				mahasiswaCount++;
						MessageBox(hw, "Permintaan telah di proses", "Info", MB_OK | MB_ICONINFORMATION);
						SendMessage(hw, WM_COMMAND, mahasiswaData, 0);
					}
					else MessageBox(hw, "Jumlah Mahasiswa melebihi batas!", "Access Denied", MB_OK | MB_ICONERROR);
				}
	 				break;
	 				
	 			case mahasiswaData:
	 			{
	 				_dataMahasiswa(hw, 10);
	 			}
	 				break;
	 				
	 			case nilaiAdd:
	 			{
	 				_nilaiAdd(hw);
	 			}
	 				break;
	 			
	 			case nilaiSave:
	 			{
	 				_nilaiSave(hw);
				}
					break;
	 				
	 			case nSearch:
	 			{
	 				char nama[100], program[100], npm[100];
	 				GetWindowText(inputNPM, npm, 100);
	 				
	 				_nilaiAdd(hw);
	 				
	 				for(int no=0; no <= mahasiswaCount; no++)
	 				{
	 					if(strcmp(npm, Mahasiswa[no].npm.c_str()) == 0)
	 					{
			 				SetWindowText(inputNPM, Mahasiswa[no].npm.c_str());
			 				SetWindowText(nNama, Mahasiswa[no].nama.c_str());
			 				SetWindowText(nProgram, Mahasiswa[no].program.c_str());
			 			}
	 				}
	 			}
	 				break;
	 				
	 			case nilaiData:
	 			{
	 				_dataNilai(hw);
	 			}
	 				break;
	 				
	 			case about:
	 				_about(hw);
	 				break;
	 				
	 			case exit:
	 				DestroyWindow(hw);
	 				break;
			}
	 		break;
	 		
	 	case WM_DESTROY:
	 		PostQuitMessage(0);
	 		break;
	 		
	 	default:
	 		DefWindowProc(hw, pesan, wp, lp);
	 		break;
	 }
}

//daftar menu
void daftarMenu(HWND hw)
{
	HMENU menu = CreateMenu();
	
	HMENU admin = CreateMenu();
	AppendMenu(admin, MF_STRING, login, "Login");
	AppendMenu(admin, MF_STRING, register, "Register");
	AppendMenu(admin, MF_SEPARATOR, NULL, NULL);
	AppendMenu(admin, MF_STRING, logout, "Logout");
	
	HMENU mahasiswa = CreateMenu();
	AppendMenu(mahasiswa, MF_STRING, mahasiswaAdd, "Add Mahasiswa");
	AppendMenu(mahasiswa, MF_STRING, mahasiswaData, "Data Mahasiswa");
	
	HMENU nilai = CreateMenu();
	AppendMenu(nilai, MF_STRING, nilaiAdd, "Add Nilai");
	AppendMenu(nilai, MF_STRING, nilaiData, "Data Nilai");

	AppendMenu(menu, MF_POPUP, (UINT_PTR)admin, "ADMIN");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)mahasiswa, "MAHASISWA");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)nilai, "NILAI");
	AppendMenu(menu, MF_POPUP, NULL, "PRINT");
	AppendMenu(menu, MF_POPUP, about, "ABOUT US");
	AppendMenu(menu, MF_POPUP, exit, "Exit");
	
	SetMenu(hw, menu);
}

//pindah layar baru
void cls(HWND hw) {
	HWND baru = GetWindow(hw, GW_CHILD);
	while (baru) {
		HWND lanjut = GetWindow(baru, GW_HWNDNEXT);
		DestroyWindow(baru);
		baru = lanjut;
	}
}

void _login(HWND hw)
{
	cls(hw);
	CreateWindow("static", "ADMINISTRATOR", WS_VISIBLE | WS_CHILD | SS_CENTER,330,10,240,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Username :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,40,90,24,hw, NULL, NULL, NULL);
	inputUser = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,40,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Password :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,64,90,24,hw, NULL, NULL, NULL);
	inputPass = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,64,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Login", WS_VISIBLE | WS_CHILD | SS_LEFT,420,90,150,24,hw, (HMENU) loginProses, NULL, NULL);
}

void _register(HWND hw)
{
	cls(hw);
	CreateWindow("static", "ADMINISTRATOR", WS_VISIBLE | WS_CHILD | SS_CENTER,330,10,240,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Username :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,40,90,24,hw, NULL, NULL, NULL);
	inputUser = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,40,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Password :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,64,90,24,hw, NULL, NULL, NULL);
	inputPass = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,64,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Register", WS_VISIBLE | WS_CHILD | SS_LEFT,420,90,150,24,hw, (HMENU) registerProses, NULL, NULL);
}

void _mahasiswaAdd(HWND hw)
{
	cls(hw);
	CreateWindow("static", "MAHASISWA", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "NPM :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
	inputNPM = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
	inputNama = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
	inputProgram = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Add New", WS_VISIBLE | WS_CHILD | SS_LEFT,380,110,270,24,hw, (HMENU) mahasiswaSave, NULL, NULL);
}

void _nilaiAdd(HWND hw)
{
	cls(hw);
	CreateWindow("static", "MAHASISWA", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "NPM :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
	inputNPM = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,200,24,hw, NULL, NULL, NULL);
	CreateWindow("button", "Search", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,580,40,70,24,hw, (HMENU) nSearch, NULL, NULL);
	
	CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
	nNama = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
	nProgram = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Kode Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,110,150,24,hw, NULL, NULL, NULL);
	nilaiKode = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,110,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,134,150,24,hw, NULL, NULL, NULL);
	nilaiMatkul = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,134,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Semester :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,158,150,24,hw, NULL, NULL, NULL);
	nilaiSemester = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,158,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai Tugas :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,182,150,24,hw, NULL, NULL, NULL);
	nilaiTugas = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,182,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai Quiz :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,206,150,24,hw, NULL, NULL, NULL);
	nilaiQuiz = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,206,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai UTS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,230,150,24,hw, NULL, NULL, NULL);
	nilaiUTS = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,230,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai UAS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,254,150,24,hw, NULL, NULL, NULL);
	nilaiUAS = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,254,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Add New", WS_VISIBLE | WS_CHILD | SS_LEFT,380,278,270,24,hw, (HMENU) nilaiSave, NULL, NULL);
}
void _nilaiSave(HWND hw)
{
	cls(hw);
	
	char npm[100], kode[100], mataKuliah[100], semester[100],
		 tugas[256], quiz[256], uts[256], uas[256];
	
	GetWindowText(inputNPM, npm, 100);
	GetWindowText(nilaiKode, kode, 100);
	GetWindowText(nilaiMatkul, mataKuliah, 100);
	GetWindowText(nilaiSemester, semester, 100);
	GetWindowText(nilaiTugas, tugas, 100);
	GetWindowText(nilaiQuiz, quiz, 100);
	GetWindowText(nilaiUTS, uts, 100);
	GetWindowText(nilaiUAS, uas, 100);
	
	for(int no=0; no <= mahasiswaCount; no++)
	{
		if( strcmp(npm, Mahasiswa[no].npm.c_str()) == 0 )
		{
			float akhir; char huruf = 'A';
			akhir = atof(tugas) + atof(quiz) + atof(uts) + atof(uas);
			
			Nilai[nilaiCount].npm = npm;
			Nilai[nilaiCount].kode = kode;
			Nilai[nilaiCount].mataKuliah = mataKuliah;
			Nilai[nilaiCount].semester = semester;
			Nilai[nilaiCount].tugas = atof(tugas);
			Nilai[nilaiCount].quiz = atof(quiz);
			Nilai[nilaiCount].uts = atof(uts);
			Nilai[nilaiCount].uas = atof(uas);
			Nilai[nilaiCount].akhir = akhir;
			Nilai[nilaiCount].huruf = huruf;
			nilaiCount++;
			SendMessage(hw, WM_COMMAND, nilaiData, 0);
		}
	}
}
void _about(HWND hw)
{
	cls(hw);
	CreateWindow("static", "KELOMPOK 2", WS_VISIBLE | WS_CHILD | SS_CENTER,30,10,900,24,hw, NULL, NULL, NULL);
	CreateWindow("static", " Anggota:\n\n Fittra Ferdiansyah \n Angel Nurfadilah \n Febry Manalu \n Aldy", WS_VISIBLE | WS_CHILD | SS_LEFT,30,34,900,320,hw, NULL, NULL, NULL);
}

//MAHASISWA

void _dataMahasiswa(HWND hw, int tinggi)
{
	static HWND _viewMahasiswa;
	cls(hw);	
	CreateWindow("static", "Data Mahasiswa", WS_VISIBLE | WS_CHILD | SS_CENTER,230,tinggi,420,24,hw, NULL, NULL, NULL);
	
	_viewMahasiswa = CreateWindow(WC_LISTVIEW, "Data Mahasiswa", WS_CHILD | WS_VISIBLE | LVS_REPORT,230,tinggi+24,420,400,hw, NULL, NULL, NULL);
	
	_kolomMahasiswa(_viewMahasiswa);
	_barisMahasiswa(_viewMahasiswa);
}

void _kolomMahasiswa(HWND hw)
{
	LVCOLUMN kolom;
	kolom.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	
	kolom.iSubItem = 0;
	kolom.pszText = "No.";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 0, &kolom);
	
	kolom.iSubItem = 1;
	kolom.pszText = "NPM";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 1, &kolom);
	
	kolom.iSubItem = 2;
	kolom.pszText = "Nama Lengkap";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 2, &kolom);
	
	kolom.iSubItem = 3;
	kolom.pszText = "Program Studi";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 3, &kolom);
}
void _barisMahasiswa(HWND hw)
{
	LVITEM baris;
	baris.mask = LVIF_TEXT;
	int urut;

	for(int no=0; no <= mahasiswaCount; no++)
	{
		if(strcmp(Mahasiswa[no].npm.c_str(), "") != 0)
		{
			urut = no +1;
			baris.iItem = static_cast<int>(no);
			baris.iSubItem = 0;
			baris.pszText = const_cast<LPSTR>(to_string(urut).c_str());
			ListView_InsertItem(hw, &baris);
			ListView_SetItemText(hw, no,1, const_cast<LPSTR>(Mahasiswa[no].npm.c_str()));
			ListView_SetItemText(hw, no,2, const_cast<LPSTR>(Mahasiswa[no].nama.c_str()));
			ListView_SetItemText(hw, no,3, const_cast<LPSTR>(Mahasiswa[no].program.c_str()));
		}
	}
}

//NILAI

void _dataNilai(HWND hw)
{
	static HWND _viewNilai;
	cls(hw);	
	CreateWindow("static", "Data Nilai", WS_VISIBLE | WS_CHILD | SS_CENTER,30,10,900,24,hw, NULL, NULL, NULL);
	
	_viewNilai = CreateWindow(WC_LISTVIEW, "Data Nilai", WS_CHILD | WS_VISIBLE | LVS_REPORT,30,34,900,400,hw, NULL, NULL, NULL);
	
	_kolomNilai(_viewNilai);
	_barisNilai(_viewNilai);
}

void _kolomNilai(HWND hw)
{
	LVCOLUMN kolom;
	kolom.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	
	kolom.iSubItem = 0;
	kolom.pszText = "No.";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 0, &kolom);
	
	kolom.iSubItem = 1;
	kolom.pszText = "NPM";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 1, &kolom);
	
	kolom.iSubItem = 2;
	kolom.pszText = "Nama Lengkap";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 2, &kolom);
	
	kolom.iSubItem = 3;
	kolom.pszText = "Program Studi";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 3, &kolom);
	
	kolom.iSubItem = 4;
	kolom.pszText = "Kode";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 4, &kolom);
	
	kolom.iSubItem = 5;
	kolom.pszText = "Mata Kuliah";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 5, &kolom);
	
	kolom.iSubItem = 6;
	kolom.pszText = "Semester";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 6, &kolom);
	
	kolom.iSubItem = 7;
	kolom.pszText = "Tugas";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 7, &kolom);
	
	kolom.iSubItem = 8;
	kolom.pszText = "Quiz";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 8, &kolom);
	
	kolom.iSubItem = 9;
	kolom.pszText = "UTS";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 9, &kolom);
	
	kolom.iSubItem = 10;
	kolom.pszText = "UAS";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 10, &kolom);
	
	kolom.iSubItem = 11;
	kolom.pszText = "Total";
	kolom.cx = 50;
	ListView_InsertColumn(hw, 11, &kolom);
	
	kolom.iSubItem = 12;
	kolom.pszText = "Keterangan";
	kolom.cx = 100;
	ListView_InsertColumn(hw, 12, &kolom);
}
void _barisNilai(HWND hw)
{
	LVITEM baris;
	baris.mask = LVIF_TEXT;
	int urut;

	for(int no=0; no <= nilaiCount; no++)
	{
//		if(strcmp(Nilai[no].npm.c_str(), "") != 0)
//		{
			urut = no+1;
			char tugas[256], quiz[256], uts[256], uas[256], akhir[256];
			
			sprintf(tugas, "%.2f", Nilai[no].tugas);
			sprintf(quiz, "%.2f", Nilai[no].quiz);
			sprintf(uts, "%.2f", Nilai[no].uts);
			sprintf(uas, "%.2f", Nilai[no].uas);
			sprintf(akhir, "%.2f", Nilai[no].akhir);

			baris.iItem = static_cast<int>(no);
			baris.iSubItem = 0;
			baris.pszText = const_cast<LPSTR>(to_string(urut).c_str());
			ListView_InsertItem(hw, &baris);
			ListView_SetItemText(hw, no,1, const_cast<LPSTR>(Nilai[no].npm.c_str()));
			ListView_SetItemText(hw, no,2, const_cast<LPSTR>(Nilai[no].npm.c_str()));
			ListView_SetItemText(hw, no,3, const_cast<LPSTR>(Nilai[no].npm.c_str()));
			ListView_SetItemText(hw, no,4, const_cast<LPSTR>(Nilai[no].kode.c_str()));
			ListView_SetItemText(hw, no,5, const_cast<LPSTR>(Nilai[no].mataKuliah.c_str()));
			ListView_SetItemText(hw, no,6, const_cast<LPSTR>(Nilai[no].semester.c_str()));
			ListView_SetItemText(hw, no,7, const_cast<LPSTR>(tugas));
			ListView_SetItemText(hw, no,8, const_cast<LPSTR>(quiz));
			ListView_SetItemText(hw, no,9, const_cast<LPSTR>(uts));
			ListView_SetItemText(hw, no,10, const_cast<LPSTR>(uas));
			ListView_SetItemText(hw, no,11, const_cast<LPSTR>(akhir));
			ListView_SetItemText(hw, no,12, const_cast<LPSTR>(to_string(Nilai[no].huruf).c_str()));
			cout << Nilai[no].npm << endl;
//		}
	}
}
