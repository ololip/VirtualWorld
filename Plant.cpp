#include "stdafx.h"
#include "Plant.h"
#include "World.h"
#include "Organism.h"
#include <cstdlib>

namespace World {
	void Plant::action()
	{
		int randomInt = (std::rand() % 40);
		if (randomInt < 4)
			if (randomInt == 0)
				sowUP();
			else if (randomInt == 1)
				sowDOWN();
			else if (randomInt == 2)
				sowRIGHT();
			else
				sowLEFT();
	}
	void Plant::sowUP()
	{
		if (positionY > 0)
			if (world->freeSpace(positionX, positionY - 1))
				createNew(positionX, positionY-1);

	}
	void Plant::sowDOWN()
	{
		if (positionY < world->getSize())
			if (world->freeSpace(positionX, positionY + 1))
				createNew(positionX, positionY + 1);

	}
	void Plant::sowLEFT()
	{
		if (positionX > 0)
			if (world->freeSpace(positionX - 1, positionY))
				createNew(positionX - 1, positionY);
	}
	void Plant::sowRIGHT()
	{
		if (positionX < world->getSize())
			if (world->freeSpace(positionX + 1, positionY))
				createNew(positionX + 1, positionY);
	}
}