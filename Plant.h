#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"

namespace World {
	class Plant : public Organism {
	public:
		Plant(int posX, int posY) : Organism(posX, posY) {};
		virtual void action();
		void sowUP();
		void sowDOWN();
		void sowLEFT();
		void sowRIGHT();

	};
}
#endif // !PLANT_H
