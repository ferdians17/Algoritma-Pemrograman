#include "Header.cpp"

INT WINAPI WinMain(HINSTANCE hi, HINSTANCE hs, LPSTR pr, int cmd)
{	
	WNDCLASS wc = {};
	
	wc.hInstance = hi;
	wc.lpfnWndProc = proses;
	wc.lpszClassName = "KELOMPOK_2";
	wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	
	if( !RegisterClass(&wc)) return 0;
	
	HWND hw = CreateWindow(
		"KELOMPOK_2",
		"APLIKASI PENILAIAN - STMIK PENUSA",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		10,
		10,
		960,
		600,
		NULL, NULL, NULL, NULL
	);
	
	ShowWindow(hw, cmd);
	UpdateWindow(hw);
	MSG pesan = {};
	
	while( GetMessage(&pesan, NULL, NULL, NULL))
	{
		TranslateMessage(&pesan);
		DispatchMessage(&pesan);
	}
	
//	return 0;
}
