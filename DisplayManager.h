#pragma once

#include "Position.h"

#include <iostream>


namespace DisplayManager {
	bool gotoxy(int x, int y);
	bool gotoxy(Position pos);
}