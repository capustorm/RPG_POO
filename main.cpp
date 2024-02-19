#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    auto *player = new Player("True Warrior", 100, 10, 4, 10);
    auto *enemy = new Enemy("Final Boss", 110, 10, 2, 5, 10);

    cout << "=====================" << endl;

    bool combat = true;
    int i = 1;
    while (combat == true) {
        cout << "\nRound " << i << endl;
        player->doAttack(enemy);
        enemy->doAttack(player);
        cout << player->toString() << endl;
        cout << enemy->toString() << endl;

        if (player->getHealth() <= 0)
        {
            cout << "\nYou loose." << endl;
            combat = false;
        } else if (enemy->getHealth() <= 0) {
            cout << "\nYou won." << endl;
            combat = false;
        }

        i++;
    }
    delete player;
    delete enemy;
    return 0;
}
