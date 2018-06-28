#include "stdafx.h"
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"
#include "Grass.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Snail.h"
#include "Guarana.h"
#include "Hedgehog.h"
#include "Belladonna.h"
#include "Coffea.h"
#include "Bear.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	World::World world;
	
	//Tworzenie zwierzat
	world.addOrganism<World::Sheep>();
	world.addOrganism<World::Sheep>();
	world.addOrganism<World::Wolf>();
	world.addOrganism<World::Wolf>();
	world.addOrganism<World::Snail>();
	world.addOrganism<World::Snail>();
	world.addOrganism<World::Hedgehog>();
	world.addOrganism<World::Hedgehog>();
	world.addOrganism<World::Bear>();
	world.addOrganism<World::Bear>();
	//Tworzenie roslin
	world.addOrganism<World::Grass>();
	world.addOrganism<World::Belladonna>();
	world.addOrganism<World::Coffea>();

	//rysowanie swiata poczatkowego
	world.drawWorld();

	//pobieranie przycisku i wykonywanie nastepnej tury, jesli nie podano ESC
	while (_getch() != 27)
	{
		world.nextRound();
	}

    return 0;
}

