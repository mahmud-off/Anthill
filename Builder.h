#ifndef BUILDER_H
#define BUILDER_H

#include "Ant.h"
// #include "Collecter.h"
// #include "Field.h"

class Collecter;
class Field;
class Anthill;
class Game;




class Builder : public Ant {
public:

	
	Builder(Game *game);
	Builder(int weight, Game *game);
	virtual ~Builder();
	Builder(vector<Collecter*>& list, Collecter* &collecter, Game *game);
	void initBuilder(Game *game);
	void work(Field* field, Anthill* anthill, Game* game) override;


	void collectMaterials(Field *field, Anthill *anthill);
	void helpToCollectMaterial(int x, int y, Field *field); // coordinates

	void buildAnthill(Anthill *anthill);
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif //BUILDER_H