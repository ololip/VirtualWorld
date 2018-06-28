#ifndef BELLADONNA_H
#define BELLADONNA_H
#include "Plant.h"

namespace World {
	class Belladonna : public Plant {
	public:
		Belladonna(int posX, int posY) : Plant(posX, posY) { setValues(); };
		void createNew(const int posX, const int posY);
		void getName();
		void specialEffect(Organism* org);
	private:
		void setValues();

	};
}
#endif // !BELLADONNA_H
