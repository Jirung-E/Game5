#include "Player.h"


Player::Player() : 
	GameObject2D { }, show_hitbox { false }, facing { 'd' },
	bullet { Bullet { "Bullet.txt", position } },
	hitbox { { sprite.getLeft(), sprite.getBottom() }, sprite.getWidth(), sprite.getHeight() } {
	sync();
	show();
}

Player::Player(Position position, Sprite sprite) :
	GameObject2D { position, sprite }, show_hitbox { false }, facing { 'd' },
	bullet { Bullet { "Bullet.txt", position } },
	hitbox { position, GameObject2D::sprite.getWidth(), GameObject2D::sprite.getHeight() } {
	sync();
	show();
}

Player::Player(Position position, const std::string& sprite) : 
	GameObject2D { position, sprite }, show_hitbox { false }, facing { 'd' },
	bullet { Bullet { "Bullet.txt", position } },
	hitbox { position, GameObject2D::sprite.getWidth(), GameObject2D::sprite.getHeight() } {
	sync();
	show();
}

Player::Player(Sprite sprite, Position position) : Player { position, sprite } {
	
}

Player::Player(const std::string& sprite, Position position) : Player { position, sprite } {
	
}

Player::Player(Position position) : Player { position, Sprite { } } {
	
}

Player::Player(Sprite sprite) : Player { Position { }, sprite } {
	
}

Player::Player(const std::string& sprite) : Player { Position { }, sprite } {
	
}


void Player::enterWorld(World* world) {
	myWorld = world;
	for(Bullet& e : bullet) {
		e.enterWorld(world);
	}
}


void Player::sync() {
	GameObject2D::sync();
	hitbox.setPosition(position);

	for(Bullet& e : bullet) {
		if(e.isFired() == false) {
			e.moveto(position.x, position.y);
		}
	}
}


void Player::show() const {
	GameObject2D::show();
	if(show_hitbox == true) {
		hitbox.show();
	}
}

void Player::hide() const {
	if(show_hitbox == true) {
		hitbox.hide();
	}
	GameObject2D::hide();
}


bool Player::isCollide() const {
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


void Player::moveto(int x, int y) {
	hide();

	GameObject2D::moveto(x, y);
	sync();

	show();
}

void Player::move(char direc) {
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
		case ' ':
			switch(facing) {
				case 'w':
					bullet[0].moveto(position.x, position.y + sprite.getTop() - 1);
					break;
				case 'a':
					bullet[0].moveto(position.x + sprite.getLeft() - 1, position.y);
					break;
				case 's':
					bullet[0].moveto(position.x, position.y + sprite.getBottom() + 1);
					break;
				case 'd':
					bullet[0].moveto(position.x + sprite.getRight() + 1, position.y);
					break;
			}
			bullet[0].fire(facing);
			
		default:
			return;
	}
	sync();
	facing = direc;

	if(isCollide()) {
		switch(direc) {
			case 'w':
				position.y++;
				break;
			case 'a':
				position.x++;
				break;
			case 's':
				position.y--;
				break;
			case 'd':
				position.x--;
				break;
		}
	}

	sync();

	show();
}


void Player::update() {
	for(Bullet& e : bullet) {
		if(e.isFired()) {
			e.move(facing);
			//show();
		}
	}
}