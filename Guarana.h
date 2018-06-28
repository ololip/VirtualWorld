#ifndef GUARANA_H
#define GUARANA_H
#include "Plant.h"

namespace World {
	class Guarana : public Plant {
	public:
		Guarana(int posX, int posY) : Plant(posX, posY) { setValues(); };
		void createNew(const int posX, const int posY);
		void getName();
		void specialEffect(Organism* org);
	private:
		void setValues();

	};
}
#endif // !GUARANA_H
