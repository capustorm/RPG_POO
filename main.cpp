#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include <vector>
<<<<<<< HEAD

int main() {
    Player *player = new Player("Victor", 40, 10, 4, 3);
=======


int main() {
    Player *player = new Player("Victor", 5, 10, 4, 3);
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
    Enemy *enemy = new Enemy("Goblin", 15, 6, 2, 5, 10);
    Enemy *enemy2 = new Enemy("Orc", 15, 6, 2, 5, 10);

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete combat;
    return 0;
}