#include "Ant.h"
#include "AntHill.h"
#include "Field.h"
#include "Anthill.h"
#include "Dead.h"
#define STEP 1

using namespace std;

Ant::Ant() {
    cout << "ant created\n";
    age = 0;
    role = "None";
    health = 100;
    weight = 0; //���� ���� ������� ������ � �����-�� ���������
}

Ant::~Ant() {
    cout << "Ant destructor;!!!\n";
}

int getRandomPoint(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};

pair<int, int> Ant::randomAntHill(Anthill* anthill) {
    int hill_x = getRandomPoint(anthill->getPosX(), anthill->getWidth() + anthill->getPosX());
    int hill_y = getRandomPoint(anthill->getPosY(), anthill->getHeight() + anthill->getPosY());

    return { hill_x, hill_y };
}

void Ant::updateMovement(Field* field, Anthill* anthil){
    if (getPosX() != endPoint.first || getPosY() != endPoint.second) {
        if (getPosX() < endPoint.first) setPosX(getPosX() + 1);
        else if (getPosX() > endPoint.first) setPosX(getPosX() - 1);

        if (getPosY() < endPoint.second) setPosY(getPosY() + 1);
        else if (getPosY() > endPoint.second) setPosY(getPosY() - 1);

        shape.setPosition(sf::Vector2f(getPosX(), getPosY()));
        //printPosition();
    }
}

void Ant::goHome(Anthill* anthill){
    endPoint = randomAntHill(anthill);
}

void Ant::findEnemy(Field* field){
    vector<pair<int, pair<int, int>>> enemiesPositions;
    vector<Enemy*> enemies = field->getEnemiesList();

    for (int i = 0; i < enemies.size(); ++i) {
        enemiesPositions[i] = { 0, {enemies[i]->getPosX(), enemies[i]->getPosY()} };
    }

    pair<int, pair<int, int>> point = findNearestPoint(this->getPosX(), this->getPosY(), enemiesPositions);
    
    endPoint.first = point.second.first;
    endPoint.second = point.second.second;
}

void Ant::findFood(Field* field){
    pair<int, pair<int, int>> point = findNearestPoint(getPosX(), getPosY(), field->foodCoordinates);
    endPoint.first = point.second.first;
    endPoint.second = point.second.second;
}

void Ant::findMaterial(Field* field){
    pair<int, pair<int, int>> point = findNearestPoint(getPosX(), getPosY(), field->materialsCoordinates);
    endPoint.first = point.second.first;
    endPoint.second = point.second.second;
}

void Ant::findDeadAnts(Anthill* anthill){

    vector<pair<int, pair<int, int>>> deadAntsPositions;
    vector<Dead*> deadList = anthill->getDeadAntsList();

    for (int i = 0; i < deadList.size(); ++i) {
        deadAntsPositions[i] = { 0, {deadList[i]->getPosX(), deadList[i]->getPosY()} }; // узнать про 0
    }
    pair<int, pair<int, int>> point = findNearestPoint(this->getPosX(), this->getPosY(), deadAntsPositions);

    endPoint.first = point.second.first;
    endPoint.second = point.second.second;
}

void Ant::randomMoving(Field* filed){
    int randMove = getRandomPoint(0, 7);
    vector<pair<int, int>> movesRandOption = {
        {-1,-1}, {0,-1}, {1,1},
        {-1,0},           {1,0},
        {-1,1}, {0,1},    {1,1}
    };

    setPosX(getPosX() + movesRandOption[randMove].first);
    setPosY(getPosY() + movesRandOption[randMove].second);
    shape.setPosition(sf::Vector2f(getPosX(), getPosY() ));

}

bool Ant::operator==(const Ant *right) const {
    if (this->age == right->age &&
        this->health == right->health &&
        this->weight == right->weight &&
        this->x == right->x &&
        this->y == right->y) {
        return true;
    }
    return false;
}

pair<int, pair<int, int>> Ant::findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int>>> v) {
    // vector<pair<int, int>> distances; // first - distance, second - point
    pair<int, pair<int, int> > answerPoint;
    int minn = 1e9;
    for (auto p: v) {
        pair<int, pair<int, int> > point;
        point.second = p.second;
        point.first = p.first;
        int res = sqrt(
            (point.second.first - x1) * (point.second.first - x1) + (point.second.second - y1) * (
                point.second.second - y1));
        if (res < minn) {
            minn = res;
            answerPoint = point;
        }
    }
    return answerPoint;
}

int h(pair<int, int> p1, pair<int, int> p2) {
    int res = sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
    return res;
}
/*
vector<pair<int, int> > Ant::A_StarSearch(pair<int, int> start, pair<int, int> end, Field *field) {
    vector<pair<int, int> > path; // path from start to end

    vector<pair<int, int> > options; // варианты куда можно пойти от точки старт (право лево вверх вниз)

    while (start != end) {
        pair<int, int> p1 = make_pair(start.first + 1, start.second);
        pair<int, int> p2 = make_pair(start.first - 1, start.second);
        pair<int, int> p3 = make_pair(start.first, start.second + 1);
        pair<int, int> p4 = make_pair(start.first, start.second - 1);
        if (isValid(p1, field->getWidth(), field->getHeight()))
            options.push_back(p1);
        if (isValid(p2, field->getWidth(), field->getHeight()))
            options.push_back(p2);
        if (isValid(p3, field->getWidth(), field->getHeight()))
            options.push_back(p3);
        if (isValid(p4, field->getWidth(), field->getHeight()))
            options.push_back(p4);


        vector<pair<int, pair<int, int> > > vH; // vector of h(option[i]) for every options
        for (auto x: options) {
            vH.push_back({h(x, end), x});
        }
        sort(vH.begin(), vH.end());
        path.push_back(vH[0].second);
        start = vH[0].second;
    }

    return path;
}
*/
void Ant::changeStatus() {
    if (this->getStatus() == "free") {
        this->status = "busy";
    }
    else if (this->getStatus() == "busy") {
        this->status = "free";
    }
}

sf::RectangleShape& Ant::getShape()
{
    return this->shape;
}
