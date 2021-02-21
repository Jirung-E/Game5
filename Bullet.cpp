#include "Bullet.h"


Bullet::Bullet() :
	GameObject2D { }, is_fired { false },
	hitbox { { sprite.getLeft(), sprite.getBottom() }, sprite.getWidth(), sprite.getHeight() } {
	sync();
}

Bullet::Bullet(Position position, Sprite sprite) :
	GameObject2D { position, sprite }, is_fired { false },
	hitbox { position, GameObject2D::sprite.getWidth(), GameObject2D::sprite.getHeight() } {
	sync();
}

Bullet::Bullet(Position position, const std::string& sprite) :
	GameObject2D { position, sprite }, is_fired { false },
	hitbox { position, GameObject2D::sprite.getWidth(), GameObject2D::sprite.getHeight() } {
	sync();
}

Bullet::Bullet(Sprite sprite, Position position) : Bullet { position, sprite } {
	
}

Bullet::Bullet(const std::string& sprite, Position position) : Bullet { position, sprite } {
	
}

Bullet::Bullet(Position position) : Bullet { position, Sprite { } } {
	
}

Bullet::Bullet(Sprite sprite) : Bullet { Position { }, sprite } {
	
}

Bullet::Bullet(const std::string& sprite) : Bullet { Position { }, sprite } {
	
}


void Bullet::sync() {
	GameObject2D::sync();
	hitbox.setPosition(position);
}


void Bullet::enterWorld(World* world) {
	myWorld = world;
}


void Bullet::show() const {
	if(isFired() == false) {
		return;
	}

	GameObject2D::show();
}

void Bullet::hide() const {
	if(isFired() == false) {
		return;
	}

	GameObject2D::hide();
}


void Bullet::fire(char facing) {
	this->facing = facing;
	is_fired = true;
	hitbox.awake();
}

void Bullet::destroy() {
	hitbox.sleep();
	is_fired = false;
}


bool Bullet::isFired() const {
	return is_fired;
}

bool Bullet::isCollide() const {
	int left = hitbox.getPosition().x + hitbox.getLeft();
	int right = hitbox.getPosition().x + hitbox.getRight();
	int top = hitbox.getPosition().y + hitbox.getTop();
	int bottom = hitbox.getPosition().y + hitbox.getBottom();

	if(left < 0 || top < 0) {
		return true;
	}

	for(int i=0; i<myWorld->getHeight(); ++i) {
		for(int k=0; k<myWorld->getWidth(); ++k) {
			if(myWorld->object_box_collider[i][k].isEnabled()) {
				int target_x = myWorld->object_box_collider[i][k].getPosition().x;
				int target_y = myWorld->object_box_collider[i][k].getPosition().y;

				if(left <= target_x && target_x <= right &&
				   top <= target_y && target_y <= bottom) {
					return true;
				}
			}
		}
	}

	return false;
}


void Bullet::moveto(int x, int y) {
	hide();

	position.x = x;
	position.y = y;

	sync();

	show();
}

void Bullet::move(char direc) {
	if(isFired() == false) {
		return;
	}

	switch(direc) {
		case 'w':
			hide();
			position.y--;
			break;
		case 'a':
			hide();
			position.x--;
			break;
		case 's':
			hide();
			position.y++;
			break;
		case 'd':
			hide();
			position.x++;
			break;
		default:
			return;
	}
	sync();

	if(isCollide()) {
		destroy();
	}
	else {
		show();
	}
}