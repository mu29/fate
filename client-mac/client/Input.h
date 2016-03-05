//
//  Input.h
//  client
//
//  Created by 정인중 on 2015. 5. 31..
//  Copyright (c) 2015년 스튜디오 작은별. All rights reserved.
//

#ifndef __client__Input__
#define __client__Input__

namespace fate {
    class Input {
    private:
        int mMouseX;
        int mMouseY;
        int mMouseOX;
        int mMouseOY;
        bool* mCurrentKeyTable;
        bool* mPreviousKeyTable;
        static Input* mInstance;
        
        Input();
        ~Input();
        
        void updateKeyTable(SDL_Event&, bool);
    public:
        void update();
        bool trigger(int);
        bool press(int);
        
        static Input* getInstance() {
            if (mInstance == nullptr)
                mInstance = new Input();
            
            return mInstance;
        }
    };
}

#endif /* defined(__client__Input__) */
