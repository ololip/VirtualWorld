#include "stdafx.h"
#include "World.h"
#include "Plant.h"
#include "Belladonna.h"
#include <iostream>

namespace World {
	void Belladonna::setValues()
	{
		symbol = 'B';
		strenght = 0;
		initiative = 0;
	}
	void Belladonna::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Belladonna(posX, posY));
	}
	void Belladonna::getName()
	{
		std::cout << "Wilcze jagody";
	}
	void Belladonna::specialEffect(Organism* org)
	{
		std::cout << " i sam ginie";
		world->eraseOrganism(org);
		org->~Organism();
	}

}