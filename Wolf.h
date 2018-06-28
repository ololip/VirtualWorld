#ifndef WOLF_H
#define WOLF_H
#include "Animal.h"
#include "Organism.h"

namespace World {

	class Wolf : public Animal {
	public:
		Wolf(int posX, int posY) : Animal(posX, posY) { setValues(); };
		void getName();
		void createNew(const int posX, const int posY);
	private:
		void setValues();
	};
}
#endif // !WOLF_H
