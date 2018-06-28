#include "stdafx.h"
#include "Animal.h"
#include "World.h"
#include "Organism.h"
#include <cstdlib>

namespace World {
	void Animal::action()
	{
		if (paralysis > 0)
		{
			setParalysis(paralysis - 1);
		}
		else
		{
			int randomInt = (std::rand()%4);
			if (randomInt == 0)
				moveUP();
			else if (randomInt == 1)
				moveDOWN();
			else if (randomInt == 2)
				moveRIGHT();
			else
				moveLEFT();
		}
	}

	void Animal::moveUP()
	{
		if (positionY > 0)
			if (world->freeSpace(positionX, positionY - 1))
				positionY -= 1;
			else
				collision(world->whoIs(positionX, positionY - 1));
		else
			if (world->freeSpace(positionX, positionY + 1))
				positionY += 1;
			else
				collision(world->whoIs(positionX, positionY + 1));
	}
	void Animal::moveDOWN()
	{
		if (positionY < world->getSize())
			if (world->freeSpace(positionX, positionY + 1))
				positionY += 1;
			else
				collision(world->whoIs(positionX, positionY + 1));
		else
			if (world->freeSpace(positionX, positionY - 1))
				positionY -= 1;
			else
				collision(world->whoIs(positionX, positionY - 1));
	}
	void Animal::moveLEFT()
	{
		if (positionX > 0)
			if (world->freeSpace(positionX - 1, positionY))
				positionX -= 1;
			else
				collision(world->whoIs(positionX - 1, positionY));
		else
			if (world->freeSpace(positionX + 1, positionY))
				positionX += 1;
			else
				collision(world->whoIs(positionX + 1, positionY));
	}
	void Animal::moveRIGHT()
	{
		if (positionX < world->getSize())
			if (world->freeSpace(positionX + 1, positionY))
				positionX += 1;
			else
				collision(world->whoIs(positionX + 1, positionY));
		else
			if (world->freeSpace(positionX - 1, positionY))
				positionX -= 1;
			else
				collision(world->whoIs(positionX - 1, positionY));
	}
}