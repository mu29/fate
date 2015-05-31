//
//  Sprite.cpp
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#include "Screen.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "Constant.h"
using namespace fate;

Sprite::Sprite() {
    mRect.x = 0;
    mRect.y = 0;
    mRect.w = 0;
    mRect.h = 0;
    mOriginalRect = mRect;
    mElevation = 0;
    mTexture = NULL;
    
    SpriteManager* manager = SpriteManager::getInstance();
    manager->addSprite(*this);
}

Sprite::Sprite(int _width, int _height) {
    mRect.x = 0;
    mRect.y = 0;
    mRect.w = _width;
    mRect.h = _height;
    mOriginalRect = mRect;
    mElevation = 0;
    mTexture = NULL;
    
    SpriteManager* manager = SpriteManager::getInstance();
    manager->addSprite(*this);
}

Sprite::Sprite(const char* _file) {
    mRect.x = 0;
    mRect.y = 0;
    mElevation = 0;
    mFile = _file;
    loadTexture(*mFile);
    
    SpriteManager* manager = SpriteManager::getInstance();
    manager->addSprite(*this);
}

Sprite::Sprite(const Sprite& _other) {
    mRect.x = _other.mRect.x;
    mRect.y = _other.mRect.y;
    mElevation = _other.mElevation;
    mFile = _other.mFile;
    loadTexture(*mFile);
    
    SpriteManager* manager = SpriteManager::getInstance();
    manager->addSprite(*this);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
}

void Sprite::loadTexture(const char& _file) {
    try {
        SDL_Renderer* renderer = Screen::getInstance()->getRenderer();
        mTexture = IMG_LoadTexture(renderer, &_file);
        if (mTexture == nullptr)
            throw Error::NULL_TEXTURE;
        
        mOpacity = 255;
        SDL_QueryTexture(mTexture, NULL, NULL, &mRect.w, &mRect.h);
        mOriginalRect = mRect;
    } catch (int e) {
        Error::print(e, SDL_GetError());
    }
}

int Sprite::getX() {
    return mRect.x;
}

int Sprite::getY() {
    return mRect.y;
}

int Sprite::getWidth() {
    return mRect.w;
}

int Sprite::getHeight() {
    return mRect.h;
}

const SDL_Rect& Sprite::getRect() {
    return mRect;
}

void Sprite::setX(int _x) {
    mRect.x = _x;
}

void Sprite::setY(int _y) {
    mRect.y = _y;
}

void Sprite::setWidth(int _width) {
    _width = _width < 0 ? -_width : _width;
    mRect.w = _width;
}

void Sprite::setHeight(int _height) {
    _height = _height < 0 ? -_height : _height;
    mRect.h = _height;
}

void Sprite::setRect(SDL_Rect& _rect) {
    mRect.x = _rect.x;
    mRect.y = _rect.y;
    mRect.w = _rect.w;
    mRect.h = _rect.h;
}

void Sprite::setOpacity(int _opacity) {
    mOpacity = _opacity;
}

void Sprite::expend(float _rate) {
    mRect.w *= _rate;
    mRect.h *= _rate;
}
