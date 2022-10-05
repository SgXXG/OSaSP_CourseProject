#pragma once
#include "Core.h"
#include <windows.h>

namespace CPPSnake {

	class IApplicationWindowListener {

	public:

		virtual Void onAppWindowResized(const Size2UI32& newClientSize, Bool isMinimized) = 0;
	};
	
	class ApplicationWindow : public EventDispatcher<IApplicationWindowListener> {

		friend class Application;

	private:

		ApplicationWindow() {};
		~ApplicationWindow();

		Bool initialize();

	public:

		HWND getHandle() const { return _handle;  }
		HDC hetClientDC() const { return _clientDC; }
		Size2UI32 getClientSize() const { return _clientSize; }
		UInt32 getClientWidth() const { return _clientSize.width; }
		UInt32 getClientHeight() const { return _clientSize.height; }
		BOOL isMinimized() const { return _isMinimized; }

	private:

		static LRESULT CALLBACK staticWndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		LRESULT CALLBACK wndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:

		HWND _handle{};
		HDC _clientDC{};
		BOOL _isMinimized{};
		Size2UI32 _clientSize{};

	};

	extern ApplicationWindow* _appWindow;
}