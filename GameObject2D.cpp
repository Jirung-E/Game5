#include "GameObject2D.h"

#include "DisplayManager.h"

#include <iostream>


// ----------------------------------------------------------------------------- //
GameObject2D::GameObject2D(Position position, Sprite sprite) : 
	position { position }, sprite { sprite } {
	sync();
	//show();
}

GameObject2D::GameObject2D(Position position, const std::string& sprite) : 
	position { position }, sprite { Sprite { sprite } } {
	sync();
	//show();
}

GameObject2D::GameObject2D(Sprite sprite, Position position) : 
	GameObject2D { position, sprite } {

}

GameObject2D::GameObject2D(const std::string& sprite, Position position) : 
	GameObject2D { position, sprite } {

}

GameObject2D::GameObject2D(Position position) : 
	GameObject2D { position, Sprite { } } {

}

GameObject2D::GameObject2D(Sprite sprite) : 
	GameObject2D { { 0, 0 }, sprite } {

}

GameObject2D::GameObject2D(const std::string& sprite) : 
	GameObject2D { { 0, 0 }, sprite } {

}
// ----------------------------------------------------------------------------- //


void GameObject2D::sync() {
	sprite.setPosition(position);
}

//void GameObject::interaction(GameObject* go) {
//	
//}



//void GameObject2D::update() {
//	
//}


void GameObject2D::show() const {
	sprite.show();
}

void GameObject2D::hide() const {
	sprite.hide();
}


void GameObject2D::moveto(int x, int y) {
	hide();

	position.x = x;
	position.y = y;

	sync();

	show();
}


void GameObject2D::move(char direc) {
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

	show();
}