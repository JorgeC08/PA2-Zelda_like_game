#pragma once
#include "ofMain.h"

class Health {
    protected:
        int health;
        int baseDamage;

        int currentHealth;
        
    public:
        virtual int getHealth() = 0; // { return health; };
        virtual void setHealth() = 0; // { this->health = health; };
        virtual int getDmg() = 0; // { return baseDamage; };
        virtual void setDmg() = 0; // { this->baseDamage = baseDamage; };

};   
