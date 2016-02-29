#pragma once
#include <SDL.h>
#include "SpriteManager.h"

namespace fate
{
	class Screen
	{
	private:
		SDL_Rect mWindowRect;
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		SpriteManager* mSpriteManager;
		static Screen* mInstance;

		Screen();
		~Screen();

		bool initSDL();
		bool createWindow();
		bool createRenderer();
		void setUpRenderer();
	public:
		void update();
		void draw();
		SDL_Renderer* getRenderer();

		static Screen* getInstance() {
			if (mInstance == nullptr)
				mInstance = new Screen();

			return mInstance;
		}
	};
}
