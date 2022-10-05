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
		Float currentTime = _timer->getCurrentTime();
		if ((currentTime - _timeSinceLastMove) >= _moveTimeStep) {

			_timeSinceLastMove = currentTime;

			_grid->setHasSnake(_body[_length - 1].x, _body[_length - 1].y, false);
			for (UInt32 i = 0; i < _length - 1; i++)
				_body[i] = _body[i - 1];
			
			switch (_moveDirection)
			{
			case Direction2D::Left:

				_body[0].x -= 1;
				if (_body[0].x < 0) _body[0].x = _grid->getNumCellsX() - 1;
				break;

			case Direction2D::Right:

				_body[0].x += 1;
				if (_body[0].x == _grid->getNumCellsX()) _body[0].x = 0;
				break;
			case Direction2D::Up:

				_body[0].y -= 1;
				if (_body[0].y < 0) _body[0].y = _grid->getNumCellsY() - 1;
				break;

			case Direction2D::Down:

				_body[0].y += 1;
				if (_body[0].y == _grid->getNumCellsY()) _body[0].Y = 0;
				break;
			}

			if (_grid->hasSnake(_body[0].x, _body[0].y)) {

				_bitItsOwnTail = true;
				return;
			}

			_grid->setHasSnake(_body[0].x, _body[0].y, true);

			if (_grid->hasFood(_body[0].x, _body[0].y))
			{
				++_length;
				++_numFoodEaten;

				if (_body.capacity < _length)
					_body.grow(_length - _body.capacity);

				_body.add({ _body[_length - 2].x, _body[_length - 2].y });

				if (_length != _grid->getTotalNumCells())
					_grid->generateFood();
			}
		}
	}

	Void Snake::draw()
	{
		return Void();
	}
}