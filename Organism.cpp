#include "stdafx.h"
#include "World.h"
#include "Organism.h"
#include <iostream>
#include <windows.h>


namespace World {

	Organism::Organism(int posX, int posY)
	{
		positionX = posX;
		positionY = posY;
		symbol = '?';
		age = 0;
		paralysis = 0;
	}
	void Organism::createNew(Organism* org)
	{
		world->createOrganism(org);
	}
	void Organism::increaseAge()
	{
		age++;
	}
	void Organism::collision(Organism* enemy)
	{
		if (getSymbol() == enemy->getSymbol()) //sprawdzam czy to ten sam organizm (rozmna¿anie czy walka)
		{
			if (positionX + 1 < world->getSize() && world->freeSpace(positionX + 1, positionY))	//sprawdzanie wolnego pola
			{
				createNew(positionX + 1, positionY);	//tworzenie nowego zwierzaka

				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 5 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " rozmnaza sie";
			}
			else if (positionX - 1 > 0 && world->freeSpace(positionX - 1, positionY))
			{
				createNew(positionX - 1, positionY);

				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 5 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " rozmnaza sie";
			}
			else if (positionY + 1 < world->getSize() && world->freeSpace(positionX, positionY + 1))
			{
				createNew(positionX, positionY + 1);

				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 5 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " rozmnaza sie";
			}
			else if (positionY - 1 > 0 && world->freeSpace(positionX, positionY - 1))
			{
				createNew(positionX, positionY - 1);

				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 5 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " rozmnaza sie";
			}
		}
		else if (enemy->canI(this))	// je¿eli to nie ten sam organizm to sprawdzam czy mogê zaatakowaæ
		{
			if (strenght > enemy->strenght)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 5 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " pokonuje ";
				enemy->getName();

				positionX = enemy->positionX;
				positionY = enemy->positionY;
				enemy->specialEffect(this);
				world->eraseOrganism(enemy);
				enemy->~Organism();
			}
			else if (strenght < enemy->strenght)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				enemy->getName();
				std::cout << " pokonuje ";
				this->getName();

				specialEffect(enemy);
				world->eraseOrganism(this);
				this->~Organism();
			}
			else if (initiative > enemy->initiative)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " pokonuje ";
				enemy->getName();

				positionX = enemy->positionX;
				positionY = enemy->positionY;
				enemy->specialEffect(this);
				world->eraseOrganism(enemy);
				enemy->~Organism();
			}
			else if (initiative < enemy->initiative)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				enemy->getName();
				std::cout << " pokonuje ";
				this->getName();

				specialEffect(enemy);
				world->eraseOrganism(this);
				this->~Organism();
			}
			else if (age > enemy->age)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " pokonuje ";
				enemy->getName();

				positionX = enemy->positionX;
				positionY = enemy->positionY;
				enemy->specialEffect(this);
				world->eraseOrganism(enemy);
				enemy->~Organism();
			}
			else if (age < enemy->age)
			{
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				enemy->getName();
				std::cout << " pokonuje ";
				this->getName();

				specialEffect(enemy);
				world->eraseOrganism(this);
				this->~Organism();
			}
			else
			{						//je¿eli wszystko równe to atakuj¹cy wygrywa, bo pierwszy zadaje cios
				world->incrementNotebook();
				world->gotoxy(world->getSize() + 5, 7 + world->getNotebook());	//wyswietlenie informacji o zdarzeniu
				this->getName();
				std::cout << " pokonuje ";
				enemy->getName();

				positionX = enemy->positionX;
				positionY = enemy->positionY;
				enemy->specialEffect(this);
				world->eraseOrganism(enemy);
				enemy->~Organism();
			}
		}
		else
		{									//proba przesuniecia na inne sasiednie pole
			if (positionY > 0)
			{
				if (world->freeSpace(positionX, positionY - 1))
					positionY -= 1;
			}
			else if (world->freeSpace(positionX, positionY + 1))
				positionY += 1;
			else if (positionX > 0)
			{
				if (world->freeSpace(positionX - 1, positionY))
					positionX -= 1;
			}
			else if (world->freeSpace(positionX + 1, positionY))
				positionX += 1;
		}
	}
	void Organism::setParalysis(int par)
	{
		paralysis = par;
	}
	int Organism::getInitiative()
	{
		return initiative;
	}
	void Organism::setStrenght(int str)
	{
		strenght = str;
	}
	void Organism::decrementId()
	{
		id--;
	}
	char Organism::getSymbol()
	{
		return symbol;
	}
	int Organism::getStrenght()
	{
		return strenght;
	}
	int Organism::getId()
	{
		return id;
	}
	void Organism::setId(int new_id)
	{
		id = new_id;
	}

	int Organism::getX()
	{
		return positionX;
	}
	int Organism::getY()
	{
		return positionY;
	}
	bool Organism::samePosition(int posX, int posY)
	{
		if (positionX == posX && positionY == posY)
			return true;
		return false;
	}
	void Organism::draw()
	{
		world->gotoxy(getX(), getY());
		std::cout << symbol;
	}
}