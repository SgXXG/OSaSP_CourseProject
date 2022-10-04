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
}