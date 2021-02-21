#pragma once

#include "BoxCollider2D.h"

#include <string>


class World {
	char** object_shape;
	BoxCollider2D** object_box_collider;
	int width;
	int height;

public:
	World(const std::string& file);
	~World();

	void show() const;

	int getWidth() const;
	int getHeight() const;

	friend class Player;
	friend class Bullet;
};