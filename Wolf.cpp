#include "stdafx.h"
#include "World.h"
#include "Animal.h"
#include "Wolf.h"
#include <iostream>
#include <windows.h>

namespace World {
	void Wolf::setValues()
	{
		symbol = 'W';
		strenght = 9;
		initiative = 5;
	}
	void Wolf::getName()
	{
		std::cout << "Wilk";
	}
	void Wolf::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Wolf(posX, posY));
	}
}