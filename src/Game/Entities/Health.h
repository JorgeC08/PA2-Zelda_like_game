#pragma once
#include "ofMain.h"

class Health {
    protected:
        int health;
        int baseDamage;
        ofImage fightingSprite;
        int currentHealth;
        int fx, fy, fw, fh;
    public:
        virtual void tickFighting() = 0;
        virtual void renderFighting() = 0;
        virtual int getHealth() = 0; // { return health; };
        virtual void setHealth(int) = 0; // { this->health = health; };
        virtual int getDmg() = 0; // { return baseDamage; };
        virtual void setDmg(int) = 0; // { this->baseDamage = baseDamage; };

};   
