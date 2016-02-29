#include <iostream>
#include <SDL.h>

#include "Input.h"
#include "Screen.h"
#include "Constant.h"
using namespace fate;

int main(int argc, char* args[])
{
	Screen* screen = Screen::getInstance();
	Input* input = Input::getInstance();


	Sprite* s = new Sprite("test.png");
	s->setOpacity(100);

	bool loop = true;
	while (loop) {
		input->update();

		if (input->trigger(Key::LEFT)) {
			s->setX(s->getX() + 1);
		}
		if (input->press(Key::RIGHT)) {
			s->setX(s->getX() - 1);
		}

		screen->draw();
		SDL_Delay( 16 );
	}

	return 0;
}
