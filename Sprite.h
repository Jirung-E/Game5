#pragma once

#include "Position.h"
#include "Pivot.h"

#include <string>


class Sprite {
	char** sprite;

	int width;
	int height;
	Pivot pivot;
	Position position;

	int left;
	int right;
	int top;
	int bottom;

	bool moveBrush(Position pos) const;
	void init();

public:
	Sprite();
	Sprite(Pivot pivot, Position position);
	Sprite(Pivot pivot);
	Sprite(Position position);
	Sprite(const std::string& file, Pivot pivot, Position position);
	Sprite(const std::string& file, Pivot pivot);
	Sprite(const std::string& file, Position position);
	Sprite(const std::string& file);
	~Sprite();


	void show() const;
	void hide() const;

	int getWidth() const;
	int getHeight() const;

	Pivot getPivot() const;
	void setPivot(Pivot pivot);

	Position getPosition() const;
	void setPosition(Position pos);

	int getLeft() const;
	int getRight() const;
	int getTop() const;
	int getBottom() const;
};