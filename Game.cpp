#include "Game.h"

#define TICS_TO_ANTHILL_DESTROYING 15

int getRandom(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};


Game::Game(): anthill(500, 500, 100, 1000, 800,0,0,0,0,1100,500,100,100), field(0, 0) {
    this->initVar();
    this->initWindow();
    this->antHillX = this->anthill.getPosX();
    this->antHillY = this->anthill.getPosY();
    this->antHillHeight = this->anthill.getHeight();
    this->antHillWidth = this->anthill.getWidth();
    field.setHW(this->videoMode.width, this->videoMode.height);
    this->initTexture();
    this->initTextureForChild();
    this->initTextureForSoldier();
    this->initTextureForEnemy();
    this->initTextureForBuilder();
    this->initTextureForCollecter();
    this->initTextureForMaterial();
    this->initTextureForFood();
    this->initTextureForNurse();
    this->initTextureForCleaner();

    this->initSprite();
    this->initSpriteForChild();
    this->initSpriteForSoldier();
    this->initSpriteForEnemy();
    this->initSpriteForBuilder();
    this->initSpriteForCollecter();
    this->initSpriteForMaterial();
    this->initSpriteForFood();
    this->initSpriteForNurse();
    this->initSpriteForCleaner();
}


const bool Game::getWindowIsOpen() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}


void Game::initTexture() {
    this->fon.loadFromFile("anthill.png");
}
void Game::initSprite() {
    this->sprite.setTexture(this->fon);
    this->sprite.setScale(0.95f, 0.75f);
}

void Game::initTextureForChild() {
    this->textureForChildren.loadFromFile("child.png");
}
void Game::initSpriteForChild() {
    this->spriteForChildren.setTexture(this->textureForChildren);
    this->spriteForChildren.setScale(1.3f, 1.f);
}

void Game::initTextureForSoldier() {
    this->textureForSoldiers.loadFromFile("solder.png");
}
void Game::initSpriteForSoldier() {
    this->spriteForSoldiers.setTexture(this->textureForChildren);
    this->spriteForSoldiers.setScale(1.3f, 1.f);
}

void Game::initTextureForEnemy() {
    this->textureForEnemy.loadFromFile("monstr 2.png");
}
void Game::initSpriteForEnemy() {
    this->spriteForEnemy.setTexture(this->textureForEnemy);
    this->spriteForEnemy.setScale(1.3f, 1.f);
}

void Game::initTextureForBuilder() {
    this->textureForBuilder.loadFromFile("builder.png");
}
void Game::initSpriteForBuilder() {
    this->spriteForBuilder.setTexture(this->textureForBuilder);
    this->spriteForBuilder.setScale(1.3f, 1.f);
}

void Game::initTextureForCollecter() {
    this->textureForCollecter.loadFromFile("collecter.png");
}
void Game::initSpriteForCollecter() {
    this->spriteForCollecter.setTexture(this->textureForCollecter);
    this->spriteForCollecter.setScale(1.3f, 1.f);
}

void Game::initTextureForMaterial() {
    this->textureForMaterial.loadFromFile("material.png");
}
void Game::initSpriteForMaterial() {
    this->spriteForMaterial.setTexture(this->textureForMaterial);
    this->spriteForMaterial.setScale(1.3f, 1.f);
}

void Game::initTextureForFood() {
    this->textureForFood.loadFromFile("food.png");
}
void Game::initSpriteForFood() {
    this->spriteForFood.setTexture(this->textureForFood);
    this->spriteForFood.setScale(1.3f, 1.f);
}

void Game::initTextureForNurse() {
    this->textureForNurse.loadFromFile("nurse.png");
}
void Game::initSpriteForNurse() {
    this->spriteForNurse.setTexture(this->textureForNurse);
    this->spriteForNurse.setScale(1.3f, 1.f);
}

void Game::initTextureForCleaner() {
    this->textureForCleaner.loadFromFile("cleaner.png");
}
void Game::initSpriteForCleaner() {
    this->spriteForCleaner.setTexture(this->textureForCleaner);
    this->spriteForCleaner.setScale(1.3f, 1.f);
}

