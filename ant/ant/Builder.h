#ifndef BUILDER_H
#define BUILDER_H

#include "Ant.h"
#include "Collecter.h"
#include "Field.h"


#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>


class Builder : public Ant {
public:

	sf::RectangleShape bui;
	Builder();
	Builder(int weight);
	virtual ~Builder();
	Builder(vector<Collecter*>& list, Collecter* &collecter);

	void initBuilder();

	virtual void work(Field field) override { collectMaterials(field); }


	void collectMaterials(Field field);
	void helpToCollectMaterial(int x, int y, Field field); // coordinates

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif //BUILDER_H