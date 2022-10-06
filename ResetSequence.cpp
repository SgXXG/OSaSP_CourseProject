#include "Pch.h"
#include "ResetSequence.h"
#include "Timer.h"
#include "GfxDevice.h"
#include "ApplicationWindow.h"

namespace CPPSnake {


	Void ResetSequence::start()
	{
		_isPlaying = true;
		_isFadingOut = true;
		_willStartToFadeIn = false;

		_startTime = _timer->getCurrentTime();
	}

	Void ResetSequence::draw()
	{
		UInt32 currentColor{};
		BGRA32 startColor = BGRA32(0, 0, 0, 0);
		BGRA32 endColor = BGRA32(0, 0, 0, 255);

		const Float fadeDuration = 2.0f;
		if (_isFadingOut) {

			Float t = (_timer->getCurrentTime() - _startTime) / fadeDuration;
			if (t >= 1.0f) {

				t = 1.0f;
				_isFadingOut = false;
				_willStartToFadeIn = true;
			}

			currentColor = BGRA32::lerp(startColor, endColor, t);
		}
		else {

			_willStartToFadeIn = false;

			Float t = (_timer->getCurrentTime() - _startTime - fadeDuration) / fadeDuration;
			if (t >= 1.0f) {

				t = 1.0f;
				_isPlaying = false;
			}

			currentColor = BGRA32::lerp(endColor, startColor, t);
		}

		_gfxDevice->drawTransparentQuad({ 0, 0 }, _appWindow->getClientWidth(), 
			_appWindow->getClientHeight(), currentColor);
	}
}