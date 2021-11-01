#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::tick()
{
    for (unsigned int i = 0; i < area->getPalos().size(); i++)
    {
        if (player->collides(area->getPalos().at(i)))
        {
            if(!player->getPressedKeys().empty()){
                int ox = player->getOX();
                int oy = player->getOY();
                int ow = player->getOW();
                int oh = player->getOH();
                switch (player->getPressedKeys().at(0))
                {
                case 'a':
                        ox -= area->getPalos().at(i)->getOW();
                        break;
                case 'd':
                        ox += area->getPalos().at(i)->getOW();
                    break;
                case 'w':
                        oy -= area->getPalos().at(i)->getOH();
                    break;
                case 's':
                        oy += area->getPalos().at(i)->getOH();
                    break;
                }
                if(area->getPalos().at(i)->getBounds().intersects( ofRectangle(ox, oy, ow, oh) )){
                    keyReleased(player->getPressedKeys().at(0));
                }
            }

        } 
    }
    player->tickOverworld();

    //Collision with enemies
    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            area->getEnemies().at(i)->tickOverworld();
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("Battle");
                setFinished(true);
            }
        }
      
    }       
    for(unsigned int i = 0; i < area->getFriends().size(); i++){
        area->getFriends().at(i)->tickOverworld();
        if(player->collides(area->getFriends().at(i))){
                if(interact){
                    greetings.load("audio/hello.mp3");
                    interact = false;
                }
        }
    }  
    
    //Collision with Boss
    if(area->getRemainingEnemies()==0){
        area->getBoss()->setActive(true);
        area->getBoss()->tickOverworld();
        if(area->getBoss()->collides(player)){
            setNextState("BossBattle");
            setFinished(true);
        }
    }

    
    camera->tick();
}

void OverworldState::drawHUD(){
    
    ofImage healthbar;
    healthbar.load("images/ui/healthbar.png");
    healthbar.draw(ofGetWidth()/2 - 96,ofGetHeight() - 130, 192, 192);


    for (int i = 0; i < 3; i++)
    {
        double playerHealthRatio = (double)player->getCurrentHealth() / (double)player->getHealth();
        
        if(playerHealthRatio < 0){
            playerHealthRatio = 0;
        }
        else if (playerHealthRatio < 0.33)
        {
            ofSetColor(200 - i * 20, 60 - i * 20, 60 - i * 20);
        }
        else if (playerHealthRatio < 0.66)
        {
            ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
        }
        else
        {
            ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);
        }
        ofDrawRectangle(ofGetWidth()/2 - 52, ofGetHeight() - 42 + i * 4, (int)(36 * playerHealthRatio) * 4, 4);

    }
    ofSetColor(255,255,255);

    if(area->getBoss()->getisActive() && area->getRemainingEnemies()<=0){
        ofDrawBitmapString("Boss remaining... ", ofGetWidth()/2 -80, ofGetHeight() -70);
    }
    else{
        ofDrawBitmapString(ofToString(area->getRemainingEnemies()) + " enemies remaining", ofGetWidth()/2 -80, ofGetHeight() -70);
    }
    ofDrawBitmapString(area->getName(), ofGetWidth()/2 +75, ofGetHeight() -70);
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();
    for (unsigned int i = 0; i < area->getPalos().size(); i++){
        int playerDistanceX = area->getPalos().at(i)->getOX() - camera->getLeftCornerX();
        int playerDistanceY = area->getPalos().at(i)->getOY() - camera->getTopCornerY();
        area->getPalos().at(i)->setRenderX(playerDistanceX);
        area->getPalos().at(i)->setRenderY(playerDistanceY);
        area->getPalos().at(i)->renderOverworld();    
    
    }

    if(area->getRemainingEnemies()==0){
        int playerDistanceX = area->getBoss()->getOX() - camera->getLeftCornerX();
        int playerDistanceY = area->getBoss()->getOY() - camera->getTopCornerY();
        area->getBoss()->setRenderX(playerDistanceX);
        area->getBoss()->setRenderY(playerDistanceY);
        area->getBoss()->renderOverworld();
    } 
    else{

        for (unsigned int i = 0; i < area->getEnemies().size(); i++)
        {
            if (!area->getEnemies().at(i)->isDead())
            {
                int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getLeftCornerX();
                int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getTopCornerY();
                area->getEnemies().at(i)->setRenderX( playerDistanceX);
                area->getEnemies().at(i)->setRenderY(playerDistanceY);
                area->getEnemies().at(i)->renderOverworld();
            }
        }
            for(unsigned int i = 0; i < area->getFriends().size(); i++){
            int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
            area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getFriends().at(i)->renderOverworld();
        }
        drawHUD();
    }
}
void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);

    if(key == 'r') area->resetEnemies();
    
    if(key == 'e') interact = !interact;
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}
