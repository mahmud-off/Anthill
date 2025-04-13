// Ant.cpp
#include "Ant.h"
#include <iostream>

Ant::Ant(const sf::Vector2f& position) {
    shape.setSize(sf::Vector2f(20, 20)); // ������ 4x4 �������
    shape.setFillColor(sf::Color::Black); // ����� ���� ��� ���������
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
// ����: ������� ��� ������� � ����. ���� �������� �� ��������� ���, ������ �� �������������� (� ��� ���� ��� � �����). ��� ����������, ����� �������� ��������, ����� ��� ������� ���� � ����� ���/���������