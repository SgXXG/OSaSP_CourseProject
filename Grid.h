#pragma once
#include "Core.h"

namespace CPPSnake {

	enum class CellFlags : UInt32 {

		None = 0,
		HasSnake,
		HasFood
	};

	struct Cell {

		UInt32 flags{};
	};

	struct GridSettings {

		UInt32 cellSize = 30;
		UInt32 lineColor = 0x00808080;
		UInt32 foodColor = 0x00000088;
		UInt32 maxNumCellsX = 100;
		UInt32 maxNumCellsY = 100;
	};

	class Grid {

		friend class Application;

	private:

		Grid() {}
		~Grid() {}

		Bool initialize(const GridSettings& settings);
		Void draw();

	public:

		Void generateFood();

		Void setHasSnake(UInt32 x, UInt32 y, Bool hasSnake) {

			if (hasSnake)_cells[x + y * _numCellsX].flags |= (UInt32)CellFlags::HasSnake;
			else _cells[x + y * _numCellsX].flags &= (UInt32)CellFlags::HasSnake;
		}

		Coord2I32 calcCellTopLeft(UInt32 x, UInt32 y) {

			return Coord2I32((UInt32)_topLeft.x + x + _settings.cellSize,
							 (UInt32)_topLeft.y + y + _settings.cellSize);
		}

		Bool hasFood(UInt32 x, UInt32 y) { return _cells[x + y * _numCellsX].flags & 
												  (UInt32)CellFlags::HasFood; }
		Bool hasSnake(UInt32 x, UInt32 y) { return _cells[x + y * _numCellsX].flags &
												  (UInt32)CellFlags::HasSnake;
		}

		UInt32 getNumCellsX() const { return _numCellsX; }
		UInt32 getNumCellsY() const { return _numCellsY; }
		UInt32 getTotalNumCells() const { return _numCellsX * _numCellsY; }

		Coord2I32 getTopLeft() const { return _topLeft; }
		UInt32 getCellSize() const { return _settings.cellSize; }

	private:

		GridSettings _settings{};
		UInt32 _numCellsX{};
		UInt32 _numCellsY{};

		Coord2I32 _topLeft{};
		Coord2I32 _foodCoords{};

		MallocBuffer<Cell> _cells{};
	};

	extern Grid* _grid;
}