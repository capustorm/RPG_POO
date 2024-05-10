#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include <vector>

int main() {
    // Player *player = new Player("Michael", 100, 20, 5, 10);
    // Player *player2 = new Player("Arturo", 110, 12, 5, 9);
    Player *player = new Player("Default", 100, 15, 8, 10);

    player->unserialize("playerInfo.txt");

    Enemy *enemy = new Enemy("Goblin", 10, 5, 4, 20, 100);
    Enemy *enemy2 = new Enemy("Orc", 10, 10, 4, 5, 100);

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;
    return 0;
}

