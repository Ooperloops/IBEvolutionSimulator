#ifndef ORGANISM_H
#define ORGANISM_H


#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class Organism
{
private:
	double pixelsPerLine;
	int genomeStep = 0;

	int environX;
	int environY;

	sf::Vector2f PositionToWorld(sf::Vector2i position, float pixelsPerLineX);
public:
	std::string genome = "";
	sf::Vector2i position;
	sf::CircleShape shape;

	Organism(sf::Vector2i position, double pixelsPerLine, int environX, int environY, double seed);

	void Think(bool environ[][100]);


};



#endif // ORGANISM_H
