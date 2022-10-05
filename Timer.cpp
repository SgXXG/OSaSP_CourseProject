#include "Pch.h"
#include "Timer.h"

namespace CPPSnake {

	Timer* _timer{};

	Bool Timer::initialize()
	{
		UInt64 freq{};
		if (!QueryPerformanceFrequency((LARGE_INTEGER*)&freq)) return false;

		_toSeconds = 1.0f / freq;
		
		return true;
	}

	Float Timer::getCurrentTime() const
	{
		UInt64 ticks{};
		QueryPerformanceCounter((LARGE_INTEGER*)&ticks);

		return ticks * _toSeconds;
	}
}