#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <iostream>
#include <windows.h>
#include "Organism.h"

namespace World {

	class World {
		friend class Organism;
	public:
		World();
		World(int);
		Organism* whoIs(int posX, int posY);
		void eraseOrganism(Organism* defeated);
		bool freeSpace(int posX, int posY);
		void incrementNotebook();
		int getCounter();
		int getNotebook();
		int getSize();
		void setSize(int worldSize);
		void nextRound();
		void drawWorld();
		void draw_organisms();
		template<class toAdd> void addOrganism()
		{
			toAdd *new_org = new toAdd(rand() % size, rand() % size);
			createOrganism(new_org);
		}
		void createOrganism(Organism* new_org);
		void gotoxy(int x, int y);
	private:
		void legend();
		int notebook_counter;
		std::vector<Organism*> org_tab;
		int size;
		int organism_counter;

	};
}
#endif // !WORLD_H
