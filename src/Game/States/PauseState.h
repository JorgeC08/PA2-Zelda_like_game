#pragma once

#include "State.h"

class PauseState : public State {

    private:

    bool pause = false;
    ofImage pauseImage;


    public:

    PauseState();

    bool getPause() {return pause;}

    	void reset(){}
		void tick(){}
		void render();
		void keyPressed(int key);
	    void mousePressed(int x, int y, int button){}

};