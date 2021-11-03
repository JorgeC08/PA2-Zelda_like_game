#include "BossBattleState.h"
#include "BattleState.h"

BossBattleState::BossBattleState(Player *player, Area *area) : BattleState(player, area){
    this->statename = "BossBattle";
}
void BossBattleState::startBattle(Boss *boss)
{
    this->boss = boss;
    this->enemy = boss;
    this->currentEnemyHealth = boss->getHealth();
}
void BossBattleState::tick()
{
    currentPlayerHealth = player->getCurrentHealth();

    if (canInteract)
    {
        if (currentPlayerHealth <= 0)
        {
                setNextState("End");
                setFinished(true);
                return;
        }
        else if(currentEnemyHealth <= 0 && this->boss->getLives()>1){
            this->boss->setLives(1);
            this->currentEnemyHealth = boss->getHealth();
        }
        else if (currentEnemyHealth <= 0 && this->boss->getLives()<=1)
        {
            this->boss->setisDefeated(true);
            this->boss->setActive(false);
            setNextState("Win");
            setFinished(true);
            return;
        }
    }

    player->tickFighting();
    enemy->tickFighting();

    if (choice != Move::none && canInteract)
    {
        enemyChoice = rand() % 3 + 1;
        if ((choice == Move::rock && enemyChoice == 2) || (choice == Move::paper && enemyChoice == 3) || (choice == Move::scissors && enemyChoice == 1))
        {
            currentPlayerHealth -= enemy->getDmg() * 2.0;
            currentEnemyHealth -= player->getDmg() / 2.0;
            outcome = Outcome::lose;
        }
        else if ((choice == Move::rock && enemyChoice == 3) || (choice == Move::paper && enemyChoice == 1) || (choice == Move::scissors && enemyChoice == 2))
        {
            currentPlayerHealth -= enemy->getDmg() / 2.0;
            currentEnemyHealth -= player->getDmg() * 2.0;
            outcome = Outcome::win;
        }
        else
        {
            currentPlayerHealth -= enemy->getDmg();
            currentEnemyHealth -= player->getDmg();
            outcome = Outcome::draw;
        }
        
        player->setCurrentHealth(currentPlayerHealth);

        resultTimer = 30;
        canInteract = false;
    }
}