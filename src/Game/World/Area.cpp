#include "Area.h"

<<<<<<< HEAD
Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<StaticEntity*> palos, vector<Friend*> friends, string name)
=======
Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<StaticEntity*> palos, string name, Boss *boss)
>>>>>>> b058a5554b2f1c0f09ebb3bbcf5bd380c9f4aa26
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->palos = palos;
<<<<<<< HEAD

    this->friends = friends;
=======
    this->boss = boss;
>>>>>>> b058a5554b2f1c0f09ebb3bbcf5bd380c9f4aa26
    this->name = name;
}

void Area::resetEnemies(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}
