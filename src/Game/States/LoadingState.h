#pragma once

#include "State.h"

class LoadingState : public State {

    private:
        ofImage loadingImage;
		int countTime;
		string loadtoState;
    public:
        LoadingState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		

};