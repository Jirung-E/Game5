#include "Sprite.h"

#include <fstream>
#include <iostream>
#include <Windows.h>


// ----------------------------------------------------------------------------- //
Sprite::Sprite() : width { 0 }, height { 0 }, pivot { 0, 0 }, position { 0, 0 } {
	sprite = new char*[1];
	sprite[0] = new char[1];
	sprite[0][0] = ' ';

	init();
}

Sprite::Sprite(Pivot pivot, Position position) : Sprite { } {
	this->pivot = pivot;
	this->position = position;

	init();
}

Sprite::Sprite(Pivot pivot) : Sprite { } {
	this->pivot = pivot;

	init();
}

Sprite::Sprite(Position position) : Sprite { } {
	this->position = position;

	init();
}

Sprite::Sprite(const std::string& file, Pivot pivot, Position position) :
	pivot { pivot }, position { position } {
	using namespace std;

	ifstream ifile;
	ifile.open(file);
	if(ifile.is_open()) {
		ifile >> width >> height;
		string str;
		getline(ifile, str);

		sprite = new char*[height];
		for(int i=0; i<height; ++i) {
			sprite[i] = new char[width];

			string tempstr;
			getline(ifile, tempstr);

			for(int k=0; k<width; ++k) {
				sprite[i][k] = tempstr[k];
			}
		}
	}
	else {
		width = 0;
		height = 0;

		sprite = new char*[1];
		sprite[0] = new char[1];
		sprite[0][0] = ' ';
	}
	ifile.close();


	//if(this->pivot.x < 0 || this->pivot.x > width) {
	//	this->pivot.x = 0;
	//}
	//if(this->pivot.y < 0 || this->pivot.y > height) {
	//	this->pivot.y = 0;
	//}

	init();
}

Sprite::Sprite(const std::string& file, Pivot pivot) : Sprite { file, pivot, { 0, 0 } } {
	
}

Sprite::Sprite(const std::string& file, Position position) : Sprite { file, { 0, 0 }, position } {
	
}

Sprite::Sprite(const std::string& file) : Sprite { file, { 0, 0 }, { 0, 0 } } {
	
}

Sprite::~Sprite() {
	for(int i=0; i<height; ++i) {
		delete[] sprite[i];
	}

	delete[] sprite;
}
// ----------------------------------------------------------------------------- //


bool Sprite::moveBrush(Position pos) const {
	if(pos.x < 0 || pos.y < 0) {
		return false;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { SHORT(pos.x), SHORT(pos.y) });

	return true;
}

void Sprite::init() {
	left = -static_cast<int>((width-1)/2);
	right = static_cast<int>(width/2);
	top = -static_cast<int>((height-1)/2);
	bottom = static_cast<int>(height/2);
}


void Sprite::show() const {
	using namespace std;

	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			if(moveBrush(Position { position.x + left + k, position.y + top + i }) == true) {
				cout << sprite[i][k];
			}
		}
	}
}

void Sprite::hide() const {
	using namespace std;

	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			if(moveBrush(Position { position.x + left + k, position.y + top + i }) == true) {
				cout << ' ';
			}
		}
	}
}


int Sprite::getWidth() const {
	return width;
}
int Sprite::getHeight() const {
	return height;
}


Pivot Sprite::getPivot() const {
	return pivot;
}

void Sprite::setPivot(Pivot pivot) {
	this->pivot = pivot;
}

Position Sprite::getPosition() const {
	return position;
}

void Sprite::setPosition(Position pos) {
	position = pos;
}



int Sprite::getLeft() const {
	return left;
}

int Sprite::getRight() const {
	return right;
}

int Sprite::getTop() const {
	return top;
}

int Sprite::getBottom() const {
	return bottom;
}