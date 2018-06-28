#ifndef HEDGEHOG_H
#define HEDGEHOG_H
#include "Animal.h"
#include "Organism.h"

namespace World {
	class Hedgehog : public Animal {
	public:
		Hedgehog(int posX, int posY) : Animal(posX, posY) { setValues(); };
		void getName();
		void specialEffect(Organism* org);
		void createNew(const int posX, const int posY);
	private:
		void setValues();
	};
}
#endif // !Hedgehog_H
