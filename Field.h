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

    vector<vector<string>> field;
    Field(int height, int width);
    void ResourceSpawn();
    vector<pair<int, pair<int, int>>> foodCoordinates; // coordinates of cells with food : weight and {x, y} - coords
    vector<pair<int, int>> materialsCoordinates; // coordinates of cells with materials
private:
    // resource spawn
    void foodSpawn(int k);
    void materialsSpawn(int k);
    int height;
    int width;
};

#endif //FIELD_H
