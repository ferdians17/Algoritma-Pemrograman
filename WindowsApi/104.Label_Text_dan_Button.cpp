#include <windows.h>

#define aksi_masuk 1
#define aksi_keluar 3

LRESULT CALLBACK proses(HWND, UINT, WPARAM, LPARAM);
void menunya(HWND);

//buat alias untuk label, teks dan tombol
HWND label, teks, tombol;

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
					CreateWindow("static", "Username:", WS_VISIBLE | WS_CHILD | SS_LEFT,110,10,100,24,hw, NULL, NULL, NULL);
					CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | SS_LEFT,210,10,100,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Password:", WS_VISIBLE | WS_CHILD | SS_LEFT,110,35,100,24,hw, NULL, NULL, NULL);
					CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | SS_LEFT,210,35,100,24,hw, NULL, NULL, NULL);
					
					CreateWindow("button", "Masuk", WS_VISIBLE | WS_CHILD | SS_LEFT,210,60,100,24,hw, NULL, NULL, NULL);
					break;
			}
			
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