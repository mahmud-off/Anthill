// Ant.cpp
#include "Ant.h"
#include <iostream>

Ant::Ant(const sf::Vector2f& position) {
    shape.setSize(sf::Vector2f(20, 20)); // Размер 4x4 пикселя
    shape.setFillColor(sf::Color::Black); // Яркий цвет для видимости
    shape.setPosition(position);
}

void Ant::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ant::updateMovement()
{

    if (x < path.first) this->x += 1;
    else if (x > path.first) this->x -= 1;
    

    if (y < path.second) this->y += 1;
    else if (y > path.second) this->y -= 1;

    shape.setPosition(sf::Vector2f(x, y));

}
// идея: создать два массива с едой. Один отвечает за свободную еду, другой за использующуюся (к ней идут или её несут). Это необходимо, чтобы избежать ситуации, когда два муравья идут к однйо еде/материалу