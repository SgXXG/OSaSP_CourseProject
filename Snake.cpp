#include "Pch.h"
#include "Snake.h"
#include "Grid.h"
#include"Timer.h"

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

		if (!_body.capacity) _body.grow(20);
		_body[0].x = (Int32)((_grid->getNumCellsX() - 1) * 0.5f);
		_body[0].y = (Int32)((_grid->getNumCellsY() - 1) * 0.5f);

		_timeSinceLastMove = _timer->getCurrentTime();
		_moveTimeStep = _settings.moveTimeStep;

		return true;
	}

	Void Snake::update()
	{
		return Void();
	}

	Void Snake::draw()
	{
		return Void();
	}
}