#include "View.h"
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include "Controller.h"
#include "Map.h"

int main() {
    int width = 60, height = 10;
    std::vector<GameObject*> allObjects;

    Player* player = new Player(0, 0);
    allObjects.push_back(player);

    Enemy* enemy = new Enemy(55, 2);
    allObjects.push_back(enemy);

    View view(allObjects, width, height);
    view.buildWall();
    view.fillWithTreasure();

    Map map(allObjects, width, height);
    Controller controller(player, &view, &map);

    controller.run();

    // 清除所有物件（手動 delete）
    // for (GameObject* obj : allObjects) {
    //     delete obj;
    // }
    return 0;
}
