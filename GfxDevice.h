#pragma once
#include "Core.h"
#include <windows.h>
#include "ApplicationWindow.h"

namespace CPPSnake {

	class GfxDevice : public IApplicationWindowListener {

		friend class Application;

	private:

		GfxDevice() {}
		~GfxDevice();

		Bool initialize();

	public:

		Void clearColor(UInt32 color);
		Void present();

		Void drawSquare(const Coord2I32& topLeft, UInt32 size, UInt32 color);
		Void drawTransparentQuad(const Coord2I32& topLeft, UInt32 width, UInt32 height, UInt32 color);

		UInt32 getBufferWidth() const { return _bufferWidth; };
		UInt32 getBufferHeight() const { return _bufferHeight; }
		UInt32* getColorBuffer() const { return _colorBuffer; }
		HDC getBackBufferDC() const { return _backBufferDC; }

	private:

		Bool createBackBuffer();
		Void onAppWindowResized(const UInt32& newClientSize, Bool isMinimized);

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
