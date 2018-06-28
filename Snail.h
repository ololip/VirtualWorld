#ifndef SNAIL_H
#define SNAIL_H
#include "Animal.h"
#include "Organism.h"

namespace World {
	class Snail : public Animal {
	public:
		Snail(int posX, int posY) : Animal(posX, posY) { setValues(); };
		void action();
		void getName();
		bool canI(Organism* org);
		void createNew(const int posX, const int posY);
	private:
		void setValues();
	};
}
#endif // !Snail_H
