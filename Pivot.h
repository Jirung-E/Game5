#pragma once

#include "Position.h"

#include <string>


class Pivot : public Position {
public:
	Pivot() = default;
	Pivot(int x, int y);
	Pivot(Position pos);
};