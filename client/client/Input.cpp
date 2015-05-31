//
//  Input.cpp
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#include <SDL2/SDL.h>
#include "Input.h"
#include "Constant.h"
using namespace fate;

Input::Input() {
    mCurrentKeyTable = new bool[Key::NUMBER];
    mPreviousKeyTable = new bool[Key::NUMBER];
}

Input::~Input() {
    delete[] mCurrentKeyTable;
    delete[] mPreviousKeyTable;
}

void Input::update() {
    for (int i = 0; i < Key::NUMBER; i++) {
        mPreviousKeyTable[i] = mCurrentKeyTable[i];
    }
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYUP:
                updateKeyTable(event, false);
                break;
            case SDL_KEYDOWN:
                updateKeyTable(event, true);
                break;
            case SDL_MOUSEMOTION:
                
                break;
            case SDL_MOUSEBUTTONUP:
                mCurrentKeyTable[Key::LMOUSE] = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mCurrentKeyTable[Key::LMOUSE] = true;
                break;
            case SDL_QUIT:
                mCurrentKeyTable[Key::QUIT] = true;
                break;
        }
    }
}

void Input::updateKeyTable(SDL_Event& _event, bool _value) {
    switch (_event.key.keysym.sym)
    {
        case SDLK_UP:
            mCurrentKeyTable[Key::UP] = _value;
            break;
        case SDLK_DOWN:
            mCurrentKeyTable[Key::DOWN] = _value;
            break;
        case SDLK_LEFT:
            mCurrentKeyTable[Key::LEFT] = _value;
            break;
        case SDLK_RIGHT:
            mCurrentKeyTable[Key::RIGHT] = _value;
            break;
        case SDLK_SPACE:
        case SDLK_RETURN:
            mCurrentKeyTable[Key::CONFIRM] = _value;
            break;
    }
}

bool Input::trigger(int code) {
    return !mCurrentKeyTable[code] && mPreviousKeyTable[code];
}

bool Input::press(int code) {
    return mCurrentKeyTable[code] && mPreviousKeyTable[code];
}

Input* Input::mInstance = nullptr;
