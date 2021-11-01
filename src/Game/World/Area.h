#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Friend.h"
#include "OverworldCamera.h"
#include "StaticEntity.h"
#include "Boss.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        Area *nextArea;
        std::vector<StaticEntity*> palos;
        Boss *boss;
        
        std::vector<Friend*> friends;
        string name;

    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Friend*> friends, vector<StaticEntity*> palos, string name,  Boss *boss);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        void setPalos(std::vector<StaticEntity*> palos) { this->palos = palos;};
        vector<Enemy*> getEnemies() { return enemies;};
        vector<StaticEntity*> getPalos() { return palos;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        void setFriends(std::vector<Friend*> friends){this->friends = friends;};
        vector<Friend*> getFriends(){return friends;};
        Boss* getBoss() { return boss;};
        string getName() {return name;}
        
};