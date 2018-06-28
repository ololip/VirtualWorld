#include "stdafx.h"
#include "World.h"
#include "Animal.h"
#include "Bear.h"
#include <iostream>
#include <windows.h>

namespace World {
	void Bear::setValues()
	{
		symbol = 'N';
		strenght = 12;
		initiative = 6;
		tiredness = 1;
	}
	void Bear::getName()
	{
		std::cout << "Niedzwiedz";
	}
	void Bear::action()
	{
		if (tiredness <= 5 && paralysis == 0)
		{
			tiredness++;
			strenght--;
		}
		else
		{
			tiredness--;
			strenght++;
			paralysis = tiredness;
		}
		Animal::action();
	}
	void Bear::createNew(const int posX, const int posY)
	{
		Organism::createNew(new Bear(posX, posY));
	}
}