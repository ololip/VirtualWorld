#ifndef BEAR_H
#define BEAR_H
#include "Animal.h"
#include "Organism.h"

namespace World {
	class Bear : public Animal {
	public:
		Bear(int posX, int posY) : Animal(posX, posY) { setValues(); };
		void getName();
		void action();
		void createNew(const int posX, const int posY);
	private:
		int tiredness;
		void setValues();
	};
}
#endif // !BEAR_H
