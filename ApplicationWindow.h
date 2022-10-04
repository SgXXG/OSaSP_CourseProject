#pragma once
#include "Core.h"
#include <windows.h>

namespace CPPSnake {
	class ApplicationWindow {

		friend class Application;

	private:

		ApplicationWindow() {};
		~ApplicationWindow();

	public:

		HWND getHandle() const { return _handle;  }
		HDC hetClientDC() const { return _clientDC; }
		Size2UI32 getClientSize() const { return _clientSize; }
		UInt32 getClientWidth() const { return _clientSize.width; }
		UInt32 getClientHeight() const { return _clientSize.height; }


	private:

		HWND _handle{};
		HDC _clientDC{};
		Size2UI32 _clientSize{};

	};

	extern ApplicationWindow* _appWindow;
}