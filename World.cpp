#include "stdafx.h"
#include "World.h"
#include "Windows.h"
#include <algorithm>


namespace World {

	World::World()
	{
		organism_counter = 0;
		notebook_counter = 0;
		size = 20;
	}
	World::World(int worldSize)
	{
		organism_counter = 0;
		notebook_counter = 0;
		setSize(worldSize);
	}
	Organism* World::whoIs(int posX, int posY)				//zwraca informacje o organizmie znajdujacym sie na danym polu
	{
		for (int i = 0; org_tab.size(); i++)
			if (org_tab[i]->samePosition(posX, posY))
				return org_tab[i];
		return nullptr;
	}
	void World::eraseOrganism(Organism* defeated)
	{
		int to_erase = -1;
		if (org_tab.back() != defeated)						//czy usuwany jest ostatnim organismem
			to_erase = defeated->getId() + 1;				//jak nie to zachowuje nastepne id
		for(unsigned int i=0;i<org_tab.size();i++)
			if(org_tab[i]==defeated)
				org_tab.erase(org_tab.begin()+i);			//usuwam organizm z listy organizmow
		if (to_erase != -1)
			for (unsigned int i = to_erase; i<org_tab.size(); i++)	//dekrementacja id kolejnych organizmow na liscie
				org_tab[i]->decrementId();
		organism_counter--;									//zmniejszenie licznika organizmow o usuniety element
	}
	bool World::freeSpace(int posX, int posY)				//zwraca informacje czy dane pole jest puste
	{
		bool test = true;
		//if (posX >= getSize() || posX <= 0 || posY <= 0 || posY >= getSize())	//je¿eli poza plansz¹ to zwracam false
		//	return false;
		for (unsigned int i = 0; i < org_tab.size(); i++)
			if (org_tab[i]->samePosition(posX, posY))
				test = false;									//je¿eli jakiœ organizm tam jest to zwracam false
		return test;
	}
	void World::incrementNotebook()
	{
		notebook_counter++;
	}
	int World::getNotebook()
	{
		return notebook_counter;
	}
	int World::getCounter()
	{
		return organism_counter;
	}
	int World::getSize()
	{
		return size;
	}
	void World::setSize(int worldSize)
	{
		this->size = worldSize;
	}
	void World::nextRound()
	{
		system("cls");
		notebook_counter = 0;
		//wykonywanie akcji organizmów
		for (int j = 6; j >= 0; j--)	//uwzglednienie inicjatywy
			for (unsigned int i = 0; i < org_tab.size(); i++)
				if (org_tab[i]->getInitiative() == j)
					org_tab[i]->action();

		//inkrementowanie wieku wszystkich organizmów
		for (unsigned int i = 0; i < org_tab.size(); i++)
			org_tab[i]->increaseAge();

		//ponowne rysowanie œwiata
		drawWorld();
	}
	void World::createOrganism(Organism* new_org)
	{
		if (freeSpace(new_org->getX(), new_org->getY()))
		{
			new_org->set_world(this);
			new_org->setId(organism_counter);
			org_tab.push_back(new_org);
			organism_counter++;
		}
	}
	void World::drawWorld()
	{
		//rysowanie ramy
		for (int i = 0; i <= size; i++)
		{
			gotoxy(size + 1, i);
			std::cout << "|";
		}
		for (int i = 0; i <= size + 1; i++)
		{
			gotoxy(i, size + 1);
			std::cout << "-";
		}
		gotoxy(size + 1, size + 1);
		std::cout << "+";

		//rysowanie organizmów
		draw_organisms();

		//legenda
		gotoxy(getSize() + 5, 5);
		std::cout << "Notatnik:";
		legend();
	}

	void World::draw_organisms()
	{
		std::for_each(org_tab.begin(), org_tab.end(), [](Organism *o) { o->draw(); });
	}

	void World::gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void World::legend()//rysowanie legendy
	{
		gotoxy(1, getSize() + 2);
		std::cout << "Legenda:";
		gotoxy(1, getSize() + 3);
		std::cout << "O - Owca";
		gotoxy(1, getSize() + 4);
		std::cout << "W - Wilk";
		gotoxy(1, getSize() + 5);
		std::cout << "J - Jez";
		gotoxy(1, getSize() + 6);
		std::cout << "S - Slimak";
		gotoxy(1, getSize() + 7);
		std::cout << "N - Niedzwiedz";
		gotoxy(1, getSize() + 8);
		std::cout << "T - Trawa";
		gotoxy(1, getSize() + 9);
		std::cout << "G - Guarana";
		gotoxy(1, getSize() + 10);
		std::cout << "B - Wilcze jagody";
		gotoxy(1, getSize() + 11);
		std::cout << "K - Kawowiec";

		gotoxy(getSize() + 5, 2);
		std::cout << "Projekt opracowal Oliwer Lipinski 167930";
		gotoxy(getSize() + 5, 3);
		std::cout << "Nastepna runda - dowolny przycisk, ESC - zakonczenie gry";
	}
}
