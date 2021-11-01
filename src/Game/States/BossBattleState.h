#pragma once

#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Area.h"
#include "Boss.h"
#include "BattleState.h"

class BossBattleState : public BattleState {
    protected:
        Boss *boss;
    public:

        BossBattleState(Player *player, Area *area);
        void tick();
        void startBattle(Boss *boss);
        Boss* getBoss(){return boss;};
        void setBoss(Boss *boss){this->boss = boss;};
};