#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <random>

using namespace std;

class Ant {
private:
    sf::RectangleShape shape; // �������� ������ �� �������������

    pair <int, int> endPoint;
    bool isMoving = false;                 // ���� ��������

    int x, y;
public:
    Ant(const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    void updateMovement();         // ���������� �������

    int getPosX() { return this->x; }
    int getPosY() { return this->y; }

    void setPosX(int x) { this->x = x; }
    void setPosY(int y) { this->y = y; }
};
