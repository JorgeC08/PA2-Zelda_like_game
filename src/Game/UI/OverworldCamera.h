#pragma once

#include "EntityManager.h"

#define DIMENSIONX 640  // camera dimensions
#define DIMENSIONY 480  // camera dimensions
#define OXDIMENSION 2688  // world dimensions
#define OYDIMENSION 2560  // world dimensions

class OverworldCamera {
    private:
        Player *player;
        int playerX, playerY;
        int playerW, playerH;
        int leftCornerX;
        int rightCornerX;
        int topCornerY;
        int bottomCornerY;

    public:
        OverworldCamera(Player *player);
        void tick();
        int getPlayerX(){ return playerX; };
        int getPlayerY(){ return playerY; };
        int getDimensionX(){ return DIMENSIONX; };
        int getDimensionY(){ return DIMENSIONY; };
        int getLeftCornerX() { return leftCornerX; };
        int getRightCornerX() { return rightCornerX; };
        int getTopCornerY() { return topCornerY; };
        int getBottomCornerY() { return bottomCornerY; };

};