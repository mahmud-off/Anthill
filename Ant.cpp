#include "Ant.h"
#include "AntHill.h"
#include <algorithm>
#include <cmath>

#define STEP 1

using namespace std;

Ant::Ant() {
    cout << "ant created\n";
    age = 0;
    role = "None";
    health = 100;
    weight = 0; //���� ���� ������� ������ � �����-�� ���������

    alive = true;
    visible = true;
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

void Ant::moveDown() {
    y -= 1 * STEP;
}

pair<int, int> Ant::findNearestPoint(int x1, int y1, vector<pair<int, int> > v) {
    // vector<pair<int, int>> distances; // first - distance, second - point
    pair<int, int> answerPoint;
    int minn = 1e9;
    for (auto point : v) {
        int res = sqrt((point.first - x1) * (point.first - x1) + (point.second - y1) * (point.second - y1));
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

vector<pair<int, int>> Ant::A_StarSearch(pair<int, int> start, pair<int, int> end) {
    vector<pair<int, int>> path; // path from start to end

    vector<pair<int, int>> options; // варианты куда можно пойти от точки старт (право лево вверх вниз)

    while (start != end) {
        options.push_back({start.first + 1, start.second});
        options.push_back({start.first - 1, start.second});
        options.push_back({start.first, start.second + 1});
        options.push_back({start.first, start.second - 1});

        vector<pair<int, pair<int, int>>> vH; // vector of h(option[i]) for every options
        for (auto x : options) {
            vH.push_back({h(x, end), x});
        }
        sort(vH.begin(), vH.end());
        path.push_back(vH[0].second);
        start = vH[0].second;
    }

    return path;
}


