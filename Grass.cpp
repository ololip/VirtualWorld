#include "stdafx.h"
#include "World.h"
#include "Plant.h"
#include "Grass.h"
#include <iostream>

namespace World {
	void Grass::setValues()
	{
		symbol = 'T';
		strenght = 0;
		initiative = 0;
	}
	void Grass::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Grass(posX, posY));
	}
	void Grass::getName()
	{
		std::cout << "Trawa";
	}


}