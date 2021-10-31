#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Health.h"

#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560


class Player : public Entity , Health {
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        vector<char> pressedKeys;
    
    public:
        Player(int health, int baseDamage);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void renderFighting();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        int getHealth() { return health; };
        void setHealth() { this->health = health; };
        int getDmg() { return baseDamage; };
        void setDmg() { this->baseDamage = baseDamage; };
        bool collitiontree = false;

        void setCurrentHealth(int h){currentHealth = h;}

        int getCurrentHealth(){return currentHealth;}
};