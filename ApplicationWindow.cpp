#include "Pch.h"
#include "ApplicationWindow.h"
#include <minwindef.h>

namespace CPPSnake {

	ApplicationWindow* _appWindow{};

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
		switch (msg) {
		case WM_SIZE:

			if (wParam != SIZE_MINIMIZED) {
				_clientSize.width = (UInt32)(LOWORD(lParam));
				_clientSize.height = (UInt32)(HIWORD(lParam));
				_isMinimized = false;
			}
			else {
				_clientSize.width = 0;
				_clientSize.height = 0;
				_isMinimized = true;
			}

			return 0;

		case WM_CLOSE:

			DestroyWindow(_handle);
			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			return 0;

		default:

			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}
}