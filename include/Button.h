#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>


class Button
{
private:
    int sizeX;
    int sizeY;

    std::function<void()> activator;
public:
    sf::RectangleShape buttonShape;

    Button(int sizeX, int sizeY, void(*func)());
    OnUpdate();
    Draw();
};

#endif // BUTTON_H
