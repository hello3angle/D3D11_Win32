// D3D11_Win32.cpp : Defines the entry point for the application.
//

#include <Windows.h>

HWND ghMainWnd = 0;

bool InitWindowsApp(HINSTANCE instanceHandle, int show);
int Run();
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd)
{
	if (!InitWindowsApp(hInstance, nShowCmd))
		return false;


	return Run();
}

bool InitWindowsApp(HINSTANCE instanceHandle, int show)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = instanceHandle;
	wc.hIcon = LoadIconW(0, IDI_ASTERISK);//IDI_APPLICATION);
	wc.hCursor = LoadCursorW(0, IDC_IBEAM);//IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"D3D11Win32";

	if (!RegisterClassW(&wc))
	{
		MessageBoxW(0, L"RegisterClass FAILED", 0, 0);
		return false;
	}

	ghMainWnd = CreateWindowW(
		L"D3D11Win32",
		L"D3D11 Win32",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, instanceHandle, 0);

	if (ghMainWnd == 0)
	{
		MessageBoxW(0, L"CreateWindow FAILED", 0, 0);
		return false;
	}

	ShowWindow(ghMainWnd, show);
	UpdateWindow(ghMainWnd);

	return true;
}

int Run()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		// Dispatch Message
		if (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// Run Game Loop
		else
		{
			
		}
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int ans = 0;
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		MessageBoxW(0, L"LMB Clicked", L"Mouse Event", MB_OK);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hWnd);
		break;
	case WM_CREATE:
		MessageBoxW(0, L"Being Created", L"Create Event", MB_OK);
		break;
	case WM_CLOSE:
		if(MessageBoxW(0, L"Being Closed", L"Close Event", MB_YESNO) == IDYES)//MB_OK);
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	}

	return 0;
}



