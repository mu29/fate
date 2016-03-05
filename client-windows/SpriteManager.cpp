#include <SDL.h>
#include "SpriteManager.h"
using namespace fate;

SpriteManager::SpriteManager() {
	mSpriteList.clear();
}

SpriteManager::~SpriteManager() {
	mSpriteList.clear();
}

void SpriteManager::addSprite(Sprite& _sprite) {
	for (list<Sprite*>::iterator iter = mSpriteList.begin(); iter != mSpriteList.end(); ++iter) {
		if ((*iter)->mElevation > _sprite.mElevation) {
			mSpriteList.insert(--iter, &_sprite);
			break;
		}
	}

	mSpriteList.push_back(&_sprite);
}

void SpriteManager::removeSprite(Sprite& _sprite) {
	mSpriteList.remove(&_sprite);
}

void SpriteManager::draw(SDL_Renderer& _renderer) {
	for (list<Sprite*>::iterator sprite = mSpriteList.begin(); sprite != mSpriteList.end(); ++sprite) {
		SDL_SetTextureAlphaMod((*sprite)->mTexture, (*sprite)->mOpacity);
		SDL_RenderCopy(&_renderer, (*sprite)->mTexture, NULL, &((*sprite)->mRect));
	}
}

SpriteManager* SpriteManager::mInstance = nullptr;
