#pragma once
#include "Core.h"
#include "ApplicationWindow.h"
#include "GfxDevice.h"
#include "Grid.h"
#include "Timer.h"
#include "Snake.h"
#include "ResetSequence.h"

namespace CPPSnake {

	enum class GameState {

		Snaking = 0,
		Reset
	};
	
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
		ResetSequence _resetSequence{};
		GameState _gameState = GameState::Snaking;
	};

	extern Application* _app;
}