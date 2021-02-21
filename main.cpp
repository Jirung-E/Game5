#include "Player.h"
#include "World.h"

#include <conio.h>


int main() {
	//World w { "TestWorld.txt" };

	Player p { "Player.txt", Position { 5, 5 } };

	p.enterWorld(new World { "TestWorld.txt" });

	//p.show_hitbox = true;

	while(true) {
		p.update();
		if(_kbhit()) {
			char c = _getch();
			if(c == 'q' || c == 'e') {
				break;
			}
			p.move(c);
		}
	}
}