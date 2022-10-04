#include "Pch.h"
#include "Application.h"

namespace CPPSnake {

	Application* _app{};
	Application::~Application() {
	
		delete _appWindow;
	}

	Bool Application::initialize()
	{
		_appWindow = new ApplicationWindow();
		if (!_appWindow -> initialize()) return false;

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
		return Void();
	}
}