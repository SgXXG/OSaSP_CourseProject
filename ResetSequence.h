#pragma once
#include "Core.h"

namespace CPPSnake {

	class ResetSequence {

	public:

		ResetSequence() {}
		~ResetSequence() {}

		Void start();
		Void draw();

		Bool willStartToFadeIn() const { return _willStartToFadeIn; }
		Bool isPlaying() const { return _isPlaying; }

	private:

		Float _startTime{};
		Bool _isPlaying{};
		Bool _isFadingOut{};
		Bool _willStartToFadeIn{};
	};
}