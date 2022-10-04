#include "Pch.h"
#include "ApplicationWindow.h"

namespace CPPSnake {
	ApplicationWindow::~ApplicationWindow() {
		if (_handle) DestroyWindow(_handle);
	}

	Bool ApplicationWindow::initialize()
	{
		WNDCLASS wc{};
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = staticWndProc;
		wc.lpszClassName = TEXT("Snake");

		if (!RegisterClass(&wc)) return false;

		Int32 screenWidth = GetSystemMetrics(SM_CXSCREEN);
		Int32 screenHeight = GetSystemMetrics(SM_CYSCREEN);

		_handle = CreateWindow(wc.lpszClassName, wc.lpszClassName, WS_POPUP,
			0, 0, screenWidth, screenHeight, NULL, NULL, NULL, this);
		if (!_handle) return false;

		ShowWindow(_handle, SW_NORMAL);

		_clientDC = GetDC(_handle);
		if (!_clientDC) return false;

		return true;
	}
	LRESULT ApplicationWindow::staticWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_CREATE) SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT*)lParam)->lpCreateParams);

		ApplicationWindow* appWindow = (ApplicationWindow*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if (appWindow) return appWindow->wndProc (hWnd, msg, wParam, lParam);

		return DefWindowProc (hWnd, msg, wParam, lParam);
	}
	LRESULT ApplicationWindow::wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return LRESULT();
	}
}