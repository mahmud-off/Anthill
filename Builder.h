#ifndef BUILDER_H
#define BUILDER_H

#include "Ant.h"
// #include "Collecter.h"
// #include "Field.h"

class Collecter;
class Field;

class Builder : public Ant {
public:
	Builder();
	Builder(int weight);
	virtual ~Builder();
	Builder(vector<Collecter*>& list, Collecter* &collecter);

	virtual void work(Field* field) override;


	void collectMaterials(Field *field);
	void helpToCollectMaterial(int x, int y, Field *field); // coordinates

	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif //BUILDER_H