#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Organism.h"
#include "Environment.h"

using namespace std;

//-------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------

//-------------------------------------------------------------
// Setup Components
//-------------------------------------------------------------
const int windowSizeX = 1000;
const int windowSizeY = 1000;

bool environmentTiles[100][100];

const int initialPopulation = 1000;
//-------------------------------------------------------------
// Default Window Components
//-------------------------------------------------------------

sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Evolution Simulator", sf::Style::Titlebar | sf::Style::Close);
vector<Organism> ecosystem;

int main()
{

    for (int i = 0; i < initialPopulation; i++) {

        srand(i*i*time(NULL));
        bool positionvalid = true;
        int xPos;
        int yPos;

        while(positionvalid){
            xPos = rand() % 100;
            yPos = rand() % 100;
            positionvalid = environmentTiles[xPos][yPos];
        }

        environmentTiles[xPos][yPos] = false;
        Organism org(sf::Vector2i(xPos, yPos), pixelsPerLineY, environmentX, environmentY, i * i);
        ecosystem.push_back(org);
    }

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(environment);

        for (int i = 0; i < lines.size(); i++) {
            window.draw(lines[i]);
        }

        for (int j = 0; j < ecosystem.size(); j++) {
            ecosystem[j].Think(&environmentTiles);
            window.draw(ecosystem[j].shape);
        }


        Sleep(50);
        window.display();
    }

    return 0;
}


