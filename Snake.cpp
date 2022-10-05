#include "Pch.h"
#include "Snake.h"

namespace CPPSnake {
	Bool Snake::initialize(const SnakeSettings& settings)
	{
		_settings = settings;
		if (_settings.moveTimeStep < 0.0f) _settings.minMoveTimeStep = 0.12f;
		if (_settings.minMoveTimeStep < 0.0f || 
			_settings.minMoveTimeStep > _settings.moveTimeStep)	_settings.minMoveTimeStep = _settings.moveTimeStep;
	
		_length = 1;
		_numFoodEaten = 0;

		_moveDirection = (Direction2D)(rand() % 4);
		_body.numItems = 1;
	}
}