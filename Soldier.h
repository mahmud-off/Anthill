#ifndef SOLDIER_H
#define SOLDIER_H

#include "Ant.h"
// #include "Enemy.h"
// #include "Collecter.h"

class Enemy;
class Collecter;
class Game;



class Soldier : public Ant {
public:


    Soldier(Game *game);
    Soldier(int power, Game *game);

    Enemy* getEnemy() { return this->enemy; }
    void setEnemy(Enemy* new_enemy) { enemy = new_enemy; }


    Soldier(vector<Collecter*>& list, Collecter* &collecter, Game *game);
    void helpToFightEnemy(Enemy *enemy, Field *field);
    void fightEnemy(Field *field);

    void initSoldier(Game *game);

    virtual ~Soldier();
    void work(Field* field, Anthill* anthill, Game* game) override;
    Soldier(vector<Ant*>& list, Ant* &collecter);

    using Ant::setPosX;
    using Ant::setPosY;
    using Ant::getPower;

    // getters



private:
    int hit; // ����
    Enemy* enemy;
};

#endif 
