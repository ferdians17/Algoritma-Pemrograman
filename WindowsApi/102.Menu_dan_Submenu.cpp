#include <windows.h>

LRESULT CALLBACK proses(HWND, UINT, WPARAM, LPARAM);
void menunya(HWND);

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
		
		default:
			DefWindowProc(hw, pesan, wp, lp);
			break;
	}
}

void menunya(HWND hw)
{
	HMENU menu = CreateMenu();
	
	HMENU aksi = CreateMenu();
	AppendMenu(aksi, MF_STRING, NULL, "Masuk");
	AppendMenu(aksi, MF_STRING, NULL, "Daftar");
	AppendMenu(aksi, MF_SEPARATOR, NULL, NULL);
	AppendMenu(aksi, MF_STRING, NULL, "Keluar");
	
	HMENU mahasiswa = CreateMenu();
	AppendMenu(mahasiswa, MF_STRING, NULL, "Tambah");
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