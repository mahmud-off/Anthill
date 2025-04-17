#ifndef NURSE_H
#define NURSE_H

#include "Ant.h"
// #include "Cleaner.h"

class Cleaner;
class Field;



class Nurse : public Ant {
public:

	Nurse();
	//virtual ~Nurse();
	void work(Field* field, Anthill* anthill) override;

	Nurse(vector<Cleaner*>& list, Cleaner* &cleaner);
	void initNurse();
	virtual ~Nurse();

	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif // NURSE_H