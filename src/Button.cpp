#include "Button.h"

using namespace std;

Button::Button(int sizeX, int sizeY, void(*func)()){
    buttonShape.setScale(sf::Vector2f(sizeX, sizeY));
    activator = func;
}

Button::OnUpdate()
{
    //dtor
}

Button::Draw(){
    //dtor
}
