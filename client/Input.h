#pragma once
#include <SDL.h>

namespace fate 
{
	class Input 
	{
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

		static Input* getInstance() 
		{
			if (mInstance == nullptr)
				mInstance = new Input();

			return mInstance;
		}
	};
}

