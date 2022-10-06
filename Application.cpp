#include "Pch.h"
#include "Application.h"

namespace CPPSnake {

	Application* _app{};
	Application::~Application() {
	
		delete _snake;
		delete _grid;
		delete _gfxDevice;
		delete _appWindow;
		delete _timer;
	}

	Bool Application::initialize()
	{
		srand(timeGetTime());

		_timer = new Timer();
		if (!_timer->initialize()) return false;
		_appWindow = new ApplicationWindow();
		if (!_appWindow -> initialize()) return false;
		_gfxDevice = new GfxDevice();
		if (!_gfxDevice->initialize()) return false;
		_grid = new Grid();
		if (!_grid->initialize(_gridSettings)) return false;
		_snake = new Snake();
		if (!_snake->initialize(_snakeSettings)) return false;

		ShowCursor(FALSE);

		return true;
	}

	Void Application::run()
	{
		MSG msg {};
		while (true)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) break;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else processFrame();
		}
	}

	Void Application::quit()
	{
		PostQuitMessage(0);
	}

	Void Application::processFrame()
	{
		_gfxDevice->clearColor(0x00000000);
		_snake->update();
		_snake->draw();
		_grid->draw();
		_gfxDevice->present();

		if (_snake->bitItsOwnTail()) {

			_snake->initialize(_snakeSettings);
			_grid->initialize(_gridSettings);
		}
	}
}