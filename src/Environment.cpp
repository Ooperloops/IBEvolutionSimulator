#include "Environment.h"

namespace IB{
    Environment::Environment(int whiteBgDimensions, int tileDimensions){
        linesPerPixel = whiteBgDimensions/tileDimensions;

        environmentBG.setSize(sf::Vector2f(whiteBgDimensions,whiteBgDimensions));

        for (int i = 0; i < tileDimensions; i++) {
            sf::RectangleShape lineX(sf::Vector2f(1, whiteBgDimensions));
            lineX.setPosition(sf::Vector2f(linesPerPixel * i, 0));
            lineX.setFillColor(sf::Color::Black);
            lines.push_back(lineX);

            sf::RectangleShape lineY(sf::Vector2f(whiteBgDimensions, 1));
            lineY.setPosition(sf::Vector2f(0, linesPerPixel * i));
            lineY.setFillColor(sf::Color::Black);
            lines.push_back(lineY);
        }
    }

    Environment::Draw(sf::RenderWindow window){
        window.draw(environmentBG);

        for(int i = 0; i < lines.size(); i++){
            window.draw(lines[i]);
        }
    }
}
