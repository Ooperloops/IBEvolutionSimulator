#include "Organism.h"

using namespace std;

sf::Vector2f Organism::PositionToWorld(sf::Vector2i position, float pixelsPerLineX, float pixelsPerLineY) {
	return sf::Vector2f(pixelsPerLineX * position.x, pixelsPerLineY * position.y);
}

Organism::Organism(sf::Vector2i position, double pixelsPerLine, int environX, int environY, double seed) {
	this->position = position;
	this->pixelsPerLine = pixelsPerLine;

	srand(seed);

	for (int i = 0; i < 5; i++) {
		int num = rand() % 4 + 0;
		genome += std::to_string(num);
	}

	shape.setRadius(pixelsPerLine / 2);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(PositionToWorld(position, pixelsPerLine, pixelsPerLine));
}

void Organism::Think(bool environ[][100]) {
	switch (genome[genomeStep]) {
	case '1':
		if (position.x < 99 && environ[position.x + 1][position.y] == 0) {
			environ[position.x][position.y] = 0;
			position.x += 1;
			environ[position.x][position.y] = 1;
		}
		break;
	case '2':
		if (position.y > 0 && environ[position.x][position.y - 1] == 0) {
			environ[position.x][position.y] = 0;
			position.y -= 1;
			environ[position.x][position.y] = 1;
		}
		break;
	case '3':
		if (position.x > 0 && environ[position.x - 1][position.y] == 0) {
			environ[position.x][position.y] = 0;
			position.x -= 1;
			environ[position.x][position.y] = 1;
		}
		break;
	case '0':
		if (position.y < 99 && environ[position.x][position.y + 1] == 0) {
			environ[position.x][position.y] = 0;
			position.y += 1;
			environ[position.x][position.y] = 1;
		}
		break;
	}

	genomeStep += 1;
	if (genomeStep + 1 > genome.size()) {
		genomeStep = 0;
	}

	shape.setPosition(PositionToWorld(position, pixelsPerLine, pixelsPerLine));
}

