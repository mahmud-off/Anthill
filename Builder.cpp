#include "AntHill.h"
#include "builder.h"
#include "Collecter.h"
#include "Field.h"
#include "Informer.h"
#include "Dead.h"
#include "Game.h"
#include "Game.h"

#define CONST_MAKE_ANTHILL_BIGGER 5

Builder::Builder(Game *game) {
    // cout << "builder created\n";
    this->setRole("builder");
    this->initBuilder(game);
    this->setAge(getRandomPoint(400, 800));
    this->setWorkStatus("find_material");
}

Builder::Builder(int weight, Game *game) {
    // cout << "builder created\n";
    this->setRole("builder");
    this->setWeight(weight);
    this->initBuilder(game);
    this->setWorkStatus("find_material");
}


void Builder::collectMaterials(Field *field, Anthill *anthill) {
	//this->changeStatus(); // change status to busy
 //   if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).first) {
 //   	// material is too heavy
 //       pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).second;
 //       Informer informer;
 //       informer.callToGetHelpToCollectMaterials(this, p.first, p.second, field, this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).first);
 //   }
 //   else {
    	// material weight is ok
    this->changeStatus(); // change status to free
    //cout << "Check Ant's point" << field->field[this->getPosY()][this->getPosX()] << " \n";
    field->field[this->getPosY()][this->getPosX()] = "";// already no food in this point
    field->updateMaterialsCoordinatesList();

    //anthill->setMaterialsCount(anthill->getFoodCount() + 1);
    //}
	//anthill->setMaterialsCount(anthill->getMaterialsCount() + 1); // increase materials by 1
}

Builder::Builder(vector<Collecter*>& list, Collecter *&collecter, Game *game) {
	// cout << "builder from collecter" << endl;

	this->setAge(collecter->getAge());
	this->setRole("builder");
    this->setWorkStatus("find_material");
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
	initBuilder(game);
}

void Builder::initBuilder(Game *game) {
    this->getShape().setSize(sf::Vector2f(10.f, 10.f));
    this->getShape().setTexture(&game->textureForBuilder);
    this->getShape().setScale(5.f, 5.f);
}

void Builder::work(Field* field, Anthill* anthill, Game *game){
    string work_status = getWorkStatus();

    if (work_status == "moving_material") {
        this->updateMovement(field, anthill, "collect_material");

        this->changeStatus(); // change status to free
    }
    else if (work_status == "collect_material") {
        collectMaterials(field, anthill);
        this->setWorkStatus("find_home");
    }
    else if (work_status == "find_home") { // && informer->collecterWhoNeedHelp.size() == 0
        this->findHome(anthill);
        this->setWorkStatus("moving_home");
    }
    else if (work_status == "moving_home") {
        this->updateMovement(field, anthill, "find_material");
    }
    else if (work_status == "find_material") {
        buildAnthill(anthill);
        //cout <<"MATERIALS"<< field->materialsCoordinates.size() << "\n";
        if (field->materialsCoordinates.size() != 0) {
            this->changeStatus(); // change status to free
            this->findMaterial(field, game);
            this->setWorkStatus("moving_material");
        }else {
            this->randomMoving(field);
        }
    }
}

Builder::~Builder() {
	//cout << "builder was deleted\n";
}

void Builder::helpToCollectMaterial(int x, int y, Field *field) {
	this->changeStatus(); // change status to busy
    //vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

void Builder::buildAnthill(Anthill *anthill) {
	anthill->setScale(anthill->getScale() + CONST_MAKE_ANTHILL_BIGGER);
}

