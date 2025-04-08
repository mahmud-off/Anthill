#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

using namespace std;

class Field {
public:
    Field(int height, int width);
    void ResourceSpawn();
private:
    // resource spawn
    void foodSpawn(int k);
    void materialsSpawn(int k);

    vector<vector<string>> field;
    int height;
    int width;
};

#endif //FIELD_H
