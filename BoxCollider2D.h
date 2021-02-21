#pragma once

#include "Position.h"


class BoxCollider2D {
	Position position;
	int width;
	int height;
	bool is_enabled;

	int left;
	int right;
	int top;
	int bottom;

	void init();
	bool moveBrush(Position pos) const;

public:
	BoxCollider2D() = default;
	BoxCollider2D(Position position, int width, int height);


	void sleep();
	void awake();
	bool isEnabled() const;

	bool isCollide() const;

	void setPosition(Position position);
	void setWidth(int width);
	void setHeight(int height);

	Position getPosition() const;
	int getWidth() const;
	int getHeight() const;

	int getLeft() const;
	int getRight() const;
	int getTop() const;
	int getBottom() const;

	void show() const;
	void hide() const;
};