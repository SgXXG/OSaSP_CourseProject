#pragma once
#include "Core.h"
#include "ApplicationWindow.h"
#include "GfxDevice.h"
#include "Grid.h"
#include "Timer.h"
#include "Snake.h"

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
		Void drawScore();

	private:

		GridSettings _gridSettings{};
		SnakeSettings _snakeSettings{};
	};

	extern Application* _app;
}