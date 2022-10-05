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
}