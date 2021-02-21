#include "BoxCollider2D.h"

#include "DisplayManager.h"

#include <iostream>
#include <Windows.h>


BoxCollider2D::BoxCollider2D(Position position, int width, int height) :
	position { position }, width { width }, height { height }, is_enabled { true } {
	init();
}


void BoxCollider2D::sleep() {
	is_enabled = false;
}

void BoxCollider2D::awake() {
	is_enabled = true;
}

bool BoxCollider2D::isEnabled() const {
	return is_enabled;
}

bool BoxCollider2D::isCollide() const {
	if(!isEnabled()) {
		return false;
	}

	if(position.x + left < 0 || position.y + top < 0) {
		return true;
	}

	return false;
}


void BoxCollider2D::init() {
	left = -static_cast<int>((width-1)/2);
	right = static_cast<int>(width/2);
	top = -static_cast<int>((height-1)/2);
	bottom = static_cast<int>(height/2);
}

bool BoxCollider2D::moveBrush(Position pos) const {
	if(pos.x < 0 || pos.y < 0) {
		return false;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { SHORT(pos.x), SHORT(pos.y) });

	return true;
}


void BoxCollider2D::setPosition(Position position) {
	this->position = position;
}

void BoxCollider2D::setWidth(int width) {
	this->width = width;
	init();
}

void BoxCollider2D::setHeight(int height) {
	this->height = height;
	init();
}


Position BoxCollider2D::getPosition() const {
	return position;
}

int BoxCollider2D::getWidth() const {
	return width;
}
int BoxCollider2D::getHeight() const {
	return height;
}

int BoxCollider2D::getLeft() const {
	return left;
}

int BoxCollider2D::getRight() const {
	return right;
}

int BoxCollider2D::getTop() const {
	return top;
}

int BoxCollider2D::getBottom() const {
	return bottom;
}


void BoxCollider2D::show() const {
	using namespace std;

	for(int i=0; i<width; i++) {
		if(moveBrush({ position.x + left + i, position.y + bottom })) {
			cout << '*';
		}
		if(moveBrush({ position.x + left + i, position.y + top })) {
			cout << '*';
		}
	}

	for(int i=0; i<height; i++) {
		if(moveBrush({ position.x + left, position.y + top + i })) {
			cout << '*';
		}
		if(moveBrush({ position.x + right, position.y + top + i })) {
			cout << '*';
		}
	}
}

void BoxCollider2D::hide() const {
	using namespace std;

	for(int i=0; i<width; i++) {
		if(moveBrush({ position.x + left + i, position.y + bottom })) {
			cout << ' ';
		}
		if(moveBrush({ position.x + left + i, position.y + top })) {
			cout << ' ';
		}
	}

	for(int i=0; i<height; i++) {
		if(moveBrush({ position.x + left, position.y + top + i })) {
			cout << ' ';
		}
		if(moveBrush({ position.x + right, position.y + top + i })) {
			cout << ' ';
		}
	}
}