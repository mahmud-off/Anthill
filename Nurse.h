#ifndef NURSE_H
#define NURSE_H

#include "Ant.h"
// #include "Cleaner.h"

class Cleaner;
class Field;
class Game;



class Nurse : public Ant {
public:

	Nurse(Game *game);
	//virtual ~Nurse();
	void work(Field* field, Anthill* anthill, Game* game) override;

	Nurse(vector<Cleaner*>& list, Cleaner* &cleaner, Game *game);
	void initNurse(Game *game);
	virtual ~Nurse();

	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif // NURSE_H