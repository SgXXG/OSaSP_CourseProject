#pragma once
#include "Core.h"
#include "ApplicationWindow.h"
#include "GfxDevice.h"
#include "Grid.h"

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

	private:

		GridSettings _gridSettings{};
	};

	extern Application* _app;
}