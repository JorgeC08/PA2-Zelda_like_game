#pragma once
#include "ofMain.h"
#include "Entity.h"

#define LIMITX 2688
#define LIMITY 2560


class StaticEntity: public Entity {
    protected:
        
    public:
        int renderX = 1000;
        int renderY = 1000;
        StaticEntity(int ow, int oh, string overworldPath);
        void renderOverworld();
        virtual void tickOverworld();
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
};