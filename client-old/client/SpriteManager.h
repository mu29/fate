//
//  SpriteManager.h
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#ifndef __client__SpriteManager__
#define __client__SpriteManager__

#include <list>
#include <SDL2_image/SDL_image.h>
#include "Sprite.h"
using namespace std;

namespace fate {
    class SpriteManager {
    private:
        list<Sprite*> mSpriteList;
        static SpriteManager* mInstance;
    public:
        SpriteManager();
        ~SpriteManager();
        
        void addSprite(Sprite&);
        void removeSprite(Sprite&);
        void draw(SDL_Renderer&);
        
        static SpriteManager* getInstance() {
            if (mInstance == nullptr)
                mInstance = new SpriteManager();
            
            return mInstance;
        }
    };
}

#endif /* defined(__client__SpriteManager__) */
