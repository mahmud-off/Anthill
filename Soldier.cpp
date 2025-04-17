#include "Soldier.h"

#include "Collecter.h"
#include "Enemy.h"
#include "Field.h"

Soldier::Soldier() {
    cout << "soldier created\n";
    this->setRole("soldier");
    this->initSoldier();
    // hit = 10; // power of hit
}

Soldier::Soldier(int power) {
    cout << "soldier created\n";
    this->setRole("soldier");
    this->setPower(power);
    this->initSoldier();
}

Soldier::Soldier(vector<Collecter *> &list, Collecter *&collecter) {
    cout << "soldier from collecter" << endl;
    this->setAge(collecter->getAge());
    this->setRole("soldier");
    this->setHealth(collecter->getHealth());
    this->setWeight(collecter->getWeight());
    this->setPosX(collecter->getPosX());
    this->setPosY(collecter->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == collecter) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
    initSoldier();
}

void Soldier::helpToFightEnemy(Enemy* enemy, Field* field)
{
    return;
}

Soldier::~Soldier() {
    cout << "soldier was deleted\n";
}
Soldier::Soldier(vector<Ant*>& list, Ant*& collecter)
{
}
void Soldier::initSoldier()
{
    this->getShape().setSize(sf::Vector2f(10.f, 10.f));
    this->getShape().setFillColor(sf::Color::Blue);
}

void Soldier::fightEnemy(Enemy *enemy, Field *field) {
    while (enemy->getHealth() > 0 && this->getHealth() > 0) { // fight until someone die
        srand(time(0));
        int whoStartFight = rand() % 2; // 0 - soldier, 1 - enemy
        if (whoStartFight == 0) { // soldier hits first
            if (enemy->getHealth() - this->getPower() < 0) { // soldier hitted enemy and enemy died
                enemy->setHealth(0);
                field->deleteEnemy(enemy); // delete killed enemy
                // need to delete enemy here
            }
            else {
                enemy->setHealth(enemy->getHealth() - this->getPower()); // enemy didn't die
            }
        }
        else if (whoStartFight == 1) { // enemy hits first
            if (this->getHealth() - enemy->getPower() < 0) { // enemy hitted soldier and soldier died
                this->setHealth(0);
                // need to delete killed soldier here
            }
            else {
                this->setHealth(this->getHealth() - enemy->getPower()); // soldier didn't die
            }
        }
    }
}
