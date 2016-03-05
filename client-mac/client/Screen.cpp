//
//  Screen.cpp
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#include "Screen.h"
using namespace fate;

Screen::Screen() {
    mWindowRect.x = 0;
    mWindowRect.y = 0;
    mWindowRect.w = 800;
    mWindowRect.h = 600;
    
    initSDL();
    createWindow();
    createRenderer();
    setUpRenderer();
    mSpriteManager = SpriteManager::getInstance();
}

bool Screen::initSDL() {
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return false;
    return true;
}

bool Screen::createWindow() {
    mWindow = SDL_CreateWindow("Fate / Irregular", mWindowRect.x, mWindowRect.y, mWindowRect.w, mWindowRect.h, 0);
    SDL_SetWindowPosition(mWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    
    if (mWindow == nullptr)
        return false;
    return true;
}

bool Screen::createRenderer() {
    mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
    
    if (mRenderer == nullptr)
        return false;
    return true;
}

void Screen::setUpRenderer() {
    // 렌더러 크기를 윈도우 크기와 맞게 설정
    SDL_RenderSetLogicalSize(mRenderer, mWindowRect.w, mWindowRect.h);
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Screen::draw() {
    SDL_RenderClear(mRenderer);
    mSpriteManager->draw(*mRenderer);
    SDL_RenderPresent(mRenderer);
}

SDL_Renderer* Screen::getRenderer() {
    return mRenderer;
}

Screen* Screen::mInstance = nullptr;
