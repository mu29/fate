//
//  SpriteManager.cpp
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#include <SDL2/SDL.h>
#include "SpriteManager.h"
using namespace fate;

SpriteManager::SpriteManager() {
    mSpriteList.clear();
}

SpriteManager::~SpriteManager() {
    mSpriteList.clear();
}

void SpriteManager::addSprite(Sprite& _sprite) {
    for(list<Sprite*>::iterator iter = mSpriteList.begin(); iter != mSpriteList.end(); ++iter) {
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
    for(list<Sprite*>::iterator sprite = mSpriteList.begin(); sprite != mSpriteList.end(); ++sprite) {
        SDL_SetTextureAlphaMod((*sprite)->mTexture, (*sprite)->mOpacity);
        SDL_RenderCopy(&_renderer, (*sprite)->mTexture, NULL, &((*sprite)->mRect));
    }
}

SpriteManager* SpriteManager::mInstance = nullptr;

