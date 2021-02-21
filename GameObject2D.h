#pragma once

#include "Position.h"
#include "Sprite.h"

#include <string>


class GameObject2D {
protected:
	Position position;
	Sprite sprite;

	void sync();

public:
	GameObject2D() = default;
	GameObject2D(Position position, Sprite sprite);
	GameObject2D(Position position, const std::string& sprite);
	GameObject2D(Sprite sprite, Position position);
	GameObject2D(const std::string& sprite, Position position);
	GameObject2D(Position position);
	GameObject2D(Sprite sprite);
	GameObject2D(const std::string& sprite);


	void show() const;
	void hide() const;

	void moveto(int x, int y);

	void move(char direc);


	//virtual void interaction(GameObject2D* go) = 0;

	//virtual void update();
};