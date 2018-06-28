#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"
#include "Organism.h"

namespace World {
	class Sheep : public Animal {
	public:
		Sheep(int posX, int posY) : Animal(posX, posY) { setValues(); };
		void getName();
		void createNew(const int posX, const int posY);
	private:
		void setValues();
	};
}
#endif // !SHEEP_H
