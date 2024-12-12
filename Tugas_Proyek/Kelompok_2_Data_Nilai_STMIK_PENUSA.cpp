#include <windows.h>
#include <stdlib.h>
#include <iostream>

//using namespace std;

//MENU AKSI
#define aksi_masuk 1
#define aksi_daftar 2
#define aksi_keluar 3
#define masuk_tombol 12
//MENU MAHASISWA
#define mahasiswa_tambah 4
#define mahasiswa_ubah 5
#define mahasiswa_hapus 6
#define mahasiswa_data 7
#define mahasiswa_simpan 13
//MENU NILAI
#define nilai_tambah 8
#define nilai_ubah 9
#define nilai_hapus 10
#define nilai_data 11
//MENU BANTUAN

LRESULT CALLBACK prosedur(HWND, UINT, WPARAM, LPARAM);
void menunya(HWND);
void masuk(HWND);
void mhsBaru(HWND);

HWND masukUser, masukPass, masukHasil;

int WINAPI WinMain(HINSTANCE hins, HINSTANCE hprev, LPSTR arg, int cmd)
{
	WNDCLASSW wc = {};
	
	wc.hInstance = hins;
	wc.lpszClassName = L"kelasku";
	wc.lpfnWndProc = prosedur;
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	
	if(!RegisterClassW(&wc)) return 0;
	
	CreateWindowW(L"kelasku", L"KELOMPOK 2 - DATA NILAI STMIK PELITA NUSANTARA", WS_OVERLAPPEDWINDOW | WS_VISIBLE , 100,100,960,600,NULL, NULL, NULL, NULL);
	
	MSG pesan = {};
	
	while( GetMessage(&pesan, NULL, NULL, NULL))
	{
		TranslateMessage(&pesan);
		DispatchMessage(&pesan);
	}
	return 0;
}

LRESULT CALLBACK prosedur(HWND hw, UINT pesan, WPARAM wp, LPARAM lp)
{
	 switch(pesan)
	 {
	 	case WM_COMMAND:
	 		switch(wp)
	 		{
	 			case aksi_masuk:
	 				MessageBeep(MB_OK);
	 				masuk(hw);
	 				break;
	 			
	 			case masuk_tombol:
	 				char username[50], password[50], hasil[100];
	 				GetWindowText(masukUser, username, 10);
	 				GetWindowText(masukPass, password, 10);
	 				
	 				strcpy(hasil, username);
	 				strcat(hasil, ",");
	 				strcat(hasil, password);
	 				
	 				SetWindowText(masukHasil,hasil);
	 				
	 				if(strcmp(username,"admin") == 0 && strcmp(password,"admin") == 0 )
	 				{
	 					MessageBox(hw,"Selamat, Proses Masuk Berhasil!", "Selamat", MB_OK);
	 				}
	 				break;
	 				
	 			case aksi_keluar:
	 				DestroyWindow(hw);
	 				break;
	 				
	 			case mahasiswa_tambah:
	 				MessageBeep(MB_OK);
	 				mhsBaru(hw);
	 				break;
			}
			break;
	 	
	 	case WM_CREATE:
	 		menunya(hw);
	 		masuk(hw);
	 		break;
	 		
	 	case WM_SIZE:
	 		break;
	 	
	 	case WM_DESTROY:
	 		PostQuitMessage(0);
	 		break;
	 		
	 	default:
	 		return DefWindowProcW(hw, pesan, wp, lp);
	 }
}

void menunya(HWND hw)
{
	HMENU menu = CreateMenu();
	
	HMENU menuAksi = CreateMenu();
	AppendMenu(menuAksi, MF_STRING, aksi_masuk, "Masuk");
	AppendMenu(menuAksi, MF_STRING, aksi_daftar, "Daftar");
	AppendMenu(menuAksi, MF_SEPARATOR, NULL, NULL);
	AppendMenu(menuAksi, MF_STRING, aksi_keluar, "Keluar");
	
	HMENU menuMahasiswa = CreateMenu();
	AppendMenu(menuMahasiswa, MF_STRING, mahasiswa_tambah, "Mahasiswa Baru");
	AppendMenu(menuMahasiswa, MF_STRING, mahasiswa_ubah, "Ubah Mahasiswa");
	AppendMenu(menuMahasiswa, MF_STRING, mahasiswa_hapus, "Hapus Mahasiswa");
	AppendMenu(menuMahasiswa, MF_SEPARATOR, NULL, NULL);
	AppendMenu(menuMahasiswa, MF_STRING, mahasiswa_data, "Data Mahasiswa");
	
	HMENU menuNilai = CreateMenu();
	AppendMenu(menuNilai, MF_STRING, nilai_tambah, "Nilai Baru");
	AppendMenu(menuNilai, MF_STRING, nilai_ubah, "Ubah Nilai");
	AppendMenu(menuNilai, MF_STRING, nilai_hapus, "Hapus Nilai");
	AppendMenu(menuNilai, MF_SEPARATOR, NULL, NULL);
	AppendMenu(menuNilai, MF_STRING, nilai_data, "Data Nilai");
	
	AppendMenu(menu, MF_POPUP, (UINT_PTR) menuAksi, "Aksi");
	AppendMenu(menu, MF_POPUP, (UINT_PTR) menuMahasiswa, "Data Mahasiswa");
	AppendMenu(menu, MF_POPUP, (UINT_PTR) menuNilai, "Data Nilai");
	AppendMenu(menu, MF_STRING, NULL, "Bantuan"); 
	
	SetMenu(hw, menu);
}

void masuk(HWND hw)
{
	CreateWindowW(L"static", L"USERNAME:", WS_VISIBLE | WS_CHILD | SS_LEFT, 100,100,100,20,hw, NULL, NULL, NULL);
	masukUser = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 200,100,100,20,hw, NULL, NULL, NULL);
	
	CreateWindowW(L"static", L"PASSWORD:", WS_VISIBLE | WS_CHILD | SS_LEFT, 100,122,100,20,hw, NULL, NULL, NULL);
	masukPass = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 200,122,100,20,hw, NULL, NULL, NULL);
	
	CreateWindowW(L"button", L"MASUK", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 200,144,100,20,hw, (HMENU)masuk_tombol, NULL, NULL);
	
	masukHasil = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 50,170,500,300,hw, NULL, NULL, NULL);
}


void mhsBaru(HWND hw)
{
	CreateWindowW(L"static", L"MAHASISWA BARU", WS_VISIBLE | WS_CHILD | SS_CENTER, 200,60,200,20,hw, NULL, NULL, NULL);
	CreateWindowW(L"static", L"--------------", WS_VISIBLE | WS_CHILD | SS_CENTER, 200,80,200,20,hw, NULL, NULL, NULL);
	
	CreateWindowW(L"static", L"NPM:", WS_VISIBLE | WS_CHILD | SS_LEFT, 200,100,200,20,hw, NULL, NULL, NULL);
	CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 200,122,200,20,hw, NULL, NULL, NULL);
	
	CreateWindowW(L"static", L"Nama Lengkap:", WS_VISIBLE | WS_CHILD | SS_LEFT, 200,144,200,20,hw, NULL, NULL, NULL);
	CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 200,166,200,20,hw, NULL, NULL, NULL);
	
	CreateWindowW(L"button", L"Simpan", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER, 300,188,100,20,hw, (HMENU)mahasiswa_simpan, NULL, NULL);
}
