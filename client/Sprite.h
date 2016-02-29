#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace fate 
{
	class Sprite 
	{
	private:
		const char* mFile;
		int mOpacity;
		int mElevation;
		SDL_Rect mRect;
		SDL_Rect mOriginalRect;
		SDL_Texture* mTexture;
	public:
		Sprite();
		Sprite(int, int);
		Sprite(const char*);
		Sprite(const Sprite&);
		~Sprite();

		void loadTexture(const char&);
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		const SDL_Rect& getRect();
		void setX(int);
		void setY(int);
		void setWidth(int);
		void setHeight(int);
		void setRect(SDL_Rect&);
		void setOpacity(int);
		void expend(float);

		friend class SpriteManager;
	};
}
