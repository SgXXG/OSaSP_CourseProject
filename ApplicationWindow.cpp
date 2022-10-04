#include "Pch.h"
#include "ApplicationWindow.h"

namespace CPPSnake {
	ApplicationWindow::~ApplicationWindow() {
		if (_handle) DestroyWindow(_handle);
	}
}