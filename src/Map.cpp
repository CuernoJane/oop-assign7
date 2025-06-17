#include "Map.h"
#include "Treasure.h"
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>

using namespace std;

Map::Map(vector<GameObject*>& objs, int w, int h) : objects(objs), width(w), height(h){}

bool Map::hasRemainingTreasure() const {
    for (auto obj : objects) {
        if (obj == nullptr) continue;
        if (obj->getType() == "Treasure") {
            return true; // 還有剩餘的 Treasure
        }
    }
    return false; // 沒有剩餘的 Treasure
}

bool Map::isBlocked(int x, int y) const{
    // 邊界檢查
    if (x < 0 || x >= width || y < 0 || y >= height) return true;

    for (auto obj : objects) {
        if (obj == nullptr) continue;
        if (obj->getX() == x && obj->getY() == y) {
            // 若是 Wall 或 Treasure 視為不可穿越
            std::string type = obj->getType();
            if (type == "Wall") {
                return true;
            }
        }
    }
    return false; // 其他情況都可以走
}

void Map::checkCollision(GameObject* player, int prevX, int prevY) {
    int x = player->getX(), y = player->getY();

    if (x < 0 || x >= width || y < 0 || y >= height) {
        player->setPosition(prevX, prevY);
        return;
    }

    for (auto it = objects.begin(); it != objects.end(); ++it) {
        GameObject* obj = *it;
        if (!obj || obj == player) continue;

        if (obj->getX() == x && obj->getY() == y) {
            if (obj->canEat() && player->canBeEaten()) {
                std::cout << "You were caught. Game Over!\n";
                exit(0);
            } else if (player->getType() == "Player" && player->canEat() && obj->canBeEaten()) {
                *it = nullptr;
                return;
            } else if (!obj->canBeEaten() && !obj->canMove()) {
                player->setPosition(prevX, prevY);
                return;
            }
        }
    }
}

