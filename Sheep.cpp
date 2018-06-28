#include "stdafx.h"
#include "World.h"
#include "Animal.h"
#include "Sheep.h"
#include <iostream>
#include <windows.h>

namespace World {
	void Sheep::setValues()
	{
		symbol = 'O';
		strenght = 4;
		initiative = 4;
	}
	void Sheep::getName()
	{
		std::cout << "Owca";
	}
	void Sheep::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Sheep(posX, posY));
	}
}