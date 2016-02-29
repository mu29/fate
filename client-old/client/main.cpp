//
//  main.cpp
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

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
        
        if (input->trigger(Key::LMOUSE)) {
            s->setX(s->getX() + 10);
        }
        if (input->press(Key::RIGHT)) {
            s->setX(s->getX() - 10);
        }
        if (input->press(Key::QUIT)) {
            break;
        }
        
        screen->draw();
        //SDL_Delay( 16 );
    }
    
    return 0;
}
