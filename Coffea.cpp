#include "stdafx.h"
#include "World.h"
#include "Plant.h"
#include "Coffea.h"
#include <iostream>

namespace World {
	void Coffea::setValues()
	{
		symbol = 'K';
		strenght = 0;
		initiative = 0;
	}
	void Coffea::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Coffea(posX, posY));
	}
	void Coffea::getName()
	{
		std::cout << "Kawowiec";
	}
	void Coffea::specialEffect(Organism* org)
	{
		org->action();
	}

}