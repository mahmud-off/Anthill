#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <algorithm>

Enemy::Enemy(int x, int y) // Coordinates compute in Field
{
    cout << "Enemy was created\n";
    srand(time(0));
    health = 100;
    hit = 5 + rand() % 10;
    weight = 5 + rand() % 10;
    posX = x;
    posY = y;
}

Enemy::~Enemy() {
    cout << "Enemy was deleted from " << this->posX << " " << this->posY << "\n";
}
//
// bool Enemy::findAnts(Anthill antHill)
// {
//     for(auto ant: antHill.getCollecterList()) {
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     for(auto ant: antHill.getCleanerList()) {
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     for(auto ant: antHill.getBuilderList()){
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     for(auto ant: antHill.getNurseList()) {
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     for(auto ant: antHill.getChildList()) {
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     for(auto ant: antHill.getSoldierList()) {
//         if(distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//
//     return false;
// }
//
// pair<int, int> Enemy::PositionOfNearestAnt(Anthill antHill) {
//
//     double minDist = INT_MAX; //minimal distance
//     pair<int, int> coordinates(this->posX, this->posY);
//
//     for(auto ant: antHill.getCollecterList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//     for(auto ant: antHill.getBuilderList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//     for(auto ant: antHill.getChildList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//     for(auto ant: antHill.getCleanerList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//     for(auto ant: antHill.getNurseList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//     for(auto ant: antHill.getSoldierList()) {
//         double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = ant->getPosX();
//             coordinates.second = ant->getPosY();
//         }
//     }
//
//     return coordinates;
//
// }
//
// bool Enemy::findFood(vector<pair<int, int>> foodCoordinates)
// {
//     for(auto food: foodCoordinates) {
//         if(distance(this->posX, this->posY, food.first, food.second) <= roView)
//             return true;
//     }
//     return false;
// }
//
// pair<int, int> Enemy::PositionOfNearestFood(vector<pair<int, int>> foodCoordinates)
// {
//     double minDist = INT_MAX; //minimal distance
//     pair<int, int> coordinates;
//
//     for(auto food: foodCoordinates) {
//         double temp = distance(this->posX, this->posY, food.first, food.second);
//         if(temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates = food;
//         }
//     }
//     return coordinates;
// }
//
// void Enemy::moveByCoordinates(pair<int, int> coords) {
//     pair<int,int> ourCoordinates(this->posX, this->posY);
//     vector<pair<int, int>> path = A_StarSearch(ourCoordinates, coords);
//     for(auto point: path) {
//         this->posX = point.first;
//         this->posY = point.second;
//     }
// }
//
// void Enemy::moveToRandomPointInROView(int heightOfField, int widthOfField)
// {
//     srand(time(0));
//
//     pair<int, int> randPoint(rand()%widthOfField, rand()%heightOfField);
//     while(distance(this->posX, this->posY, randPoint.first, randPoint.second) > roView) {
//         randPoint.first = rand()%widthOfField;
//         randPoint.second = rand()%heightOfField;
//     }
//     moveByCoordinates(randPoint);
// }
//
//
// double Enemy::distance(int x1, int y1, int x2, int y2)
// {
//     return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
// }
//
// double hFunc(pair<int, int> p1, pair<int, int> p2) {
//     return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
// }
//
// vector<pair<int, int>> Enemy::A_StarSearch(pair<int, int> start, pair<int, int> end) {
//     vector<pair<int, int>> path; // path from start to end
//
//     vector<pair<int, int>> options; // варианты куда можно пойти от точки старт (право лево вверх вниз)
//
//     while (start != end) {
//         options.push_back({start.first + 1, start.second});
//         options.push_back({start.first - 1, start.second});
//         options.push_back({start.first, start.second + 1});
//         options.push_back({start.first, start.second - 1});
//
//         vector<pair<double, pair<int, int>>> vH; // vector of h(option[i]) for every options
//         for (auto x : options) {
//             vH.push_back({hFunc(x, end), x});
//         }
//         sort(vH.begin(), vH.end());
//         path.push_back(vH[0].second);
//         start = vH[0].second;
//     }
//
//     return path;
// }