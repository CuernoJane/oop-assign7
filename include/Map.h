#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;

class Map{
private:
    vector<GameObject*>& objects;
    int width;  // 假設地圖寬度
    int height; // 假設地圖高度
public:
    Map(vector<GameObject*>& objs, int w, int h);
    bool hasRemainingTreasure() const;
    bool isBlocked(int x, int y) const;
    void checkCollision(GameObject* player, int prevX, int prevY);
};

