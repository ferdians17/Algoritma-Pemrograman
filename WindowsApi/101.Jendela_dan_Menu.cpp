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
	
	HWND hw = CreateWindow("permenuan", "Jendela dan Menu", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT, 420, 240, NULL, NULL, NULL, NULL);
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
	AppendMenu(menu, MF_POPUP, NULL, "Aksi");
	AppendMenu(menu, MF_POPUP, NULL, "Data Mahasiswa");
	AppendMenu(menu, MF_POPUP, NULL, "Data Nilai");
	
	SetMenu(hw, menu);
}