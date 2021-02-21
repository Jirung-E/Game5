#pragma once

#include "GameObject2D.h"
#include "BoxCollider2D.h"
#include "World.h"

#include <string>


class Bullet : public GameObject2D {
	BoxCollider2D hitbox;
	bool is_fired;
	char facing;

	World* myWorld;

	void sync();

public:
	Bullet();
	Bullet(Position position, Sprite sprite);
	Bullet(Position position, const std::string& sprite);
	Bullet(Sprite sprite, Position position);
	Bullet(const std::string& sprite, Position position);
	Bullet(Position position);
	Bullet(Sprite sprite);
	Bullet(const std::string& file);

	void enterWorld(World* world);

	void show() const;
	void hide() const;

	void fire(char facing);
	void destroy();

	bool isFired() const;
	bool isCollide() const;

	void moveto(int x, int y);
	void move(char direc);
};