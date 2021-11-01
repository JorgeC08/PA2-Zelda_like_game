#include "Boss.h"

Boss::Boss(string id, int health, int baseDamage, string entityName, int ox, int oy, int lives) : Enemy(id, health, baseDamage, entityName, ox, oy){
    this->lives = lives;
    this->active = false;
    this->defeated = false;
}

void Boss::Spawn(){
    
    if(getHealth()==0 && lives>=1){
        this->lives = lives - 1;
        this->setHealth(100);
    }
    if(lives == 0){
        this->active = false;
    }
}


