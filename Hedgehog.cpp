#include "stdafx.h"
#include "World.h"
#include "Animal.h"
#include "Hedgehog.h"
#include <iostream>
#include <windows.h>

namespace World {
	void Hedgehog::setValues()
	{
		symbol = 'J';
		strenght = 2;
		initiative = 3;
	}
	void Hedgehog::specialEffect(Organism* org)
	{
		org->setParalysis(2);
	}
	void Hedgehog::getName()
	{
		std::cout << "Jez";
	}
	void Hedgehog::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Hedgehog(posX, posY));
	}
}