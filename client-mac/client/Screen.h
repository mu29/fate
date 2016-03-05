//
//  Screen.h
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#ifndef __client__Screen__
#define __client__Screen__

#include <SDL2/SDL.h>
#include "SpriteManager.h"

namespace fate {
    class Screen {
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

#endif /* defined(__client__Screen__) */
