#include "Controller.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <thread>
#include <chrono>

Controller::Controller(Player* p, View* v, Map* m)
    : player(p), view(v), map(m), direction('w'), running(true), objects(v->getObjects()){}

char Controller::getInputIfAny() {
    struct termios oldt, newt;
    char c = 0;
    int bytesWaiting;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ioctl(STDIN_FILENO, FIONREAD, &bytesWaiting);
    if(bytesWaiting > 0){
        read(STDIN_FILENO, &c, 1);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void Controller::run(){
    view->render();

    while(running){
        char input = getInputIfAny();
        if(input == 'q'){
            std::cout << "! Game Over\n";
            running = false;
            continue;
        }else if(input == 'w' || input == 'a' || input == 's' || input == 'd'){
            direction = input;
        }

        int prevX = player->getX();
        int prevY = player->getY();
            
        switch(direction){
            case 'w': player->setPosition(prevX, prevY - 1); break;
            case 's': player->setPosition(prevX, prevY + 1); break;
            case 'a': player->setPosition(prevX - 1, prevY); break;
            case 'd': player->setPosition(prevX + 1, prevY); break;
        }

        map->checkCollision(player, prevX, prevY);

        for (auto obj : view->getObjects()) {
            Enemy* enemy = dynamic_cast<Enemy*>(obj);
            if (enemy) {
                enemy->moveTowardPlayer(player->getX(), player->getY(), map);
                map->checkCollision(enemy, -1, -1); // we ignore prevX, prevY for enemy
            }
        }

        view->render();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (!map->hasRemainingTreasure()) {
            std::cout << "You win!\n";
            break;
        }
    }
}