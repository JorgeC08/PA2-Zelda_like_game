#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Health.h"
#include "Enemy.h"

class Boss : public Enemy{

    private:
        int lives = 2;
        bool active = false;
        bool defeated = false;

    public:
        Boss(string id, int health, int baseDamage, string entityName, int ox, int oy, int lives);
        ~Boss();
        int getLives() {return lives ;};
        void setLives(int lives) { this->lives = lives;};
        bool getisActive(){return active;};
        void setActive(bool active) {this->active = active;};
        bool getisDefeated(){return defeated;};
        void setisDefeated(bool defeated) {this->defeated = defeated;};
        void Spawn();
};


