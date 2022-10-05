#include "Pch.h"
#include "Grid.h"
#include "ApplicationWindow.h"
#include "GfxDevice.h"

namespace CPPSnake {

	Grid* _grid{};

	Bool Grid::initialize(const GridSettings& settings)
	{
		_settings = settings;
		if (_settings.cellSize < 8) _settings.cellSize = 8;
		if (!_settings.maxNumCellsX) _settings.maxNumCellsX = 100;
		if (!_settings.maxNumCellsY) _settings.maxNumCellsY = 100;

		_numCellsX = (_appWindow->getClientWidth() - 1) / _settings.cellSize;
		if (_numCellsX > _settings.maxNumCellsX) _numCellsX = _settings.maxNumCellsX;

		_numCellsY = (_appWindow->getClientHeight() - 1) / _settings.cellSize;
		if (_numCellsY > _settings.maxNumCellsY) _numCellsY = _settings.maxNumCellsY;

		_cells.numItems = getTotalNumCells();
		if (_cells.capacity < _cells.numItems) _cells.grow(_cells.numItems - _cells.capacity);

		for (UInt32 i = 0; i < _cells.numItems; ++i)
			_cells[i].flags = {};

		UInt32 rem = _appWindow->getClientWidth() - _numCellsX * _settings.cellSize;
		_topLeft.x = (UInt32)(rem * 0.5f);
		rem = _appWindow->getClientHeight() - _numCellsY * _settings.cellSize;
		_topLeft.y = (UInt32)(rem * 0.5f);

		return true;
	}

	Void Grid::draw()
	{
		UInt32 bufferWidth = _gfxDevice->getBufferWidth();
		UInt32* colorBuffer = _gfxDevice->getColorBuffer();

		UInt32 numLines = _numCellsX + 1;
		UInt32 lineLength = _numCellsY * _settings.cellSize;
		for (UInt32 lineIndex = 0; lineIndex < numLines; ++lineIndex)
		{
			UInt32 x = (UInt32)_topLeft.x + lineIndex * _settings.cellSize;
			for (UInt32 y = 0; y < lineLength; ++y)
				colorBuffer[(_topLeft.y + y) * bufferWidth + x] = _settings.lineColor;
		}

		numLines = _numCellsY + 1;
		lineLength = _numCellsX * _settings.cellSize; 
		for (UInt32 lineIndex = 0; lineIndex < numLines; ++lineIndex)
			__stosd((PDWORD)&colorBuffer[(_topLeft.y + lineIndex * _settings.cellSize) 
				* bufferWidth + _topLeft.x], _settings.lineColor, lineLength);
	}
}