#ifndef NURSE_H
#define NURSE_H

#include "Ant.h"
#include "Cleaner.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

class Nurse : public Ant {
public:
	sf::RectangleShape nur;
	Nurse();
	//virtual ~Nurse();
	virtual void work(Field field) override { ; }

	Nurse(vector<Cleaner*>& list, Cleaner* &cleaner);
	void initNurse();
	virtual ~Nurse();

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif // NURSE_H