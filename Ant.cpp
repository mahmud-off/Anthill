#include "Ant.h"
#include "AntHill.h"
#include "Field.h"
#include "Anthill.h"
#include "Dead.h"
#include "Food.h"
#include "Materials.h"
#include "Game.h"
#define STEP 1

using namespace std;

Ant::Ant() {
    //cout << "ant created\n";
    x = 0;
    y = 0;
    age = 0;
    role = "None";
    health = 100;
    weight = 0; //���� ���� ������� ������ � �����-�� ���������
}

Ant::~Ant() {
    //cout << "Ant destructor;!!!\n";

}

int isValid(pair<int, int> point, int fiedlWidth, int fieldHeight) {
    // check if point is in the Field
    if (point.first < fiedlWidth && point.second < fieldHeight && point.first > 0 && point.second > 0) {
        return 1;
    } else {
        return 0;
    }
}

int getRandomNumber__(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};

pair<int, int> Ant::randomAntNurseryPos(Anthill* anthill) {

    int x = getRandomNumber__(anthill->getBornRoomX() - anthill->getBornRoomWidth()*1.5, anthill->getBornRoomX() + anthill->getBornRoomWidth()*1.5);
    int y = getRandomNumber__(anthill->getBornRoomY() - anthill->getBornRoomHeght()*1.5, anthill->getBornRoomY() + anthill->getBornRoomHeght()*1.5);



    pair<int, int> point = { x,y };
    return point;
};

pair<int, pair<int, int> > Ant::findNearestPointCollecter(int x1, int y1,vector<Food*> v, vector<Food*>& detectedFood, Game* game) {
    // vector<pair<int, int>> distances; // first - distance, second - point
    pair<int, pair<int, int> > answerPoint = {0,{0,0}};
    int minn = 1e9;
    Food* elem = nullptr;
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        Food* p = v[i];
        pair<int, pair<int, int> > point;
        point.second.first = p->getX();
        point.second.second = p->getY();
        point.first = p->getWeight();
        int res = sqrt(
            (point.second.first - x1) * (point.second.first - x1) + (point.second.second - y1) * (
                point.second.second - y1));
        if (res < minn) {
            minn = res;
            answerPoint = point;
            elem = p;
            index = i;
        }
    }
    if(elem != nullptr) {
        Food *detectedP = new Food(elem->getX(),elem->getY(), elem->getWeight(), game);
        detectedFood.push_back(detectedP);
        v.erase(v.begin()+index);
    }
    //cout << "-->" << v.size() << " " << detectedFood.size() << "\n";
    return answerPoint;
}

pair<int, pair<int, int> > Ant::findNearestPointBuilder(int x1, int y1, vector<Materials*> v, vector<Materials*>& detectedMaterials, Game *game) {
    // vector<pair<int, int>> distances; // first - distance, second - point
    pair<int, pair<int, int> > answerPoint = { 0,{0,0} };
    int minn = 1e9;
    Materials* elem = nullptr;
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        Materials* p = v[i];
        pair<int, pair<int, int> > point;
        point.second.first = p->getX();
        point.second.second = p->getY();
        point.first = p->getWeight();
        int res = sqrt(
            (point.second.first - x1) * (point.second.first - x1) + (point.second.second - y1) * (
                point.second.second - y1));
        if (res < minn) {
            minn = res;
            answerPoint = point;
            elem = p;
            index = i;
        }
    }
    if (elem != nullptr) {
        Materials* detectedP = new Materials(elem->getX(), elem->getY(), elem->getWeight(), game);
        //detectedP->initMaterials(elem->getX(), elem->getY(), elem->getWeight());
        detectedMaterials.push_back(detectedP);
        v.erase(v.begin() + index);
    }
    //cout << "-->" << v.size() << " " << detectedMaterials.size() << "\n";
    return answerPoint;
}

pair<int, pair<int, int>> Ant::findNearestPointDead(int x1, int y1, vector<Dead*> v, vector<Dead*>& detectedDead)
{
    pair<int, pair<int, int> > answerPoint = { 0,{0,0} };
    int minn = 1e9;
    Dead* elem = nullptr;
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        Dead* p = v[i];
        pair<int, pair<int, int> > point;
        point.second.first = p->getX();
        point.second.second = p->getY();
        point.first = p->getWeight();
        int res = sqrt(
            (point.second.first - x1) * (point.second.first - x1) + (point.second.second - y1) * (
                point.second.second - y1));
        if (res < minn) {
            minn = res;
            answerPoint = point;
        }
    }
    if (elem != nullptr) {
        Dead* detectedP = new Dead(elem->getX(), elem->getY(), elem->getWeight());
        //detectedP->initMaterials(elem->getX(), elem->getY(), elem->getWeight());
        detectedDead.push_back(detectedP);
        v.erase(v.begin() + index);
    }
    //cout << "-->" << v.size() << " " << detectedMaterials.size() << "\n";
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

