#include "myheader.h"

HINSTANCE hInst;
HWND hWnd;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCommandLine,
	_In_ int nCmdShow) {
	UNREFERENCED_PARAMETER(lpCommandLine);
	UNREFERENCED_PARAMETER(nCmdShow);
	MyRegister(hInstance);
	if (!InitWindow()) {
		return FALSE;
	}
	
	MSG msg = { 0 };
	while (GetMessage(&msg, hWnd, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}

ATOM MyRegister(HINSTANCE hInstance) {
	hInst = hInstance;
	WNDCLASS wc = { 0 };
	wc.lpszClassName = className;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	return RegisterClass(&wc);
}

BOOL InitWindow(){
	hWnd = CreateWindow(className, windowName, WS_OVERLAPPEDWINDOW, 10, 10, 640, 480, NULL, NULL, hInst, NULL);
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			CreateWindow(TEXT("Button"), TEXT(""), WS_VISIBLE | WS_CHILD, 10+10*j, 10+10*i, 10, 10, hWnd, (HMENU)(100+i*9+j), hInst, NULL);
		}
	}
	if (!hWnd) {
		return FALSE;
	}
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch (uMsg) {
	case WM_COMMAND:{
		int id = LOWORD(wParam);
		TCHAR s[20] = { 0 };
		wsprintf(s, TEXT("%d"), id);
		MessageBox(NULL, s, s, MB_OK);
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
