#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

using namespace std;

class Field {
public:
    //getters
    int getHeight() { return height; }
    int getWidth() { return width; }

    void updateFoodCoordinatesList();
    void updateMaterialsCoordinatesList();

    vector<vector<string>> field;
    Field(int width, int height);
    void ResourceSpawn();
    vector<pair<int, int>> foodCoordinates; // coordinates of cells with food
    vector<pair<int, int>> materialsCoordinates; // coordinates of cells with materials

    //Enemies
    void createEnemy();
    void deleteEnemy(Enemy* killed);
    //for testing
    vector<Enemy*> enemies;

    vector<pair<int, pair<int, int>>> foodCoordinates; // coordinates of cells with food : weight and {x, y} - coords
    vector<pair<int, pair<int, int>>> materialsCoordinates; // coordinates of cells with materials
private:
    // resource spawn
    void foodSpawn(int k);
    void materialsSpawn(int k);

    vector<vector<string>> field;
    int height;
    int width;

    //enemies
    //vector<Enemy*> enemies;

};

#endif //FIELD_H
