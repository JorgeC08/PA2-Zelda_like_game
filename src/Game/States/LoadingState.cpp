#include "LoadingState.h"

LoadingState::LoadingState(){

    loadingImage.load("images/ui/loadingImage.jpg");
    // music.load("audio/ui/tittle.wav");

    countTime = 0;
    this->statename = "Loading";

}
void LoadingState::reset(){
    countTime = 0;
}
void LoadingState::tick(){ 
    
    ofResetElapsedTimeCounter(); // reset time to 0;
    while(ofGetElapsedTimef()<3){
    }
    setFinished(true);
    

}
void LoadingState::render(){
    loadingImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}
void LoadingState::keyPressed(int key){}
void LoadingState::mousePressed(int x, int y, int button){}
void LoadingState::keyReleased(int key){}