#include "Ant.h"
#include "AntHill.h"
#include <algorithm>
#include <cmath>
#include <random>
#include "Field.h"

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

void Ant::moveRight() {
    x += 1 * STEP;
}

void Ant::moveLeft() {
    x -= 1 * STEP;
}

void Ant::moveUp() {
    y += 1 * STEP;
}


void Ant::randomMoving(int heightOfField, int widthOfField)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distX(0, widthOfField);
    std::uniform_int_distribution<int> distY(0, heightOfField);
    int randomNumberX = distX(gen);
    int randomNumberY = distY(gen);
    pair<int, int> randPoint(randomNumberX, randomNumberY);

    cout << "Your random point: " << randPoint.first << " " << randPoint.second << "\n";

    moveByCoordinates(randPoint);
}

void Ant::moveByCoordinates(pair<int, int> point)
{
    while(x != point.first || y != point.second) {
        if(x < point.first) ++x;
        else if (x > point.first) --x;

        if(y < point.second) ++y;
        else if(y > point.second) --y;
        printPosition();
    }
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

void Ant::moveDown() {
    y -= 1 * STEP;
}

int isValid(pair<int, int> point, int fiedlWidth, int fieldHeight) {
    // check if point is in the Field
    if (point.first < fiedlWidth && point.second < fieldHeight && point.first > 0 && point.second > 0) {
        return 1;
    } else {
        return 0;
    }
}


pair<int, pair<int, int> > Ant::findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int> > > v) {
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
