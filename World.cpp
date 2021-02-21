#include "World.h"

#include "DisplayManager.h"

#include <fstream>


World::World(const std::string& file) {
	using namespace std;

	ifstream ifile;
	ifile.open(file);
	if(ifile.is_open()) {
		ifile >> width >> height;
		string str;
		getline(ifile, str);

		object_shape = new char*[height];
		object_box_collider = new BoxCollider2D*[height];
		for(int i=0; i<height; ++i) {
			object_shape[i] = new char[width];
			object_box_collider[i] = new BoxCollider2D[width];

			string tempstr;
			getline(ifile, tempstr);

			for(int k=0; k<width; ++k) {
				object_shape[i][k] = tempstr[k];
				object_box_collider[i][k].setWidth(1);
				object_box_collider[i][k].setHeight(1);
				object_box_collider[i][k].setPosition({ k, i });
				if(object_shape[i][k] == ' ') {
					object_box_collider[i][k].setWidth(0);
					object_box_collider[i][k].setHeight(0);
					object_box_collider[i][k].sleep();
				}
			}
		}
	}
	else {
		width = 0;
		height = 0;

		object_shape = new char*[1];
		object_shape[0] = new char[1];
		object_shape[0][0] = '\0';
		object_box_collider[0][0].setPosition({ 0, 0 });
		object_box_collider[0][0].sleep();
	}
	ifile.close();

	show();
}

World::~World() {
	for(int i=0; i<height; ++i) {
		delete[] object_shape[i];
		delete[] object_box_collider[i];
	}

	delete[] object_shape;
	delete[] object_box_collider;
}


void World::show() const {
	using namespace DisplayManager;
	using namespace std;

	gotoxy(0, 0);

	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			if(object_shape[i][k] == ' ') {
				continue;
			}
			gotoxy(k, i);
			cout << object_shape[i][k];
		}
	}

	//for(int i=0; i<height; ++i) {
	//	for(int k=0; k<width; ++k) {
	//		object_box_collider[i][k].show();
	//	}
	//}
}


int World::getWidth() const {
	return width;
}

int World::getHeight() const {
	return height;
}