#ifndef ANIMAL_H
#define ANIMAL_H
#include "Organism.h"

namespace World {

	class Animal : public Organism {
	public:
		Animal(int posX, int posY) : Organism(posX, posY) {};
		virtual void action();
		void moveUP();
		void moveDOWN();
		void moveLEFT();
		void moveRIGHT();
	};
	
}
#endif // !ANIMAL_H
