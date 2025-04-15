#include "Ant.h"
#include "AntHill.h"
#include "Field.h"
#include "Anthill.h"

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

int getRandom(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};

pair<int, int> Ant::randomAntHill(Anthill* anthill) {
    int hill_x = getRandom(anthill->getPosX(), anthill->getWidth() + anthill->getPosX());
    int hill_y = getRandom(anthill->getPosY(), anthill->getHeight() + anthill->getPosY());

    return { hill_x, hill_y };
}

void Ant::updateMovement(Field* field, Anthill* anthil){
    if (getPosX() != endPoint.first || getPosY() != endPoint.second) {
        if (getPosX() < endPoint.first) setPosX(getPosX() + 1);
        else if (getPosX() > endPoint.first) setPosX(getPosX() - 1);

        if (getPosY() < endPoint.second) setPosY(getPosY() + 1);
        else if (getPosY() > endPoint.second) setPosY(getPosY() - 1);

        shape.setPosition(sf::Vector2f(getPosX(), getPosY()));
        printPosition();
    }
}

void Ant::goHome(Anthill* anthill){
    endPoint = randomAntHill(anthill);
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

void Ant::randomMoving(Field* filed){
    int randMove = getRandom(0, 7);
    vector<pair<int, int>> movesRandOption = {
        {-1,-1}, {0,-1}, {1,1},
        {-1,0},           {1,0},
        {-1,1}, {0,1}, {1,1}
    };

    setPosX(getPosX() + movesRandOption[randMove].first);
    setPosY(getPosY() + movesRandOption[randMove].second);
    shape.setPosition({ getPosX(), getPosY() });

}

bool Ant::operator==(const Ant *right) const {

    if(this->age == right->age &&
        this->health == right->health &&
        this->weight == right->weight &&
        this->x == right->x &&
        this->y == right->y) {
        return true;
    }
    return false;
}

int isValid(pair<int, int> point, int fiedlWidth, int fieldHeight) { // check if point is in the Field
    if (point.first < fiedlWidth && point.second < fieldHeight && point.first > 0 && point.second > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

pair<int, pair<int, int>> Ant::findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int>>> v) {
    // vector<pair<int, int>> distances; // first - distance, second - point
    pair<int, pair<int, int>> answerPoint;
    int minn = 1e9;
    for (auto p : v) {
        pair<int, pair<int, int>> point;
        point.second = p.second;
        point.first = p.first;
        int res = sqrt((point.second.first - x1) * (point.second.first - x1) + (point.second.second - y1) * (point.second.second - y1));
        if (res < minn) {
            minn = res;
            answerPoint = point;
        }
    }
    return answerPoint;
}
