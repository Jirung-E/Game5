#include "DisplayManager.h"

#include <Windows.h>


bool DisplayManager::gotoxy(int x, int y) {
	if(x < 0 || y < 0) {
		return false;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { SHORT(x), SHORT(y) });

	return true;
}

bool DisplayManager::gotoxy(Position pos) {
	if(pos.x < 0 || pos.y < 0) {
		return false;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { SHORT(pos.x), SHORT(pos.y) });

	return true;
}