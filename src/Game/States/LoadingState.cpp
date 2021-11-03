#include "LoadingState.h"

LoadingState::LoadingState(){

    loadingImage.load("images/ui/loadingImage.jpg");
    music.load("audio/ui/tittle.wav");

    countTime = 0;

}
void LoadingState::reset(){
    countTime = 0;
    setNextState("");
}
void LoadingState::tick(){
    
    loadtoState = getNextState();  // Idk if thats right
    countTime++;

    if(countTime == 90){
        setFinished(true);
        setNextState("loadtoState");
    }

}
void LoadingState::render(){}
void LoadingState::keyPressed(int key){}
void LoadingState::mousePressed(int x, int y, int button){}
void LoadingState::keyReleased(int key){}