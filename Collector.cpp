// Ant.cpp
#include "Collector.h"
#include <iostream>

#define ANTHILL_WH 200

int getRandom(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};

Collector::Collector(const sf::Vector2f& position) {
    shape.setSize(sf::Vector2f(20, 20)); // Размер 20x20 пикселя
    shape.setFillColor(sf::Color::Black); // Яркий цвет для видимости
    shape.setPosition(position);

    
    setPosX(position.x);
    setPosY(position.y);
    cout << getPosX() << " " << getPosY() << endl;
}

void Collector::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Collector::updateMovement()
{
    if (x != endPoint.first || y != endPoint.second) {
        if (x < endPoint.first) setPosX(getPosX() + 1);
        else if (x > endPoint.first) setPosX(getPosX() - 1);

        if (y < endPoint.second) setPosY(getPosY() + 1);
        else if (y > endPoint.second) setPosY(getPosY() - 1);

        shape.setPosition(sf::Vector2f(x, y));
    }else if ( !((x == ANTHILL_WH && y <= ANTHILL_WH) || (y == ANTHILL_WH && x <= ANTHILL_WH)) ){ // "если мы не дома, то находим координаты для дома" 
        endPoint.first = (x >= ANTHILL_WH ? ANTHILL_WH : x);
        endPoint.second = (y >= ANTHILL_WH ? ANTHILL_WH : y);
    }else{
        endPoint.first = getRandom(0, 1024);
        endPoint.second =  endPoint.first > ANTHILL_WH ? getRandom(0, 768) : getRandom(ANTHILL_WH+1, 768);
        //this->isMoving = true;
    }



}
// идея: создать два массива с едой. Один отвечает за свободную еду, другой за использующуюся (к ней идут или её несут). Это необходимо, чтобы избежать ситуации, когда два муравья идут к однйо еде/материалу