#pragma once
#include <iostream>

namespace fate {
	class Error 
	{
	public:
		const static int NULL_SURFACE = 0;
		const static int NULL_TEXTURE = 1;
		const static int SDL_INIT_FAIL = 2;
		const static int CREATE_WINDOW_FAIL = 3;
		const static int CREATE_RENDERER_FAIL = 4;

		static void print(int code, const char* msg) {
			std::cout << msg << " (" << code << ")" << std::endl;
		}
	};

	class Key 
	{
	public:
		const static int NUMBER = 8;
		const static int QUIT = 0;
		const static int LMOUSE = 1;
		const static int RMOUSE = 2;
		const static int UP = 3;
		const static int DOWN = 4;
		const static int LEFT = 5;
		const static int RIGHT = 6;
		const static int CONFIRM = 7;
	};
}