int Ant::getRandomPoint(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
}

void Ant::stay_on_your_Point(int x, int y) {
    this->x = x;
    this->y = y;
};

pair<int, int> Ant::randomAntHill(Anthill* anthill) {
    int hill_x = getRandomPoint(anthill->getPosX()-100, anthill->getWidth() + anthill->getPosX() + 100);
    int hill_y = getRandomPoint(anthill->getPosY()-100, anthill->getHeight() + anthill->getPosY() + 100);

    return { hill_x, hill_y };
}

void Ant::updateMovement(Field* field, Anthill* anthil, string new_work_status){
    if (getPosX() != endPoint.first || getPosY() != endPoint.second) {
        if (getPosX() < endPoint.first) setPosX(getPosX() + 1);
        else if (getPosX() > endPoint.first) setPosX(getPosX() - 1);

        if (getPosY() < endPoint.second) setPosY(getPosY() + 1);
        else if (getPosY() > endPoint.second) setPosY(getPosY() - 1);

        shape.setPosition(sf::Vector2f(getPosX(), getPosY()));
        //printPosition();
    }
    else {
        this->setWorkStatus(new_work_status);
    }
}

void Ant::findHome(Anthill* anthill){
    endPoint = randomAntHill(anthill);
}
/*
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
*/

void Ant::findFood(Field* field, Game* game){
    pair<int, pair<int, int>> point = findNearestPointCollecter(this->getPosX(), this->getPosY(), field->foodCoordinates, field->detectedFood, game);
        //findNearestPoint(getPosX(), getPosY(), field->foodCoordinates);
    this->setEndPoint({point.second.first, point.second.second});
    field->field[point.second.second][point.second.first] = "";

    vector<Food*> newFoodCoordinates = field->foodCoordinates;
    for (int i = 0; i < newFoodCoordinates.size(); i++) {
        int x = newFoodCoordinates[i]->getX();
        int y = newFoodCoordinates[i]->getY();
        if (field->field[y][x] != "food") {
            field->foodCoordinates.erase(field->foodCoordinates.begin()+i);

        }
    }

    //endPoint.first = point.second.first;
    //endPoint.second = point.second.second;
}

void Ant::findMaterial(Field* field, Game *game){
    pair<int, pair<int, int>> point = findNearestPointBuilder(this->getPosX(), this->getPosY(), field->materialsCoordinates, field->detectedMaterials, game);
    this->setEndPoint({ point.second.first, point.second.second });
    field->field[point.second.second][point.second.first] = "";

    //vector<Materials*> newMaterialsCoordinates = field->materialsCoordinates;
    for (int i = 0; i < field->materialsCoordinates.size(); i++) {
        int x = field->materialsCoordinates[i]->getX();
        int y = field->materialsCoordinates[i]->getY();
        if (field->field[y][x] != "materials") {
            //cout << "AAAAAAAAA"<<field->materialsCoordinates.size() << "\n";
            field->materialsCoordinates.erase(field->materialsCoordinates.begin() + i);
            break;
        }
    }
}


void Ant::findDeadAnts(Anthill* anthill){



    int xdead = 0;
    int ydead = 0;
    for (int i = 0; i < anthill->getDeadAntsList().size(); ++i) {
        anthill->detectedDead.push_back(new Dead(anthill->getDeadAntsList()[i]->getPosX(), anthill->getDeadAntsList()[i]->getPosY(),0));
        xdead = anthill->getDeadAntsList()[i]->getPosX();
        ydead = anthill->getDeadAntsList()[i]->getPosY();
        anthill->getDeadAntsList().erase(anthill->getDeadAntsList().begin() + i);
        break;
    }



    endPoint.first = xdead;
    endPoint.second = ydead;
}

void Ant::randomMoving(Field* filed){
    int randMove = getRandomPoint(-1, 1);
    setPosX(getPosX() + randMove);

    randMove = getRandomPoint(-1, 1);
    setPosY(getPosY() + randMove);

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

void Ant::setPosX(int x)
{
    this->x = x;
    this->getShape().setPosition(x, this->y);

}

void Ant::setPosY(int y)
{
    this->y = y;
    this->getShape().setPosition(this->x, y);
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

/*
int h(pair<int, int> p1, pair<int, int> p2) {
    int res = sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
    return res;
}
*/
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
