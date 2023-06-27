#include <Windows.h>

const LPCWSTR className = TEXT("HelloWorld");
const LPCWSTR windowName = TEXT("HelloWorld");

ATOM MyRegister(HINSTANCE);
BOOL InitWindow();
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);