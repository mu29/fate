#pragma once

#include <list>
#include <SDL_image.h>
#include "Sprite.h"
using namespace std;

namespace fate 
{
	class SpriteManager
	{
	private:
		list<Sprite*> mSpriteList;
		static SpriteManager* mInstance;
	public:
		SpriteManager();
		~SpriteManager();

		void addSprite(Sprite&);
		void removeSprite(Sprite&);
		void draw(SDL_Renderer&);

		static SpriteManager* getInstance()
		{
			if (mInstance == nullptr)
				mInstance = new SpriteManager();

			return mInstance;
		}
	};
}


