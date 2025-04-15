#ifndef BUILDER_H
#define BUILDER_H

#include "Ant.h"
// #include "Collecter.h"
// #include "Field.h"

class Collecter;
class Field;
class Anthill;





class Builder : public Ant {
public:

	
	Builder();
	Builder(int weight);
	virtual ~Builder();
	Builder(vector<Collecter*>& list, Collecter* &collecter);
	void initBuilder();
	virtual void work(Field* field, Anthill* anthill) override;


	void collectMaterials(Field *field, Anthill *anthill);
	void helpToCollectMaterial(int x, int y, Field *field); // coordinates

	void buildAnthill(Anthill *anthill);
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif //BUILDER_H