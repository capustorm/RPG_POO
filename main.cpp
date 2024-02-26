#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    auto *player = new Player("True Warrior", 100, 10, 4, 10);
    auto *enemy = new Enemy("Final Boss", 110, 10, 2, 5, 10);

    cout << "=====================" << endl;
    cout << "Player:" << endl << player->toString() << endl;
    cout << "=====================" << endl;
    cout << "Enemy:" << endl << enemy->toString() << endl;
    cout << "=====================" << endl;

    bool combat = true;
    int i = 1;
    while (combat) {
        int previousPlayerHealth = player->getHealth();
        int previousEnemyHealth = enemy->getHealth();

        cout << "\nRound " << i << endl;
        player->doAttack(enemy);
        enemy->doAttack(player);

        if (player->getHealth() <= 0)
        {
            player->setHealth(player, 0);
        } else if (enemy->getHealth() <= 0) {
            enemy->setHealth(enemy,0);
        }

        int enemyDamage = previousPlayerHealth - player->getHealth();
        int playerDamage = previousEnemyHealth - enemy->getHealth();

        cout << player->getName() << " has done " << playerDamage << " damage to " << enemy->getName() << endl;
        cout << enemy->getName() << " has done " << enemyDamage << " damage to " << player->getName() << endl;

        cout << player->getName() << "'s life remaining: " << player->getHealth() << endl;
        cout << enemy->getName() << "'s life remaining: " << enemy->getHealth() << endl;

        if (player->getHealth() <= 0)
        {
            cout << "\nYou lose." << endl;
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
