#include <windows.h>

LRESULT CALLBACK proses(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hs, HINSTANCE hi, LPSTR pr, int cmd)
{
	WNDCLASS wc = {};
	
	wc.hInstance = hs;
	wc.lpfnWndProc = proses;
	wc.lpszClassName = "kosong";
	
	if(!RegisterClass(&wc)) return 0;
	
	HWND hw = CreateWindow("kosong", "Aplikasi Pertama", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 420, 240, NULL, NULL, NULL, NULL);
	
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
	switch(pesan)
	{
		case WM_CREATE:
			break;
			
		default:
			DefWindowProc(hw, pesan, wp, lp);
			break;
			
	}
}