void Game::initVar() {
    this->window = nullptr;


    this->bornRoomHeight = 200;
    this->bornRoomWidth = 200;
    this->bornRoomX = 900;
    this->BornRoomY = 300;

    this->antHillWidth = 600;
    this->antHillHeight = 500;
    this->antHillX = 460;
    this->antHillY = 250;


    this->storageX = 200;
    this->storageY = 200;
    this->storageHeight = 200;
    this->storageWidth = 200;
}

void Game::initWindow() {
    this->videoMode.height = 1000;
    this->videoMode.width = 1920;

    this->window = new sf::RenderWindow(this->videoMode, "Anthill", sf::Style::Default);
    this->window->setFramerateLimit(1000);
}


void Game::createWorld() {
    this->anthill.generateAnts(this->window->getSize().x / 2, this->window->getSize().y / 2, &this->informer, this);
    storage.createStorage(anthill.getFoodCount(), this->storageX, this->storageY, this->storageHeight,
                          this->storageWidth, this);
    field.ResourceSpawn(&this->anthill, this);
    field.enemiesSpawn(&this->anthill, this);

    for (int i = 0; i < this->anthill.getCollecterList().size(); i++) {
        this->anthill.getCollecterList()[i]->setPosX(getRandom(this->antHillX, this->antHillWidth + this->antHillX));
        this->anthill.getCollecterList()[i]->setPosY(getRandom(this->antHillY, this->antHillY + this->antHillHeight));
        this->anthill.getCollecterList()[i]->getShape().setPosition(
            (float) this->anthill.getCollecterList()[i]->getPosX(),
            (float) this->anthill.getCollecterList()[i]->getPosY());
    }

    for (int i = 0; i < this->anthill.getBuilderList().size(); i++) {
        this->anthill.getBuilderList()[i]->setPosX(getRandom(this->antHillX, this->antHillWidth + this->antHillX));
        this->anthill.getBuilderList()[i]->setPosY(getRandom(this->antHillY, this->antHillY + this->antHillHeight));
        this->anthill.getBuilderList()[i]->getShape().setPosition((float) this->anthill.getBuilderList()[i]->getPosX(),
                                                                  (float) this->anthill.getBuilderList()[i]->getPosY());
    }

    for (int i = 0; i < this->anthill.getSoldierList().size(); i++) {
        this->anthill.getSoldierList()[i]->setPosX(getRandom(this->antHillX, this->antHillWidth + this->antHillX));
        this->anthill.getSoldierList()[i]->setPosY(getRandom(this->antHillY, this->antHillY + this->antHillHeight));
        this->anthill.getSoldierList()[i]->getShape().setPosition((float) this->anthill.getSoldierList()[i]->getPosX(),
                                                                  (float) this->anthill.getSoldierList()[i]->getPosY());
    }

    for (int i = 0; i < this->anthill.getNurseList().size(); i++) {
        this->anthill.getNurseList()[i]->setPosX(getRandom(this->antHillX, this->antHillWidth + this->antHillX));
        this->anthill.getNurseList()[i]->setPosY(getRandom(this->antHillY, this->antHillY + this->antHillHeight));
        this->anthill.getNurseList()[i]->getShape().setPosition((float) this->anthill.getNurseList()[i]->getPosX(),
                                                                (float) this->anthill.getNurseList()[i]->getPosY());
    }

    for (int i = 0; i < this->anthill.getChildList().size(); i++) {
        this->anthill.getChildList()[i]->setPosX(getRandom(this->bornRoomX, this->antHillWidth + this->antHillX));

        this->anthill.getChildList()[i]->setPosY(getRandom(this->BornRoomY, this->BornRoomY + this->bornRoomHeight));

        this->anthill.getChildList()[i]->getShape().setPosition((float) this->anthill.getChildList()[i]->getPosX(),
                                                                (float) this->anthill.getChildList()[i]->getPosY());
        //cout << "---------" << (float)this->anthill.getChildList()[i]->getPosX() << "  " << (float)this->anthill.getChildList()[i]->getPosY() << "\n";
        //cout << this->anthill.getChildList()[i]->get_shape().getFillColor().toInteger()<<"\n";
    }

    for (int i = 0; i < this->anthill.getCleanerList().size(); i++) {
        this->anthill.getCleanerList()[i]->setPosX(getRandom(this->antHillX, this->antHillWidth + this->antHillX));
        this->anthill.getCleanerList()[i]->setPosY(getRandom(this->antHillY, this->antHillY + this->antHillHeight));
        this->anthill.getCleanerList()[i]->getShape().setPosition((float) this->anthill.getCleanerList()[i]->getPosX(),
                                                                  (float) this->anthill.getCleanerList()[i]->getPosY());
    }
}


