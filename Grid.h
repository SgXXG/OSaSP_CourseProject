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

		UInt32 getNumCellsX() const { return _numCellsX; }
		UInt32 getNumCellsY() const { return _numCellsY; }
		Coord2I32 getTopLeft() const { return _topLeft; }
		UInt32 getCellSize() const { return _settings.cellSize; }

	private:

		GridSettings _settings{};
		UInt32 _numCellsX{};
		UInt32 _numCellsY{};

		Coord2I32 _topLeft{};

		MallocBuffer<Cell> _cells{};
	};

	extern Grid* _grid;
}