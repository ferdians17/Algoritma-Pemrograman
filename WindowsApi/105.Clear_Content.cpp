#include <windows.h>

#define aksi_masuk 1
#define aksi_keluar 3
#define mahasiswa_tambah 5

LRESULT CALLBACK proses(HWND, UINT, WPARAM, LPARAM);
void menunya(HWND);

//buat alias untuk label, teks dan tombol
HWND label, teks, tombol;
void ClearScreen(HWND hwnd) {
	// Menghapus semua kontrol dalam jendela kecuali menu
	HWND hwndChild = GetWindow(hwnd, GW_CHILD);
	while (hwndChild) {
		HWND hwndNext = GetWindow(hwndChild, GW_HWNDNEXT);
		DestroyWindow(hwndChild);
		hwndChild = hwndNext;
	}
}

int WINAPI WinMain(HINSTANCE hs, HINSTANCE hi, LPSTR pr, int cmd)
{	
	WNDCLASS wc = {};
	
	wc.hInstance = hs;
	wc.lpfnWndProc = proses;
	wc.lpszClassName = "permenuan";
	wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	
	if(!RegisterClass(&wc)) return 0;
	
	HWND hw = CreateWindow("permenuan", "Menu dan Submenu", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT, 420, 240, NULL, NULL, NULL, NULL);
	ShowWindow(hw, cmd);
	MSG pesan = {};
	
	while( GetMessage(&pesan, NULL, NULL, NULL) )
	{
		TranslateMessage(&pesan);
		DispatchMessage(&pesan);
	}
	return 0;
}

LRESULT CALLBACK proses(HWND hw, UINT pesan, WPARAM wp, LPARAM lp)
{
	switch( pesan )
	{
		case WM_CREATE:
			menunya(hw);
			break;
			
		case WM_COMMAND:
			switch(wp)
			{
				case aksi_keluar:
					DestroyWindow(hw);
					break;
				
				case aksi_masuk:
					ClearScreen(hw);
					CreateWindow("static", "Username:", WS_VISIBLE | WS_CHILD | SS_LEFT,110,10,100,24,hw, NULL, NULL, NULL);
					CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | SS_LEFT,210,10,100,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Password:", WS_VISIBLE | WS_CHILD | SS_LEFT,110,35,100,24,hw, NULL, NULL, NULL);
					CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | SS_LEFT,210,35,100,24,hw, NULL, NULL, NULL);
					
					CreateWindow("button", "Masuk", WS_VISIBLE | WS_CHILD | SS_CENTER,210,60,100,24,hw, NULL, NULL, NULL);
					break;
				
				case mahasiswa_tambah:
					ClearScreen(hw);
					CreateWindow("static", "Hai", WS_VISIBLE | WS_CHILD | SS_LEFT,110,10,50,24,hw, NULL, NULL, NULL);
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

void menunya(HWND hw)
{
	HMENU menu = CreateMenu();
	
	HMENU aksi = CreateMenu();
	AppendMenu(aksi, MF_STRING, aksi_masuk, "Masuk");
	AppendMenu(aksi, MF_STRING, NULL, "Daftar");
	AppendMenu(aksi, MF_SEPARATOR, NULL, NULL);
	AppendMenu(aksi, MF_STRING, aksi_keluar, "Keluar");
	
	HMENU mahasiswa = CreateMenu();
	AppendMenu(mahasiswa, MF_STRING, mahasiswa_tambah, "Tambah");
	AppendMenu(mahasiswa, MF_STRING, NULL, "Print");
	AppendMenu(mahasiswa, MF_STRING, NULL, "Data Mahasiswa");
	
	HMENU nilai = CreateMenu();
	AppendMenu(nilai, MF_STRING, NULL, "Tambah");
	AppendMenu(nilai, MF_STRING, NULL, "Print");
	AppendMenu(nilai, MF_STRING, NULL, "Data Nilai");
	
	AppendMenu(menu, MF_POPUP, (UINT_PTR)aksi, "Aksi");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)mahasiswa, "Data Mahasiswa");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)nilai, "Data Nilai");
	
	SetMenu(hw, menu);
}