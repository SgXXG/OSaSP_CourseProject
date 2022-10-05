#pragma once
#include "Core.h"
#include <windows.h>

namespace CPPSnake {

	class GfxDevice {

		friend class Application;

	private:

		GfxDevice() {}
		~GfxDevice();

		Bool initialize();

	public:

		Void clearColor(UInt32 color);
		Void present();

	private:

		Bool createBackBuffer();

	private:

		HBITMAP _backBuffer{};
		HBITMAP _BackBufferOut{};
		HDC _backBufferDC{};
		HDC _wndClientDC{};

		UInt32* _colorBuffer{};
		UInt32 _bufferWidth{};
		UInt32 _bufferHeight{};

	};

	extern GfxDevice* _gfxDevice;
}
