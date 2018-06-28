#ifndef COFFEA_H
#define COFFEA_H
#include "Plant.h"

namespace World {
	class Coffea : public Plant {
	public:
		Coffea(int posX, int posY) : Plant(posX, posY) { setValues(); };
		void createNew(const int posX, const int posY);
		void getName();
		void specialEffect(Organism* org);
	private:
		void setValues();

	};
}
#endif // !COFFEA_H
