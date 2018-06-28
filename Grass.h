#ifndef GRASS_H
#define GRASS_H
#include "Plant.h"

namespace World {
	class Grass : public Plant {
	public:
		Grass(int posX, int posY) : Plant(posX, posY) { setValues(); };
		void createNew(const int posX, const int posY);
		void getName();

	private:
		void setValues();

	};
}
#endif // !GRASS_H
