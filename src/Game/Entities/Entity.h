#pragma once
#include "ofMain.h"
enum Direction {left, right, up, down};
class Entity {
    protected:
        // Fighting coordinates and dimensions
        // int fx, fy, fw, fh;
        // Overworld Coordinates and dimensions
        int ox, oy, ow, oh;
        // ofImage fightingSprite;
        ofImage overworldSprite;

    public:
        Entity(int ox, int oy, int ow, int oh, string overworldPath);
        virtual void tickOverworld() = 0;
        // virtual void tickFighting() = 0;
        virtual void renderOverworld();
        // virtual void renderFighting();
        int getOX() { return ox; };
        int getOY() { return oy; };
        int getOW() { return ow; };
        int getOH() { return oh; };
        ofRectangle getBounds();
        ofRectangle getBounds(int ox, int oy);
        bool collides(Entity* entity);
        void setOX(int ox) { this-> ox = ox; };
        void setOY(int oy) { this-> oy = oy; };
        // int getHealth() { return health; };
        // void setHealth(int health) { this->health = health; };
        // int getDmg() { return baseDamage; };
        // void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
};

class StaticEntity: public Entity {
    protected:
        int renderX = 1000;
        int renderY = 1000;
    public:
        StaticEntity(int ox, int oy, int ow, int oh, string overworldPath);
        virtual void tickOverworld();
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
};