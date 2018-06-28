#include "stdafx.h"
#include "World.h"
#include "Plant.h"
#include "Guarana.h"
#include <iostream>

namespace World {
	void Guarana::setValues()
	{
		symbol = 'G';
		strenght = 0;
		initiative = 0;
	}
	void Guarana::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Guarana(posX, posY));
	}
	void Guarana::getName()
	{
		std::cout << "Guarana";
	}
	void Guarana::specialEffect(Organism* org)
	{
		org->setStrenght(org->getStrenght() + 3);
	}

}