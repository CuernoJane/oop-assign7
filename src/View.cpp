#include "View.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

View::View(vector<GameObject*>& objs, int w, int h) : objects(objs), width(w), height(h) {
}

View::~View() {
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
}

vector<GameObject*>& View::getObjects(){
    return objects;
}

void View::addObject(GameObject* obj){
    objects.push_back(obj);
}

void View::render() const {
    // 清空畫面
    std::cout << "\033[2J\033[H" << std::flush;

    // 初始化網格（寬 x 高）
    vector<vector<GameObject*>> grid(height, vector<GameObject*>(width, nullptr));

    // 把物件放入對應的 grid 位置
    for (auto obj : objects) {
        if (obj == nullptr || obj->getType() == "Player" || obj->getType() == "Enemy") continue; // 避免存取已刪除寶藏的位置
        int x = obj->getX();
        int y = obj->getY();
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = obj;
        }
    }

    for (auto obj : objects) {
        if (obj == nullptr || obj->getType() != "Enemy") continue; // 避免存取已刪除寶藏的位置
        int x = obj->getX();
        int y = obj->getY();
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = obj;
        }
    }

    for (auto obj : objects) {
        if (obj == nullptr || obj->getType() != "Player") continue; // 避免存取已刪除寶藏的位置
        int x = obj->getX();
        int y = obj->getY();
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = obj;
        }
    }

    for (int i = 0; i < width + 2; i++) std::cout << '-';
    std::cout << '\n';

    for (int y = 0; y < height; y++) {
        std::cout << '|';
        for (int x = 0; x < width; x++) {
            GameObject* obj = grid[y][x];
            if (obj == nullptr) {
                std::cout << ' ';
            } else {
                string type = obj->getType();
                char symbol = obj->getSymbol();

                if (type == "Treasure") {
                    std::cout << "\033[1;33m" << symbol << "\033[0m"; // 黃色
                } else if (type == "Player") {
                    std::cout << "\033[1;36m" << symbol << "\033[0m"; // 青色
                } else if (type == "Enemy") {
                    std::cout << "\033[1;31m" << symbol << "\033[0m"; // 紅色
                } else {
                    std::cout << symbol; // 其他（牆）用預設白色
                }
            }
        }
        std::cout << "|\n";
    }

    for (int i = 0; i < width + 2; i++) std::cout << '-';
    std::cout << '\n';
}


void View::fillWithTreasure() {
    vector<std::pair<int, int>> treasurePos = {
        {0,6},{0,7},{0,8},{1,2},{1,3},{1,4},{2,4},{2,5},{2,6},
        {3,2},{3,4},{3,6},{4,7},{4,8},{4,9},
        {5,1},{5,8},{6,1},{6,8},{7,1},
        {8,6},{9,2},{9,6},{10,5},{10,9},{11,0},
        {12,1},{13,1},{14,9},
        {15,0},{15,1},{16,2},{17,3},{17,4},{18,3},
        {19,0},{20,0},{20,1},{21,0},{21,8},{21,9},{22,1},{22,8},
        {24,6},{25,3},{25,4},{26,2},{26,3},{27,1},
        {28,0},{29,1},{30,1},{31,1},{32,0},{33,0},{33,1},
        {34,0},{35,6},{35,8},{36,4},{36,7},{37,1},
        {38,0},{39,1},{40,1},{41,1},{42,0},{43,0},{43,1},
        {44,0},{45,6},{45,8},{46,4},{46,7},{47,1},
        {48,0},{49,1},{50,1},{51,1},{52,0},{53,0},
        {54,0},{55,6},{55,8},{56,4},{56,7},{57,1},
        {58,2},{58,3},{59,4}
    };

    for(auto [x,y] : treasurePos){
        addObject(new Treasure(x, y));
    }
}

void View::buildWall() {
    int baseY = 2;
    int xStart1A = 4;
    int xStart1B = 11;
    int xStart3  = 19;
    int xStartO1 = 28;
    int xStartO2 = 38;
    int xStartP  = 48;

    for (int y = 0; y < 6; ++y) {
        objects.push_back(new Wall(xStart1A + 1, baseY + y));
        objects.push_back(new Wall(xStart1A + 2, baseY + y));
        objects.push_back(new Wall(xStart1A + 3, baseY + y));
    }
    for (int y = 0; y < 6; ++y) {
        objects.push_back(new Wall(xStart1B + 1, baseY + y));
        objects.push_back(new Wall(xStart1B + 2, baseY + y));
        objects.push_back(new Wall(xStart1B + 3, baseY + y));
    }
    for (int x = 0; x <= 4; ++x) {
        objects.push_back(new Wall(xStart3 + x, baseY));
        objects.push_back(new Wall(xStart3 + x, baseY + 2));
        objects.push_back(new Wall(xStart3 + x, baseY + 3));
        objects.push_back(new Wall(xStart3 + x, baseY + 5));
    }
    objects.push_back(new Wall(xStart3 + 3, baseY + 1));
    objects.push_back(new Wall(xStart3 + 4, baseY + 1));
    objects.push_back(new Wall(xStart3 + 3, baseY + 4));
    objects.push_back(new Wall(xStart3 + 4, baseY + 4));

    for (int y = 0; y < 6; ++y) {
        objects.push_back(new Wall(xStartO1, baseY + y));
        objects.push_back(new Wall(xStartO1 + 1, baseY + y));
        objects.push_back(new Wall(xStartO1 + 4, baseY + y));
        objects.push_back(new Wall(xStartO1 + 5, baseY + y));
    }
    for (int x = 1; x <= 3; ++x) {
        objects.push_back(new Wall(xStartO1 + x, baseY));
        objects.push_back(new Wall(xStartO1 + x, baseY + 5));
    }

    for (int y = 0; y < 6; ++y) {
        objects.push_back(new Wall(xStartO2, baseY + y));
        objects.push_back(new Wall(xStartO2 + 1, baseY + y));
        objects.push_back(new Wall(xStartO2 + 4, baseY + y));
        objects.push_back(new Wall(xStartO2 + 5, baseY + y));
    }
    for (int x = 1; x <= 3; ++x) {
        objects.push_back(new Wall(xStartO2 + x, baseY));
        objects.push_back(new Wall(xStartO2 + x, baseY + 5));
    }

    for (int y = 0; y < 6; ++y){
        objects.push_back(new Wall(xStartP, baseY + y));
        objects.push_back(new Wall(xStartP + 1, baseY + y));
    }
    for(int x = 2; x <= 5; ++x){
        objects.push_back(new Wall(xStartP + x, baseY));
        objects.push_back(new Wall(xStartP + x, baseY + 2));
    }
    objects.push_back(new Wall(xStartP + 4, baseY + 1));
    objects.push_back(new Wall(xStartP + 5, baseY + 1));
}
