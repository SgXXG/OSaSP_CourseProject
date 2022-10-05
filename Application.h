#pragma once
#include "Core.h"
#include "ApplicationWindow.h"
#include "GfxDevice.h"

namespace CPPSnake {
	
	class Application {

	public:

		Application() {}
		~Application();

		Bool initialize();
		Void run();
		Void quit();

	private:

		Void processFrame();
	};

	extern Application* _app;
}