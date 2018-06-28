#include "stdafx.h"
#include "World.h"
#include "Animal.h"
#include "Snail.h"
#include <iostream>
#include <windows.h>

namespace World {
	void Snail::setValues()
	{
		symbol = 'S';
		strenght = 1;
		initiative = 1;
	}
	void Snail::action()
	{
		if (rand() % 10 == 0)
			Animal::action();
	}
	bool Snail::canI(Organism* org)
	{
		if (org->getStrenght() < 2)	//jeœli sila przeciwnika mniejsza od 2 to nie moze zaatakowac
			return false;
		if (org->getStrenght() > 4)	//jeœli sila przeciwnika wieksza od 4 to 60% szans na nie moze zaatakowac
			if (std::rand() % 10 < 6)
				return false;
		return true;				//jeœli nie, to mo¿e zaatakowaæ
	}
	void Snail::getName()
	{
		std::cout << "Slimak";
	}
	void Snail::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Snail(posX, posY));
	}
}