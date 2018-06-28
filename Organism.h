#ifndef ORGANISM_H
#define ORGANISM_H
#include "World.h"

namespace World {
	class World;

	class Organism {
	public:
		Organism(int posX, int posY);
		~Organism() {};
		bool canI(Organism* org) { return true; };
		void setParalysis(int par);
		virtual void getName() {};
		virtual void createNew(const int posX, const int posY) {};
		virtual void createNew(Organism* org);
		virtual void specialEffect(Organism* org) {};
		void increaseAge();
		void collision(Organism* enemy);
		void decrementId();
		char getSymbol();
		int getInitiative();
		int getStrenght();
		void setStrenght(int str);
		int getId();
		void setId(int new_id);
		int getX();
		int getY();
		bool samePosition(int posX, int posY);
		void draw();
		virtual void action() {};
		void set_world(World *const world) 
		{
			this->world = world;
		}
	protected:
		int paralysis;
		int positionX;
		int positionY;
		int strenght;
		int initiative;
		char symbol;
		int id;
		int age;
		World *world;
	};
}
#endif // !ORGANISM_H
