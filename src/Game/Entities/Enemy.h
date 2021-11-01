#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Health.h"

#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560

class Enemy : public Entity , Health {
    private:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
        int renderX = 1000;
        int renderY = 1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        string id;
        int moveTimer;
        bool dead = false;
        string entityName;
        ofImage sprite; 
        

    
    public:
        Enemy(string id, int health, int baseDamage, string entityName, int ox, int oy);
        ~Enemy();
        int getOX() { return ox; };
        int getOY() { return oy; };
        bool isDead() { return dead;};
        void kill() { this->dead = true;};
        void revive() { this->dead = false;};
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void renderFighting();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
        int getHealth() { return health; };
        void setHealth(int health) {this->health = health;};
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage){this->baseDamage =baseDamage ;};
};