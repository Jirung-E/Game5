#pragma once

#include "GameObject2D.h"
#include "BoxCollider2D.h"
#include "Bullet.h"
#include "World.h"


class Player : public GameObject2D {
	BoxCollider2D hitbox;
	Bullet bullet[50];
	char facing;

	World* myWorld;

	void sync();

public:
	Player();
	Player(Position position, Sprite sprite);
	Player(Position position, const std::string& sprite);
	Player(Sprite sprite, Position position);
	Player(const std::string& sprite, Position position);
	Player(Position position);
	Player(Sprite sprite);
	Player(const std::string& sprite);

	bool show_hitbox;

	void enterWorld(World* world);

	void show() const;
	void hide() const;

	bool isCollide() const;

	void moveto(int x, int y);
	void move(char direc);

	void update();
};