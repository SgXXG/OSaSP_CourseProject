#include "Pch.h"
#include "GfxDevice.h"
#include "Application.h"
#include "ApplicationWindow.h"

namespace CPPSnake {

	GfxDevice::~GfxDevice() {

		if (_backBuffer) {

			SelectObject(_backBufferDC, _BackBufferOut);
			DeleteObject(_backBuffer);
		}

		if (_backBufferDC) DeleteDC(_backBufferDC);
	}

	Bool GfxDevice::initialize()
	{
		_bufferWidth = _appWindow->getClientWidth();
		_bufferHeight = _appWindow->getClientHeight();

		if (!createBackBuffer()) return false;

		return true;
	}

	Void GfxDevice::clearColor(UInt32 color)
	{
		return Void();
	}

	Void GfxDevice::present()
	{
		return Void();
	}

	Bool GfxDevice::createBackBuffer()
	{
		return Bool();
	}
}