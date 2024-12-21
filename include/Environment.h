#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace IB{

class Environment
{
public:
    double linesPerPixel;

    Environment(int whiteBgDimensions, int tileDimensions);
    Draw(sf::RenderWindow window);

private:
    sf::RectangleShape environmentBG;
    std::vector<sf::RectangleShape> lines;
};

}

#endif // ENVIRONMENT_H