void Game::update() {
    this->pollEvents();
    this->window->clear();

    //Update will be here
    this->anthill.update(&this->field, this, &this->informer);
    //this->anthill.getChildList()[0]->randomMoving(&this->field);

    //testing
    /*
    for (int i = 0; i < this->anthill.getCollecterList().size(); ++i) {
    Collecter* ant = this->anthill.getCollecterList()[i];

    ant->setEndPoint({ 0,0 });

    ant->updateMovement(&this->field, &this->anthill);
    }
*/
    //ant->setPosX(getRandom(0,1024));
    //ant->setPosY()


	//this->anthill.update(&this->field);

	this->tics++;
	if (tics == TICS_TO_ANTHILL_DESTROYING) {
		anthill.anthillDestroying();
		this->tics = 0;
		this->anthill.updateAntsAge();
	}
	//this->upadateAnts();
}

void Game::render() {
    this->window->draw(this->sprite);

	this->renderCollecter();
	this->renderSoldier();
	this->renderCleaner();
	this->renderChild();
	this->renderNurse();
	this->renderBuilder();
	this->renderFoodStorage();
	this->renderFood();
	this->renderMaterials();
	this->renderEnemy();
	this->renderDead();

	this->window->display();
}

void Game::renderCollecter() {
    for (int i = 0; i < anthill.getCollecterList().size(); i++) {
        this->window->draw(anthill.getCollecterList()[i]->getShape());
    }
}

void Game::renderCleaner() {
    for (int i = 0; i < anthill.getCleanerList().size(); i++) {
        this->window->draw(anthill.getCleanerList()[i]->getShape());
    }
}

void Game::renderDead() {
    for (int i = 0;i < anthill.getDeadAntsList().size();i++) {
        //cout << anthill.getDeadAntsList()[i]->getShape().getPosition().x <<" "<< anthill.getDeadAntsList()[i]->getShape().getPosition().y << "\n";
        this->window->draw(anthill.getDeadAntsList()[i]->getShape());
    }
    for( int i = 0; i < anthill.detectedDead.size(); ++i) {
        this->window->draw(anthill.detectedDead[i]->getShape());
    }
}


void Game::renderSoldier() {
    for (int i = 0; i < anthill.getSoldierList().size(); i++) {
        this->window->draw(anthill.getSoldierList()[i]->getShape());
    }
}

void Game::renderChild() {
    //cout << anthill.getChildList().size() << "\n";
    for (int i = 0; i < anthill.getChildList().size(); i++) {
        this->window->draw(anthill.getChildList()[i]->getShape());
    }
}

void Game::renderNurse() {
    for (int i = 0; i < anthill.getNurseList().size(); i++) {
        this->window->draw(anthill.getNurseList()[i]->getShape());
    }
}

void Game::renderBuilder() {
    for (int i = 0; i < anthill.getBuilderList().size(); i++) {
        this->window->draw(anthill.getBuilderList()[i]->getShape());
    }
}

void Game::renderFoodStorage() {
    for (int i = 0; i < storage.getCount(); i++) {
        this->window->draw(storage.storage[i]->getFoodShape());
    }
}

void Game::renderFood() {
    for (int i = 0; i < field.foodCoordinates.size(); i++) {
        this->window->draw(field.foodCoordinates[i]->getFoodShape());
    }

    // for (int i = 0; i < field.detectedFood.size(); i++) {
    //     this->window->draw(field.detectedFood[i]->getFoodShape());
    // }
}

void Game::renderMaterials() {
    for (int i = 0; i < field.materialsCoordinates.size(); i++) {
        this->window->draw(field.materialsCoordinates[i]->getMaterialsShape());
    }
    for (int i = 0; i < field.detectedMaterials.size(); i++) {
        this->window->draw(field.detectedMaterials[i]->getMaterialsShape());
    }
}

void Game::renderEnemy() {
    for (int i = 0; i < field.getEnemiesList().size(); i++) {
        this->window->draw(field.getEnemiesList()[i]->getEnemyShape());
    }
}

Game::~Game() {
    delete this->window;
}
