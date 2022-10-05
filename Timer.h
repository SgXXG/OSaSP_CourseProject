#pragma once
#include "Core.h"
#include <windows.h>

namespace CPPSnake {

	class Timer {

		friend class Application;

	private:

		Timer() {}
		~Timer() {}

		Bool initialize();

	public:

		Float getCurrentTime() const;

	private:

		Float _toSeconds{};
	};

	extern Timer* _timer;
}