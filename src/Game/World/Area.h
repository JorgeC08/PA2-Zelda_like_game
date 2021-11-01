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
<<<<<<< HEAD
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<StaticEntity*> palos, vector<Friend*> friends, string name);
=======
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<StaticEntity*> palos, string name, Boss *boss);
>>>>>>> b058a5554b2f1c0f09ebb3bbcf5bd380c9f4aa26
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
<<<<<<< HEAD
        void setFriends(std::vector<Friend*> friends){this->friends = friends;};
        vector<Friend*> getFriends(){return friends;};
=======
        Boss* getBoss() { return boss;};
>>>>>>> b058a5554b2f1c0f09ebb3bbcf5bd380c9f4aa26
        string getName() {return name;}
        
};